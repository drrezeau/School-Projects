/***********************************************************************
* Program:
*    Lab ProducerConsumer  
*    Brother Jones, CS 345
* Author:
*    David Lambertson
*
* Summary:
*    This lab was about learning what and how mutex locks and semaphores work.
*    They are good when you have critical code that should only be running one
*    at a time. You can put a lock at the beginning to stop anything else
*    from doing that section until it unlocks.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <cassert>
using namespace std;


typedef int bufferItem; 
#define BUFFER_SIZE 5

bufferItem buffer[BUFFER_SIZE];
pthread_mutex_t myMutex;
sem_t empty;
sem_t full;

int count, in, out;
/******************************************
*This function is used to add an item.
*If it wasn't added, it returns false
*to let the producer know.
****************************************/
bool addItem(bufferItem item)
{
   sem_wait(&empty); 
   pthread_mutex_lock(&myMutex);//locking

   bool success;
   if (count != BUFFER_SIZE)
   {
      buffer[in] = item;
      in = (in + 1) % BUFFER_SIZE;
      count++;
      success = true;
   }
   else
   {
      //cout << "FULL" << endl;
      success = false;
   }
   
   

   pthread_mutex_unlock(&myMutex);//unlocking
   sem_post(&full);

   return success;
}

/*************************************************
*This removes items from the buffer. If it was unsuccessful
*the function returns false to let the consumer know.
**************************************************/
bool removeItem(bufferItem *consumedNumber)
{
   sem_wait(&full);
   pthread_mutex_lock(&myMutex);

   bool success;
   if (count != 0)
   {
      *consumedNumber = buffer[out];
      out = (out + 1) % BUFFER_SIZE;
      count--;
      
      success = true;
   }
   else
   {
      success = false;
   }
   
    
    pthread_mutex_unlock(&myMutex);
    sem_post(&empty);

    return success;
}

/***************************************
*Produces a number to add to the buffer if
*there is space in the buffer.
**************************************/
void *producer (void *param) 
{
   long j = (long) param;
   bufferItem itemProduced; 
   while (true) 
   {
     
      /* sleep for a random period of time */ 
      usleep(rand() % 150000); 
      /* generate a random number */ 
      itemProduced = (rand() % 1000); 

      //checking if I was able to add it, if so, display.
      if(addItem(itemProduced))
      {
         cout << setw(5) << itemProduced << setw(7) << " P" << (j+1) << endl;
      }
         
   } 
}
/***********************************************
*Consumes items from the buffer if there are items
*to consume.
**********************************************/
void *consumer(void *param) 
{ 
   bufferItem consumedItem;
   long j = (long) param;
   while (true) 
   {
      
      /* sleep for a random period of time */
      usleep(rand() % 150000); 

      //Checking if removal was successful, if so, display.
      if(removeItem(&consumedItem))
      {
         cout << setw(23) << consumedItem << setw(7) << " C" << (j+1) << endl;
      }
      
      
       sem_post(&empty);
   } 
} 


/**********************************************
 *Grabs the variables provided by the user. Lets the user
 *know how to use the program if they dont pass the correct
 *amount of arguments.
 **********************************************/
int main(int argc, char *argv[])
{
   cout << "Lab 5" << endl;
   count = in = out = 0;
   int sleepTime, consumerThreads, producerThreads;
   
   /*  1. Check and get command line arguments argv[1], argv[2], argv[3] */
   if (argc == 4)
   {
      sleepTime = atoi(argv[1]);
      producerThreads = atoi(argv[2]);
      consumerThreads = atoi(argv[3]);
   }
   else 
   {
      cout << "USAGE: a.out 1 2 3\n";
      return 0;
   }

   assert(sleepTime > 0);
   assert(producerThreads > 0);
   assert(consumerThreads > 0);
   
   /*  2. Initialize buffer [good for error checking but not really needed]*/
   cout << "Produced  by P#  Consumed  by C#\n";
   cout << "========  =====  ========  =====\n";
   /*  3. Initialize the mutex lock and semaphores */

   //creating the mutex lock
   pthread_mutex_init(&myMutex, NULL);

   //creating the semaphore
   sem_init(&empty, 0, BUFFER_SIZE);
   sem_init(&full, 0, 0);
   
   /*  4. Create producer threads(s) */
    pthread_t producers[producerThreads];
   for (int i = 0; i < producerThreads; i++)
   {
      pthread_create(&producers[i], NULL, &producer, (void*) i);
   }
   
   /*  5. Create consumer threads(s) */
   pthread_t consumers[consumerThreads];
   for (int i = 0; i < consumerThreads; i++)
   {
      pthread_create(&consumers[i], NULL, &consumer, (void*) i);
   }
   
   /*  6. Sleep [ to read manual page, do:  man 3 sleep ]*/
   sleep(sleepTime);
   
   /*  7. Cancel threads [ pthread_cancel() ] */
   for (int i = 0; i < producerThreads; i++)
   {
      pthread_cancel(producers[i]);
   }
   for (int i = 0; i < consumerThreads; i++)
   {
      pthread_cancel(consumers[i]);
   }
   /*  8. Exit */ 
   return 1;
   
}




