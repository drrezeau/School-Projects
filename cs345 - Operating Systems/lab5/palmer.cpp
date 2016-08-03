/***********************************************************************
 * Program:
 *    Lab ProducerConsumer
 *    Brother Jones, CS 345
 * Author:
 *    Palmer Cluff
 *
 * Conclusions:
 *    I have learned that using semaphores, the producer & consumer
 *    method of working with threads is efficient and less prone to
 *    errors.
 *
 * Summary:
 *    A multi-threaded program that uses semaphores for the producer &
 *    consumer scenerio.
 ************************************************************************/
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

//Set the buffetItem and buffer size
typedef int bufferItem;
#define BUFFER_SIZE 5

//Set the variables
pthread_mutex_t myMutex;

sem_t empty;
sem_t full;

bufferItem buffer[BUFFER_SIZE];
bufferItem front = 0;
bufferItem back = 0;

//Prototype
void *consumer(void *param);
void *producer(void *param);

/**********************************************************************
 * INITIALIZE
 * Initialize the start variables.
 **********************************************************************/
void initialize()
{
   //create the mutex thread
   pthread_mutex_init(&myMutex, NULL);
   
   //create the semaphore and initalize to 5
   sem_init(&full, 0, 0);
   
   //create empty semaphore
   sem_init(&empty, 0, BUFFER_SIZE);
   
   //Initialize the buffer
   for (int i = 0; i < BUFFER_SIZE; i++)
   {
      buffer[i] = 0;
   }   
}

/**********************************************************************
 * INSERT
 * This function inserts into the buffer.
 **********************************************************************/
void insert(int item)
{
   buffer[front] = item;
   front = ++front % BUFFER_SIZE;
}

/****************************************************************************
 * REMOVE
 * This function removes from the buffer.
 *****************************************************************************/
int remove()
{
   int temp = buffer[back];
   back = ++back % BUFFER_SIZE;
   return temp;
}

/**********************************************************************
 * PRODUCER
 * This function handles the producer threads to insert randomly
 * generated values from 0 - 999 into the buffer after sleeping. It
 * takes advantage of semaphores in doing so.
 **********************************************************************/
void *producer (void *param)
{
   bufferItem itemProduced;
   
   int * temp = (int*)param;
   int pValue = *temp;
   delete temp;
   
   while (true)
   {
      /* sleep for a random period of time */
      usleep(rand() % 300000);
      
      /* generate a random number */
      itemProduced = (rand() % 1000);

      /* insert item into shared global buffer and print what was done */
      sem_wait(&empty);
      pthread_mutex_lock(&myMutex);

      insert(itemProduced);

      cout << setw(6) << itemProduced << setw(6) << "P" << pValue << endl;
      //Check that the buffer is inside bound.

      //Unlock
      pthread_mutex_unlock(&myMutex);

      sem_post(&full);
   }
}

/**********************************************************************
 * CONSUMER
 * This function handles the consumer threads to remove the values
 * from the buffer after sleeping.
 **********************************************************************/
void *consumer(void *param)
{
   bufferItem consumedItem;

   int * temp = (int*)param;
   int cValue = *temp;
   delete temp;

   while (true)
   {
      /* sleep for a random period of time */
      usleep(rand() % 300000);

      /* consume item from shared global buffer and print what was done */
      sem_wait(&full);

      pthread_mutex_lock(&myMutex);

      consumedItem = remove();

      cout << setw(20) << consumedItem << setw(6) << "C" << cValue << endl;

      pthread_mutex_unlock(&myMutex);
      sem_post(&empty);
   }
}

/**********************************************************************
 * MAIN
 * This function acts as the driver for the program. It takes in 3
 * parameters to account for sleep time, the number of producer
 * threads, and the number of consumer threads. It also handles all
 * initialization, thread creation, sleeps, and cancels the threads.
 **********************************************************************/
int main (int argc, char *argv[])
{

   int sleepTime;
   int producers;
   int consumers;

   /* 1. Check and get command line arguments argv[1], argv[2], argv[3] */
   if (argc == 4)
   {
      sleepTime = atoi(argv[1]);
      producers = atoi(argv[2]);
      consumers = atoi(argv[3]);

      //Base display
      cout << "Produced by P# Consumed by C#" << endl
           << "======== ===== ======== =====" << endl;
      srand(time(NULL));
   }

   //Usage statement
   else
   {
      cout << "Please enter 3 arguments. The first should be the amount"
           << " of sleep time. The second argument should be the number"
           << " of producer threads. The last argument should be the"
           << " number of consumer threads." << endl;
      return 0;
   }

   /* 2. Initialize buffer [good for error checking but not really needed]*/
   /* 3. Initialize the mutex lock and semaphores */

   initialize();

   /* 4. Create producer threads(s) */
   pthread_t * producerThread = new pthread_t[producers];

   for (int i = 0; i < producers; i++)
   {
      int * ID = new int(i + 1);
      if (pthread_create(&producerThread[i], NULL, producer, (void* ) ID))
      {
         cerr << "Error creating consumer thread.\n" << i << endl;
         delete ID;
         return -2;
      }
   }

   /* 5. Create consumer threads(s) */
   pthread_t * consumerThread = new pthread_t[consumers];
   for(int i = 0; i < consumers; i++)
   {
      int * ID = new int(i + 1);
      if (pthread_create(&consumerThread[i], NULL, consumer, (void *) ID))
      {
         cerr << "Error creating producer thread.\n" << i << endl;
         delete ID;
         return -3;
      }
   }


   /* 6. Sleep [ to read manual page, do: man 3 sleep ]*/
   sleep(sleepTime);

   /* 7. Cancel threads [ pthread_cancel() ] */
   for (int i = 0; i < producers; ++i)
   {
      pthread_cancel(producerThread[i]);
   }

   for (int i = 0; i < consumers; ++i)
   {
      pthread_cancel(consumerThread[i]);
   }

   delete[] producerThread;
   delete[] consumerThread;

   /* 8. Exit */
   return 0;
}
