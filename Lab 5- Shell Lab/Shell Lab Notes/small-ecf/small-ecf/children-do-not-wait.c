#include "csapp.h"

//
// Create children don't wait for them
//

    
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
}

