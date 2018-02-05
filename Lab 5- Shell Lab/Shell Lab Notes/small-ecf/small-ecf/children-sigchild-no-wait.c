#include "csapp.h"

//
// Wait for a child and print messages of even ordering
//

void handler(int sig)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, 0)) > 0) {
      fprintf(stderr,"%d: reap child %d\n", getpid(), pid); 
    }
}
    
int main(int argc, char **argv)
{
    int pid;
    int kids = 1;
    int birthed = 0;
    int shouldPause = 0;

    if ( argc > 1 ) { 
      kids = atoi(argv[1]);
      if (argc > 2) {
	shouldPause = atoi(argv[2]);
      }
    }

    Signal(SIGCHLD, handler);

    while (birthed++ < kids ) {
      fprintf(stderr, "%d: fork child\n", getpid());
      if ((pid = Fork()) == 0) {
	fprintf(stderr, "%d: I am the child\n", getpid());
	exit(0);
      }
      fprintf(stderr, "%d: Child is %d\n", getpid(), pid);
    }

    //
    // The parent does not explicitly wait for
    // the children to be reaped. A pause()
    // waits for a signal to occur. You could
    // also do a e.g. sleep(1) here..
    //

    if ( shouldPause ) {
      pause();
    }
}

