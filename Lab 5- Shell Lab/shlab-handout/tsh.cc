//
// tsh - A tiny shell program with job control
//
// <Ken Ford kefo7771>
//Referenced Computer Systems: A Programmer's Perspective by Randal E. Bryant and David R. O'Hallaron

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>

#include "globals.h"
#include "jobs.h"
#include "helper-routines.h"

//
// Needed global variable definitions
//

static char prompt[] = "tsh> ";
int verbose = 0;

//
// You need to implement the functions eval, builtin_cmd, do_bgfg,
// waitfg, sigchld_handler, sigstp_handler, sigint_handler
//
// The code below provides the "prototypes" for those functions
// so that earlier code can refer to them. You need to fill in the
// function bodies below.
//

void eval(char *cmdline);//responsible for evaluating and handling child and parent relationship
int builtin_cmd(char **argv); //parses command and assigns each command its task
void do_bgfg(char **argv);//assigns job to either foreground or background
void waitfg(pid_t pid);//where parent waits for child to terminate in order to solve racing problem

void sigchld_handler(int sig);//handles cases where child receives signals
void sigtstp_handler(int sig);//handles when a stop command is passed in
void sigint_handler(int sig);//handles when an interrupt command is passed in

//
// main - The shell's main routine
//
int main(int argc, char **argv)
{
  int emit_prompt = 1; // emit prompt (default)

  //
  // Redirect stderr to stdout (so that driver will get all output
  // on the pipe connected to stdout)
  //
  dup2(1, 2);

  /* Parse the command line */
  char c;
  while ((c = getopt(argc, argv, "hvp")) != EOF) {
    switch (c) {
    case 'h':             // print help message
      usage();
      break;
    case 'v':             // emit additional diagnostic info
      verbose = 1;
      break;
    case 'p':             // don't print a prompt
      emit_prompt = 0;  // handy for automatic testing
      break;
    default:
      usage();
    }
  }

  //
  // Install the signal handlers
  //

  //
  // These are the ones you will need to implement
  //
  Signal(SIGINT,  sigint_handler);   // ctrl-c
  Signal(SIGTSTP, sigtstp_handler);  // ctrl-z
  Signal(SIGCHLD, sigchld_handler);  // Terminated or stopped child

  //
  // This one provides a clean way to kill the shell
  //
  Signal(SIGQUIT, sigquit_handler);

  //
  // Initialize the job list
  //
  initjobs(jobs);

  //
  // Execute the shell's read/eval loop
  //
  for(;;) {
    //
    // Read command line
    //
    if (emit_prompt) {
      printf("%s", prompt);
      fflush(stdout);
    }

    char cmdline[MAXLINE];

    if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin)) {
      app_error("fgets error");
    }
    //
    // End of file? (did user type ctrl-d?)
    //
    if (feof(stdin)) {
      fflush(stdout);
      exit(0);
    }

    //
    // Evaluate command line
    //
    eval(cmdline);
    fflush(stdout);
    fflush(stdout);
  }

  exit(0); //control never reaches here
}

/////////////////////////////////////////////////////////////////////////////
//
// eval - Evaluate the command line that the user has just typed in
//
// If the user has requested a built-in command (quit, jobs, bg or fg)
// then execute it immediately. Otherwise, fork a child process and
// run the job in the context of the child. If the job is running in
// the foreground, wait for it to terminate and then return.  Note:
// each child process must have a unique process group ID so that our
// background children don't receive SIGINT (SIGTSTP) from the kernel
// when we type ctrl-c (ctrl-z) at the keyboard.
//
void eval(char *cmdline)
{
  /* Parse command line */
//Consulted Ch. 8.4
//
// The 'argv' vector is filled in by the parseline
// routine below. It provides the arguments needed
// for the execve() routine, which you'll need to
// use below to launch a process.
//
char *argv[MAXARGS];  // argument list for execve
char buf[MAXLINE];    // Holds modified command line

//
// The 'bg' variable is TRUE if the job should run
// in background mode or FALSE if it should run in FG
//
int bg;                      //fg or bg mode
pid_t myPid;
pid_t pid;
int state=0;
//initialize signal block
sigset_t block;

//check to see if fg or bg
strcpy(buf, cmdline);
bg = parseline(buf, argv);

//get pid of parent
myPid=getpid();

//print out pid of parent
//printf("   *-> myPid %d \n", myPid);

//check for empty line
if (argv[0] == NULL)
    return;

//check for built in function
if (builtin_cmd(argv)==0){
    //signal blocking area
    //create an empty block signal set
    sigemptyset(&block);
    //includes signal 17 (SIGCHLD) to block set
    sigaddset(&block, 17);
    //block signals in set
    sigprocmask(SIG_BLOCK, &block, NULL);

    //fork here and create child
    pid = fork();
    if (pid == 0){  //child has pid=0
        //child runs job
        //set child in separate process group
        setpgid(0,0);
        //unblock child
        sigprocmask(SIG_UNBLOCK, &block, NULL);
        //execve returns -1 on error, so check if it returns less than 0
        if (execve(argv[0], argv, environ) < 0){
            printf("%s : command not found\n",argv[0]);
            //exit if unable to find command
            exit(0);
        }
    }

    //print out the pid here
    //printf("   *-> pid %d \n", pid);

    if (!bg){
        //parent waits for child running in foreground to terminate
        //add job when fg
        addjob(jobs, pid, FG, cmdline);
        //unblock parent
        sigprocmask(SIG_UNBLOCK, &block, NULL);
        //wait for fg process to finish
        waitfg(pid);
    }
    else{
        //parent goes back to command line with child running background
        //add job when bg
        addjob(jobs, pid, BG, cmdline);
        //unblock sigchld
        sigprocmask(SIG_UNBLOCK, &block, NULL);
        int numJobs = pid2jid(pid);

        printf("[%d] (%d) %s",numJobs,pid,cmdline);
    }
  }
return;

  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// builtin_cmd - If the user has typed a built-in command then execute
// it immediately. The command name would be in argv[0] and
// is a C string. We've cast this to a C++ string type to simplify
// string comparisons; however, the do_bgfg routine will need
// to use the argv array as well to look for a job number.
//
int builtin_cmd(char **argv)
{
    string cmd(argv[0]);
    string quitStr = "quit";
    string fgStr = "fg";
    string bgStr = "bg";
    string jobsStr = "jobs";
    char* cmdCompare = &cmd[0];
    //printf("builtin_cmd cmd value: %s\n", cmdArr);
    //if command is quit, then go here
    if (cmdCompare == quitStr)
    {
        exit(0);
        return 1;
    }
    //if command is either fg or bg, go here
    if (cmdCompare == fgStr || cmdCompare == bgStr)
    {
        //printf("Builtin_cmd: Made it into bgfg\n");
        do_bgfg(argv);
        return 1;

    }
    //if command is jobs, go here
    if (cmdCompare == jobsStr)
    {
        listjobs(jobs);
        return 1;
    }

    return 0;     /* not a builtin command */
}

/////////////////////////////////////////////////////////////////////////////
//
// do_bgfg - Execute the builtin bg and fg commands
//
void do_bgfg(char **argv)
{
    struct job_t *jobp=NULL;

  /* Ignore command if no argument */
    if (argv[1] == NULL)
    {
        printf("%s command requires PID or %%jobid argument\n", argv[0]);
        return;
    }

  /* Parse the required PID or %JID arg */
    if (isdigit(argv[1][0]))
    {
        //check if pid is the same as one passed in
        pid_t pid = atoi(argv[1]);
        if (!(jobp = getjobpid(jobs, pid)))
        {
            printf("(%d): No such process\n", pid);
            return;
        }
    }
    //checks for percent sign JID command
    else if (argv[1][0] == '%') {
        int jid = atoi(&argv[1][1]);
        //check if jid is the same as one passed in
        if (!(jobp = getjobjid(jobs, jid)))
        {
            printf("%s: No such job\n", argv[1]);
            return;
        }
    }
    //unable to find either jid or pid
    else {
        printf("%s: argument must be a PID or %%jobid\n", argv[0]);
        return;
    }
    //input will be either bg or fg
    string cmd(argv[0]);
    //if background
    if (cmd == "bg")
    {
        //change jobp's state to background in order to move it to background
        jobp->state = BG;
        //after moving the processes around, we send a continue signal to continue the processes
        kill(-jobp->pid,SIGCONT);
        printf("[%d] (%d) %s", jobp->jid,jobp->pid,jobp->cmdline);
        //printf("in to_bgfg, process sent to background");

    }
    //if not in background, move to foreground
    else
    {
        //change jobp's state to foreground in order to move it to the foreground
        jobp->state = FG;
        //after moving the processes around, we send a continue signal to continue the processes
        kill(-jobp->pid,SIGCONT);
        //since moving to foreground, we need to wait
        waitfg(jobp->pid);
        //printf("[%d] (%d) %s\n", jobp->jid,jobp->pid,jobp->cmdline);
        //printf("in to_bgfg, process sent to foreground");
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// waitfg - Block until process pid is no longer the foreground process
//
void waitfg(pid_t pid)
{
    //consulted CH. 8.4, 8.5
    int status;//status of how child terminated
    int fgJobPid=fgpid(jobs);//job pid of current foreground job
    int jobNum=pid2jid(fgJobPid);//job id of current pid in fg

    //printf("waitfg: pid=%d, START waiting, status=%d \n",pid,status);
    //fflush(stdout);

    //printf("   *****\n");
    //listjobs(jobs);
    //printf("   *****\n");
    //fflush(stdout);

    if (waitpid(pid, &status, WUNTRACED) < 0){
        unix_error("waitfg: waitpid error");
    }//if

    //if process stopped, do NOT delete process from jobs list
    if (WIFSTOPPED(status)){
        //set the job to stopped
        getjobpid(jobs,fgJobPid)->state=ST;
        //printf("waitfg: process (pid=%d) has stopped \n",pid);
        return;
    }//if

    //if process exited, then delete process from jobs list
    if (WIFEXITED(status)){
        deletejob(jobs, pid);
        return;
    }//if

    //if process was signaled, then delete process from jobs list
    if (WIFSIGNALED(status)){
        printf("Job [%d] (%d) terminated by signal %d\n",jobNum,fgJobPid,WTERMSIG(status));
        deletejob(jobs, pid);
        return;
    }//if

    //printf("waitfg: pid=%d, FINISHED waiting, status=%d \n",pid,status);
    //fflush(stdout);


    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// Signal handlers
//


/////////////////////////////////////////////////////////////////////////////
//
// sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
//     a child job terminates (becomes a zombie), or stops because it
//     received a SIGSTOP or SIGTSTP signal. The handler reaps all
//     available zombie children, but doesn't wait for any other
//     currently running children to terminate.
//
void sigchld_handler(int sig)
{
    //Consulted Ch. 8.4, Figure 8.18 and 8.5
    //printf("sigchld_handler was reached\n");
    int status;
    pid_t pid;
    //parent reaps children here
    while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
    {
        //when child is terminated from uncaught signal
        if (WIFSIGNALED(status))
        {
            //printf("Job [%d] (%d) terminated by signal %d\n", pid2jid(pid), pid, WTERMSIG(status));
            deletejob(jobs,pid);
        }
        //when child is terminated via a call to exit or return
        if (WIFEXITED(status))
        {
            //delete job from list now that child is terminated
            deletejob(jobs, pid);
        }
        //when child is currently stopped
        if (WIFSTOPPED(status))
        {
            getjobpid(jobs, pid)->state = ST;
            //printf("[%d] Stopped %s\n", pid2jid(pid), jobs->cmdline);
        }
    }
    //normal termination is no children left
    if (pid < 0 && errno != ECHILD) {
	printf("waitpid error: %s\n", strerror(errno));
    }

  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigint_handler - The kernel sends a SIGINT to the shell whenever the
//    user types ctrl-c at the keyboard.  Catch it and send it along
//    to the foreground job.
//
void sigint_handler(int sig)
{
    //Consulted Ch. 8.4, Figure 8.18 and 8.5
    //printf("sigint_handler received interrupt signal: %d\n", sig);
    int pid;
    pid = fgpid(jobs);
    //printf("%d: PID of foreground job\n", pid);
    int jobNum = pid2jid(pid);
    if (pid != 0){
        kill(-pid,SIGINT);
        //printf("Job [%d] (%d) terminated by signal %d\n",jobNum,pid,sig);
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
//     the user types ctrl-z at the keyboard. Catch it and suspend the
//     foreground job by sending it a SIGTSTP.
//
void sigtstp_handler(int sig)
{
    //Consulted Ch. 8.4, Figure 8.18 and 8.5
    int pid;
    pid = fgpid(jobs);
    //printf("%d: PID of foreground job\n", pid);
    int jobNum = pid2jid(pid);
    if (pid != 0){
        printf("Job [%d] (%d) stopped by signal %d\n",jobNum,pid,sig);
        fflush(stdout);
        kill(-pid,SIGTSTP);
    }
    return;
}

/*********************
 * End signal handlers
 *********************/




