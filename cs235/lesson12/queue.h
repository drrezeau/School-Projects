/**************************************************
 * QUEUE.H
 * Summary:
 *    This is our implementation of the Queue Abstract
 *    Data Type. It allows a user to see whats at the front and back
 *     and also lets them push or pop items in the queue. 
 * Author: 
 *    David Lambertson
 * Time:
 *   Estimated: 6 hours
 *   Actual: 5 hours
 * Hardest Part:
 *      Getting the resize function to work properly with the
 *      wrap around. 
 **************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

/******************************
 * This is the class for Queue.
 * It holds all the member functions
 * and variables that we use within Queue.
 ******************************/
template<class T>
class Queue
{
  public:
   //default constructor
  Queue() : myCapacity(0), numPush(0), numPop(0), data(0x00000000) {}

   //non default constructor
   Queue(int myCapacity) throw (const char *);

   //Copy Constructor
   Queue(const Queue<T> & rhs) throw (const char *);

   //Destructor
   ~Queue() { delete [] data; }

   //checks to see if the Queue is empty
   bool empty() const { return (numPush == numPop); }

   //returns the capacity of the queue
   int capacity() const { return myCapacity; }

   //returns the number of items saved in the queue
   int size() const { return (numPush - numPop); }

   //clears the queue and sets everything to 0
   void clear() { numPush = 0; numPop = 0; }

   //saves a value from the user at the end of the queue
   void push(const T & value)
   {
      resize(); //grows when needed


      data[numPush%myCapacity] = value;
      numPush++;
   }

   //pops an item from the front of the queue
   void pop() throw (const char *)
   {
      if(empty())
         throw "ERROR: attempting to pop from an empty queue";
      numPop++;
   }
      
   //returns what item is at the back of the queue
   T & back() throw (const char *)
   {
      if(empty())
         throw "ERROR: attempting to access an item in an empty queue";
      return data[iTail()];
   }

   //returns what item is at the front of the queue
   T & front() throw (const char *)
   {
      if(empty())
         throw "ERROR: attempting to access an item in an empty queue";
      return data[iHead()];
   }
      
      

  private:
   T * data;
   int myCapacity;
   int numPush; //number of pushes
   int numPop;  //number of pops

   //returns the integer spot for front
   int iHead()
   {
      return numPop % myCapacity;
   }

   //returns integer spot for back
   int iTail()
   {
      return (numPush - 1) % myCapacity;
   }

   //resizes the data
   void resize() throw (const char *);

};

/***********************
 * copy constructor
 ***********************/
template <class T>
Queue<T> :: Queue(const Queue<T> & rhs) throw (const char *)
{
   this->myCapacity = rhs.myCapacity;
   this->numPop = rhs.numPop;
   this->numPush = rhs.numPush;

   try
   {
      data = new T[myCapacity];
   }
   catch(...)
   {
      throw "Unable to allocate buffer.";
   }
    for (int i =0; i < (rhs.numPush-rhs.numPop); i++)
   {
       data[i] = rhs.data[iHead() + i];
   }
}

/******************
 * Non Default Constructor
 ****************/
template<class T>
Queue<T> :: Queue(int myCapacity) throw (const char *)
{
   assert(myCapacity > 0);


   try
   {
      data = new T[myCapacity];
   }
   catch(...)
   {
      throw "Error: Unable to allocate buffer.";
   }
   
   this->myCapacity=myCapacity;
   this->numPush=0;
   this->numPop=0;
}

/**********************************
 * reallocates the data if no more space
 * is available for data to be saved.
 **********************************/
template <class T>
void Queue <T> :: resize() throw (const char *)
{
   if (myCapacity == 0)
   {
      myCapacity += 1;
      data = new T[myCapacity];
   }
   else if (myCapacity == (numPush-numPop))
   {
      T * newData;
      myCapacity *= 2;
      try
      {
         newData = new T[myCapacity];
      }
      catch(...)
      {
         throw "Unable to allocate a new buffer for Stack";
         myCapacity /= 2;
      }
      int i = 0;
      for (; i < (numPush-numPop); i++)
      {
         newData[i] = data[(iHead() + i) % (numPush-numPop)];
      }
      numPush = i;
      numPop = 0;
      
      delete [] data;
      data = newData;
   }
}

#endif
