#include "csapp.h"

//
// Wait for a child and print messages of even ordering
//

int died = 0;

int main(int argc, char **argv)
{
    int pid;
    int kids = 1;
    int birthed = 0;

    if ( argc > 1 ) { 
      kids = atoi(argv[1]);
    }

    while (birthed++ < kids ) {
      fprintf(stderr, "%d: fork child\n", getpid());
      if ((pid = Fork()) == 0) {
	fprintf(stderr, "%d: I am the child\n", getpid());
	exit(0);
      }
      fprintf(stderr, "%d: Child is %d\n", getpid(), pid);
    }

    while (died < kids) {
      pid = waitpid(-1, NULL, 0);
      fprintf(stderr,"%d: reap child %d\n", getpid(), pid); 
      died++;
    }
}

