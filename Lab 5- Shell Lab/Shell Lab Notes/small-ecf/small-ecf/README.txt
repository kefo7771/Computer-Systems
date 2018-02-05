Recitation example order:

A) =============================================================

Use "children-do-not-wait" to go through the basic mechanism of
forking a child. The parent does not wait.

Use "children-simple-wait" to go through basic structure of
explicitly waiting for child. At this point the wait() is
logically in the flow of the program.

Use "children-sigchild-no-wait" to see the recommended structure
in a shell - there is a SIGCHLD handler and the wait occurs
in that one location. However, in this example, the parent
doesn't actually explicitly wait for the kid, and thus
SIGCHLD handler may not be called. If you add the "pause"
argument, the parent will pause for (any) signal to be delivered.
This happens to then let the children execute, which causes
handler to run.

Use "children-sigchild-correct-wait" to show the "proper"
interface. Global variable keeps track of the number of
children. Parent waits until that global variable is
the desired value. All it does while waiting is pause(),
although it could be doing some other work. Each child
is reaped in signal handler.

B) =============================================================

Run "procmask-before" -- children will be spawned and the parent adds
them to the job list before they run. Parent actually finishes before
any child is executed and there are no "deletejob" messages, because
the parent has exited before children run.

Now, run "procmask-before 1" -- this causes parent to sleep
between fork() and addjob(), and child gets to run. Running
child will then exit, causing signal handler to run. This
caused "deletejob" message to appear. But, the deletejob()
occurs before addjob() was done.
*** Note that the sleep() system call is interrupted and returns early

Run "procmask-partial". This solution blocks SIGCHLD and those
signals are not delivered to parent until it is unblocked.
*** Note that the sleep() system call is NOT interrupted

The "procmask-partial" solution is partial in that the CHILD
is also blocking SIGCHLD because signals are inherited through
fork() and kept through an exec(). 

Program "procmask-show-flaw" shows the flaw by using the
"children-sigchild-correct-wait" program.

Run "procmask-show-flaw 1" -- this will cause children
program to be run and parent does a sleep() after each one.
Even though parent is sleeping, the grandchildren
are never reaped because the child has SIGCHLD blocked.

Run "procmask-fix-flaw 1" -- this has been modified
to have the child UNBLOCK the signals. Thus, the
"children-sigchld-correct-wait" program will now
receive the SIGCHLD events.


