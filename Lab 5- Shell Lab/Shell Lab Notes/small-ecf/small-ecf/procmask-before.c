#include "csapp.h"

//
// Demonstration of race condition
//
// First version
//

void initjobs()
{
  fprintf(stderr,"initjobs");
}

void addjob(int pid)
{
  fprintf(stderr,"addjob(%d)\n", pid);
}

void deletejob(int pid)
{
  fprintf(stderr,"deletejob(%d)\n", pid);
}

/* $begin procmask2 */
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
    
	/* Child process */
	if ((pid = Fork()) == 0) {
	    Execve("/bin/date", NULL, NULL);
	}

	/* Parent process */

	if ( sleepFor > 0 ) {
	  sleep( sleepFor );
	}

	addjob(pid);
    }
    exit(0);
}
/* $end procmask2 */
