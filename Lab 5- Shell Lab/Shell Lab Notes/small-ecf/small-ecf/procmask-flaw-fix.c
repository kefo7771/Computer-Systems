#include "csapp.h"

//
// Demonstration of race condition
//
// First version
//

void initjobs()
{
  fprintf(stderr,"initjobs\n");
}

void addjob(int pid)
{
  fprintf(stderr,"addjob(%d)\n", pid);
}

void deletejob(int pid)
{
  fprintf(stderr,"deletejob(%d)\n", pid);
}

/* $begin procmask1 */
void handler(int sig)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, 0)) > 0) /* Reap a zombie child */
	deletejob(pid); /* Delete the child from the job list */
    if (errno != ECHILD)
	unix_error("waitpid error");
}
    
int main(int argc, char **argv)
{
    int pid;
    int sleepFor = 0;

    if ( argc > 1 ) { 
      sleepFor = atoi(argv[1]);
    }

    Signal(SIGCHLD, handler);
    initjobs(); /* Initialize the job list */

    for (int i = 0; i < 5; i++) {

      sigset_t mask;
	Sigemptyset(&mask);
	Sigaddset(&mask, SIGCHLD); 
	Sigprocmask(SIG_BLOCK, &mask, NULL); /* Block SIGCHLD */


	/* Child process */
	if ((pid = Fork()) == 0) {
	  Sigprocmask(SIG_UNBLOCK, &mask, NULL);  /* Unblock SIGCHLD */
	    Execve("./children-sigchild-correct-wait", NULL, NULL);
	}

	if ( sleepFor > 0 ) {
	  sleep( sleepFor );
	}


	/* Parent process */
	addjob(pid);  /* Add the child to the job list */

	Sigprocmask(SIG_UNBLOCK, &mask, NULL);  /* Unblock SIGCHLD */

    }
    exit(0);
}
/* $end procmask1 */
