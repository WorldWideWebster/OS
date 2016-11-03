/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 1
 * Due 9/23
 * 
 * 
 * ***************************************************
 * prog.c
 * creates n subprocesses using fork and displays "child running"
 * and the exits. also runs execv to open b.c in each child process
 * ***************************************************/
 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  // for strtol

int main(int argc, char **argv) 
{
		// Allow for arg stuff
	int j;
	for(j = 0; j < argc; j++)
	{
		 int res;
		 int i = 0;
		 /* duplicate the current process */
		 for(i = 0; i < strtol(argv[j], NULL, 10); i++)
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
				char *args[] = {"", NULL};
				printf("Child Running\n");
				res = execv("b", args);
				// Child Exits
				exit(0);
			}
			else 
			{ /* parent process */
				int child_pid = res;
				waitpid(child_pid, NULL, 0);
				/* parent will wait for the child to complete */
			}
		}
	}
	exit(0);
 }
