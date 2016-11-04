/*****************************************************
 * Sean Webster
 * Operating Systems
 * Homework 3
 * Due 11/4/2016
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
#include<stdlib.h>
#include<math.h>


#define MAX_SIZE 64
#define POWER log2(MAX_SIZE)

// Allocate large block of memory for use in mms
int *initBlock = malloc(MAX_SIZE);



// realloc-segment block into sections of power 2
// create task requiring memory
// task makes request of size of memory
// find fit of task

int 	*createBlockSizes(void)		// Creates randomized memory block sizes
void 	*memory_malloc(void);		// allocates memory, every time a block is allocated, store the size of that block
									// returns a pointer to the first byte of the block of memory it just allocated
void 	*memory_free(void);			// deallocates memory
void 	*thread_mms(void *arg);		// function for sending
void 	*thread_User(void *arg);	// function for receiving

sem_t bin_sem;		// semaphore
pthread_mutex_t mutx;	// mutex

// Struct for memory objects in a linked list form
struct memblock
{
	int size;			// size of memory block
	int* location;		// location of memory block
	int* last;			// block before current block
	int* next;			// block after current block
};

int main(int argc, char **argv)
{
  //for(int m = 0; m < argc; m++)
     // {
    /* initialize random seed: */
    srand (time(NULL));
	int i;
    pthread_t* threads;
    void *thread_result;
    int state1, state2;
	//mutex initialization
    state1 = pthread_mutex_init(&mutx, NULL);
	//semaphore initialization, first value = 0
    state2 = sem_init(&bin_sem, 0 ,0);


	int *sizes = createBlockSizes();
	for(numBlocks = 0; sizes[numBlocks] != 0; numBlocks++)

    
	
    if(state1||state2!=0)
      puts("Error mutex & semaphore initialization!!!");
    
	// Create MMS thread 
    pthread_create(&threads[argv[1]], NULL, thread_MMS, (void*)i);
	
    // Create 'user' threads
    for(j = 0; j < argv[1] - 1; j++)
    {    
      pthread_create(&threads[j], NULL, thread_User, (void*)j);
      
    }

    for(numBlocks = 0; sizes[numBlocks] != 0; numBlocks++)


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

memBlock *initMemBlock(int *sizes, int numBlocks)
{
	int last;
	memBlock *blocks = (memBlock*)malloc(sizeof(memBlock) * numBlocks);
	for(int j = 0; j < numBlocks; j++)
	{
		memBlock[j].size = sizes[j];
		if(numBlocks == 0)
		{
			memBlock[j].location = initBlock;
			memBlock[j].last = 0;
		}
		else
			memBlock[j].location = initBlock + memBlock[j].last.size;
			memBlock[j].last = last;
	}
}
int *createBlockSizes(void)
{
	int *sizes = (int*)malloc(MAX_SIZE * sizeof(int));
	int tempSize;
	int cumSize = 0;
	int curRand;
	for(int i; cumSize <= MAX_SIZE; i++)
	{
	    curRand = rand() % ((int)POWER - 1);
	    while(curRand == 0)
	        curRand = rand() % ((int)POWER - 1);
		tempSize = pow(2, curRand);
		while(tempSize + cumSize > MAX_SIZE)
			tempSize = pow(2, curRand);
		cumSize += tempSize;
		sizes[i] = tempSize;
}
  
int memory_malloc(memBlock **block)			// creates blocks of memory for thread
{
	block.size = ;
}
  
  // Provider inserts item into queue
  void *thread_MMS(void *arg)
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