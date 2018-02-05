#include "csapp.h"

//
// Wait for a child and print messages of event ordering
//
// This version uses a global variable (died) to coordinate
// the reaping of child processes.
//

int died = 0;

void handler(int sig)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, 0)) > 0) {
      fprintf(stderr,"%d: reap child %d\n", getpid(), pid); 
      died++;
    }
}
    
int main(int argc, char **argv)
{
    int pid;
    int kids = 1;
    int birthed = 0;

    if ( argc > 1 ) { 
      kids = atoi(argv[1]);
    }

    Signal(SIGCHLD, handler);

    while (birthed < kids ) {
      fprintf(stderr, "%d: fork child\n", getpid());
      if ((pid = Fork()) == 0) {
	fprintf(stderr, "%d: I am the child\n", getpid());
	exit(0);
      }
      fprintf(stderr, "%d: Child is %d\n", getpid(), pid);
        birthed++;
    }

    fprintf(stderr, "%d: parent sleeps: %d birthed\n", getpid(), birthed);
    while (died < kids) {
        pause();
        fprintf(stderr, "%d: parent reaps: %d died\n", getpid(), died);
    }
}

