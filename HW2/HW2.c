/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 2
 * Due 10/13
 * 
 * 
 * ***************************************************
 * prog.c
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

#define BUYER_NUM 260
#define PROVIDER_NUM 4
#define BUFFER_SIZE 25
typedef int buffer_item;

buffer_item buffer[BUFFER_SIZE];
int index_counter = 0;

// global variable, all threads can acess

void *thread_Insert(void *arg);	// function for sending
void *thread_Remove(void *arg);	// function for receiving

sem_t bin_sem;		// semaphore
pthread_mutex_t mutx;	// mutex

queue<int> theQueue;	// Queue

int buyer[BUYER_NUM];
int provider[PROVIDER_NUM];

int main(int argc, char **argv)
{
  /* initialize random seed: */
  srand (time(NULL));
  
    

  
  int theNumber;	//number to be inserted by provider
  pthread_t p[PROVIDER_NUM];
  pthread_t b[BUYER_NUM];
  void *thread_result;
  int state1, state2;
  state1 = pthread_mutex_init(&mutx, NULL);
  state2 = sem_init(&bin_sem, 0 ,0);
  //mutex initialization
  //semaphore initialization, first value = 0

  if(state1||state2!=0)
    puts("Error mutex & semaphore initialization!!!");
  
  

  // Create provider threads
  for(int j = 0; j < PROVIDER_NUM; j++)
  {    
    pthread_create(p[j], NULL, thread_Insert, j);
    
  }
  
  // Create buyer threads
  for(int i = 0; i < BUYER_NUM; i++)
  {    
    pthread_create(b[i], NULL, thread_Remove, i);
  }

  // Waiting buyer threads to terminate
  for(int k = 0; k < BUYER_NUM; k++)
  {   
    pthread_join(b[k], &thread_result);
  }
;

  printf("Final Index: %d\n", index_counter);
  
  sem_destroy(&bin_sem);	// destroy semaphore
  pthread_mutex_destroy(&mutx);	// destroy mutex
  return 0;
}

// Provider inserts item into queue
void *thread_Insert(void *arg)
{
  int i;
  int theGoods = random() % 10;
  printf("Creating Thread: %s\n", (char*)arg);
  
  for(;index_counter<BUFFER_SIZE;)
  {
    pthread_mutex_lock(&mutx);
    
    if(theQueue.empty())
    {
      index_counter++;     
      printf("Provider %s: INSERTED item %d to QUEUE %d\n", (char*)arg, theGoods, theQueue.push();
      sem_post(&bin_sem);	// semaphore to increase
    }
    else
    {
      sleep(2);
    }
    pthread_mutex_unlock(&mutx);
  }
}

// Thread decreases items
void *thread_Remove(void *arg)
{
  int i;
  
  printf("Creating Thread: %s\n", (char*)arg);
  
  while(!theQueue.empty())
  {
    sem_wait(&bin_sem);	//decrease index_counter
    pthread_mutex_lock(&mutx);
      sleep(1);
      printf("Buyer %s: REMOVED item %d from QUEUE\n", (char*)arg, theQueue.pop());
      buffer[index_counter] = 0;
      index_counter--;
      pthread_mutex_unlock(&mutx);
   }
}