/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 1
 * Due 9/23
 * 
 * 
 * ***************************************************
 * hw1_2.c
 * takes an integer input n and outputs 2*n processes
 * displaying the phrase "I am process i and my process id
 * is PID"
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
		 for(i = 0; i < 2 * strtol(argv[j], NULL, 10); i++)
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
				// Part A
				printf("I am process %d and my process ID is %d\n", i + 1, getpid());
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
