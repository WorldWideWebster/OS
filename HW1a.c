#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv) 
{
	 int res;
	 /* duplicate the current process */
	 while(1)
	 {
		res = fork();
		/* *******
		* If fork was successful there are now two processes at this point
		**** */
		/* check whether fork is successful */
		if (res < 0) 
		{
			perror("fork");
			exit(-1);
			}
		/* Check whether this is the father or the child */
		/* the child got 0 from fork. */
		if (res == 0) 
		{
			printf("Child Running\n");
			// Child Exits
			exit(0);
		}
		else 
		{ /* parent process */
			int child_pid = res;
			waitpid(child_pid, NULL, 0);
			/* parent will wait for the child to complete */
			printf ("Child Complete\n");
		}
	}
	exit(0);
 }
