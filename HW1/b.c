/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 1
 * Due 9/23
 * 
 * 
 * ***************************************************
 * b.c
 * Program to be run by part one of HW 1, executes system
 * command 'ls'
 * ***************************************************/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) 
{
	system("ls");
	

	return(0);
}
