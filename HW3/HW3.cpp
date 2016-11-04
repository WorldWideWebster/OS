/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 3
 * Due 10/13
 * 
 * 
 * ***************************************************
 * HW2.cpp
 * creates n subprocesses using fork and displays "child running"
 * and the exits. also runs execv to open b.c in each child process
 * ***************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>
#include<time.h>
#include<queue>
#include <stdlib.h>


#define MAX_SIZE 4096


int mms = malloc(MAX_SIZE);


// Allocate large block of memory
// realloc-segment block into sections of power 2
// create task requiring memory
// find fit of task

// global variable, all threads can acess
void *memoryMalloc(void);
void *thread_Insert(void *arg);	// function for sending
void *thread_Remove(void *arg);	// function for receiving

sem_t bin_sem;		// semaphore
pthread_mutex_t mutx;	// mutex



int main(int argc, char **argv)
{
  //for(int m = 0; m < argc; m++)
     // {
    /* initialize random seed: */
    srand (time(NULL));

    pthread_t* threads;
    void *thread_result;
    int state1, state2;
    state1 = pthread_mutex_init(&mutx, NULL);
    state2 = sem_init(&bin_sem, 0 ,0);
    //mutex initialization
    //semaphore initialization, first value = 0

    if(state1||state2!=0)
      puts("Error mutex & semaphore initialization!!!");
    

    // Create provider threads
    for(j = 0; j < argv[1] - 1; j++)
    {    
      pthread_create(&threads[j], NULL, thread_User, (void*)j);
      
    }
    sleep(1);
    
    // Create buyer threads
 
    pthread_create(&threads[argv[1]], NULL, thread_MMS, (void*)i);

    // Waiting buyer threads to terminate
    for(int k = 0; k < [argv[1] - 1]; k++)
    { 
      //printf("Buyers executed: %d\n", k + 1);
      pthread_join(threads[k], &thread_result);
    }
    // Waiting buyer threads to terminate
	pthread_join(thread[argv[1]], &thread_result);

    sem_destroy(&bin_sem);	// destroy semaphore
    pthread_mutex_destroy(&mutx);	// destroy mutex
    printf("Final Index: %d\n", index_counter);
    
     // }
    return 0;
  }


  // Provider inserts item into queue
  void *thread_Insert(void *arg)
  {
    int theGoods = rand() % 10 + 1;
    printf("Creating Provider Thread: %d with item %d\n", (int*)arg, theGoods);
    
    //for(i = 0;i < PROVIDER_NUM; i++)
    for(;counter < BUYER_NUM -1;)
    {
      pthread_mutex_lock(&mutx);
      
      if(theQueue.empty() && !index_counter)
      //if(!theItem)
      {
	sleep(.5);
	index_counter++;   
	printf("index added - index: %d - counter: %d\n", index_counter, counter);
	theQueue.push(theGoods);
	//theItem = theGoods;
	printf("Provider %d: INSERTED item %d to QUEUE\n", (int*)arg, theGoods);
	sem_post(&bin_sem);	// semaphore to increase
      }
      else
      {
	sleep(.5);
      }
      pthread_mutex_unlock(&mutx);
    }
  }

  // Thread decreases items
  void *thread_Remove(void *arg)
  {
    bool isDone = 0;
    
    //printf("Creating Buyer Thread: %d\n", (int*)arg);

    for(;isDone < 1;)
    {
      if(theQueue.empty())
	sleep(.5);
      else
      {	  
	sem_wait(&bin_sem);	//decrease index_counter
	pthread_mutex_lock(&mutx);
	sleep(.5);
	counter++;
	printf("Buyer %d: REMOVED item %d from QUEUE\n", (int*)arg, theQueue.front());
	printf("threads executed: %d \n", counter);
	theQueue.pop();
	//theItem = 0;
	printf("index subbed - index: %d - counter: %d\n", index_counter, counter);
	index_counter--;
	
	pthread_mutex_unlock(&mutx);
	isDone = 1;
      }
  }	
}