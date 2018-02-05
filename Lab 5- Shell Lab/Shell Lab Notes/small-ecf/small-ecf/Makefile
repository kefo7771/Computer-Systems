CC = gcc
CSAPP_INC = .
CSAPP_SRC = .
CFLAGS = -Wall -O2 -g

PROGS	= children-simple-wait \
	children-do-not-wait \
	children-sigchild-no-wait \
	children-sigchild-correct-wait \
	 procmask-before procmask-partial \
	procmask-flaw-show procmask-flaw-fix

all:	csapp.o $(PROGS)

$(PROGS): csapp.o

clean:
	rm -f $(PROGS) *.o *~
	rm -rf *.dSYM

