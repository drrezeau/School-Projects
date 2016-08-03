/***********************************************************************
* Program:
*    Lab ProducerConsumer  
*    Brother Jones, CS 345
* Author:
*    Hyungjun An
*
* Summary:
*    This program uses Pthreads semaphores to solve a concurrency issue.
*    It producer and consumer threads that use a shared buffer. When
*    running of program for 2 seconds with one producer and one consumer
*    should produce around 15 to 30 lines of output.
************************************************************************/
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

typedef int bufferItem;
#define BUFFER_SIZE 5
#define RAND_MAX_SIZE 150000

//Pointer to make the buffer FIFO
int bufferFront = 0;
int bufferEnd = 0;

bufferItem buffer[BUFFER_SIZE];

pthread_mutex_t myMutex;
sem_t full;
sem_t empty;


/**********************************************************
 * This function will create a new item to insert into the
 * buffer.
 **********************************************************/
void *producer (void *param)
{
   bufferItem itemProduced;
   int* threadNumber;
   threadNumber = (int*) param;
   int num = *threadNumber;
   
   while (true)
   {
      /* sleep for a random period of time */
      usleep(rand() % RAND_MAX_SIZE);
      /* generate a random number */
      itemProduced = (rand() % 1000);  
      //Wait if full
      sem_wait(&full);
      /* acquire the lock */
      pthread_mutex_lock(&myMutex);
 
      buffer[(bufferEnd) % BUFFER_SIZE] = itemProduced;
      bufferEnd++;
      cout << setw(5) << itemProduced << setw(8) << "P" << num << endl;    
      /* release the lock */
      pthread_mutex_unlock(&myMutex);
      //no longer empty
      sem_post(&empty);
   }
}


/**********************************************************
 * This function will consume an item created by the
 * producer.
 **********************************************************/
void *consumer(void *param)
{
   bufferItem consumedItem;

   //Thread number
   int* threadNumber;
   threadNumber = (int*) param;
   int num =  *threadNumber;
   
   while (true)
   {
      /* sleep for a random period of time */
      usleep (rand() % RAND_MAX_SIZE);

      //wait if empty
      sem_wait(&empty);

      /* acquire the lock */
      pthread_mutex_lock(&myMutex);
     
      consumedItem = buffer[bufferFront % BUFFER_SIZE];
      bufferFront++;
    
      cout << setw(22) << consumedItem << setw(7) << "C" << num << endl;
      
      /* release the lock */
      pthread_mutex_unlock(&myMutex);

      //No longer full
      sem_post(&full);
   }
}

/**********************************************************
 * Main will create the threads and then sleep for a while
 * and then delete the threads.
 **********************************************************/
int main (int argc, char *argv[])
{
   srand(time(NULL));
   
   /* 1. Check and get command line arguments argv[1], argv[2], argv[3] */
   if (argc < 3)
   {
      cout << "Incorrect arguments" << endl;
      cout << "1 - sleep time" << endl;
      cout << "2 - producers" << endl;
      cout << "3 - consumers" << endl;
      return 0;
   }

   int sleepTime = atoi(argv[1]);
   int numProducers = atoi(argv[2]);
   int numConsumers = atoi(argv[3]);
   int sendItemTest = 0;
   
   cout << "Sleep time: " << sleepTime << endl;
   cout << "Producers : " << numProducers << endl;
   cout << "Consumers : " << numConsumers << endl;

   /* 2. Initialize buffer [good for error checking but not really needed]*/
   
   cout << "Produced  by P#  Consumed  by C#" << endl;
   cout << "========  =====  ========  =====" << endl;
      
   /* 3. Initialize the mutex lock and semaphores */
   int error[3] = {0};
   error[0] = pthread_mutex_init (&myMutex, NULL);
   error[1] = sem_init (&empty, 0, 0);
   error[2] = sem_init (&full, 0, BUFFER_SIZE);

   //Check for errors
   for (int i = 0; i < 3; i++)
   {
      if (error[i] != 0)
      {
         cout << "Error!\n";
         exit(0);
      }
   }

   /* 4. Create producer threads(s) */
   pthread_t *producers;
   producers = new pthread_t[numProducers];

   //create an array of pointers to send to the threads
   int ** sendProducers;
   sendProducers = new int* [numProducers];
   
   for (int i = 0; i < numProducers; i++)
   {
      //set up the pointer and set the value
      sendProducers[i] = new int;
      *(sendProducers[i]) = i + 1;

      if ( pthread_create( &producers[i], NULL, producer,
                           (void*) sendProducers[i]) != 0)
      {
         cout << "ERROR in creation of the producer threads.\n";
         exit(0);
      }
   }
   
   /* 5. Create consumer threads(s) */
   pthread_t *consumers;
   consumers = new pthread_t[numConsumers];
   //set up an array of pointers to send the number value to the thread
   int ** sendConsumers;
   sendConsumers = new int* [numConsumers];
   
   for (int i = 0; i < numConsumers; i++)
   {
      //set up the pointer and then assign the value to it
      sendConsumers[i] = new int;
      *(sendConsumers[i]) = i + 1;
      
      if ( pthread_create( &consumers[i], NULL, consumer,
                           (void*) sendConsumers[i]) != 0)
      {   
         cout << "ERROR in creation of the consumer threads.\n";
         exit(0);
      }
   }

   /* 6. Sleep [ to read manual page, do: man 3 sleep ]*/
   sleep(sleepTime);
   
   /* 7. Cancel threads [ pthread_cancel() ] */
   for (int i = 0; i < numConsumers; i++)
   {
      delete sendConsumers[i];
      if ( pthread_cancel( consumers[i]) != 0)
      {
         cout << "ERROR in cancellation of the consumer threads.\n";
         exit(0);
      }
   }

   for (int i = 0; i < numProducers; i++)
   {
      delete sendProducers[i];
      if ( pthread_cancel( producers[i]) != 0)
      {
         cout << "ERROR in cancellation of the producer threads.\n";
         exit(0);
      }
   }

   delete[] sendConsumers;
   delete[] sendProducers;
   delete[] consumers;
   delete[] producers;
   
   /* 8. Exit */
   return 0;
}
   
   


