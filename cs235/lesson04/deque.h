/**************************************************
 * DEQUE.H
 * Summary:
 *    This class is for the deque which allows the user
 *    to add elements or remove elements from either side
 *    of the container. It also allows the user to access either
 *    end of the deque but not the elements in between.
 * Author: 
 *    Derek Calkins
 * Time:
 *   Estimated: 6 hours
 *   Actual: 6 hours
 * Hardest Part:
 *   -Understanding the iHead and iTail and which was which in the deque.
 *   -Also getting it to allocate with a negative number which is where
 *    iAbsoluteFromI helped a ton.
 **************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <cassert>
#include <cmath>
#include <iostream>

/******************************
 * This is the class for Deque.
 * It holds all the member functions
 * and variables that we use within Deque.
 ******************************/
template<class T>
class Deque
{
  public:
   //default constructor
  Deque() : myCapacity(0), iTail(-1), iHead(0), data(0x00000000) {}

   //non default constructor
   Deque(int myCapacity) throw (const char *);

   //Copy Constructor
   Deque(const Deque<T> & rhs) throw (const char *);

   //Destructor
   ~Deque() { delete [] data; }

   //checks to see if the Deque is empty
   bool empty() const { return (iHead == iTail + 1); }

   //returns the capacity of the deque
   int capacity() const { return myCapacity; }

   //returns the number of items saved in the deque
   int size() const { return ((iTail + 1) - iHead); }

   //clears the deque and sets everything to 0
   void clear() { iTail = -1; iHead = 0; }

   //saves a value from the user at the end of the deque
   void push_back(const T & value) throw (const char *)
   {
      resize(); //grows when needed
      data[iAbsoluteFromI(++iTail)] = value;
   }

   //pushes an item onto the front of the deque
   void push_front(const T & value) throw (const char *)
   {
      resize(); //grows when needed
      data[iAbsoluteFromI(--iHead)] = value;
   }

   //pops an item from the front of the deque
   void pop_front() throw (const char *)
   {
      if(empty())
         throw "ERROR: unable to pop from the front of empty deque";
      iHead++;
   }

   //pops an item from the back of the deque
   void pop_back() throw (const char *)
   {
      if(empty())
         throw "ERROR: unable to pop from the back of empty deque";
      iTail--;
   }
      
   //returns what item is at the back of the deque
   const T & back() throw (const char *)
   {
      if(empty())
         throw "ERROR: unable to access data from an empty deque";
      return data[iAbsoluteFromI(iTail)];
   }

   //returns what item is at the front of the deque
   const T & front() throw (const char *)
   {
      if(empty())
         throw "ERROR: unable to access data from an empty deque";
      return data[iAbsoluteFromI(iHead)];
   }      

   //for finding the absolute value of the index
   const int iAbsoluteFromI(const int & i) const
   {
      return (((i % capacity()) + capacity()) % capacity());
   }
      
  private:
   T * data;         // holds the data
   int myCapacity;   // is the capacity of the deque
   int iTail;        // index of the tail of the deque
   int iHead;        // index of the head of the deque
   
   void resize() throw (const char *);

};

/***********************
 * COPY CONSTRUCTOR
 ***********************/
template <class T>
Deque<T> :: Deque(const Deque<T> & rhs) throw (const char *)
{
   this->myCapacity = rhs.myCapacity;
   this->iTail = rhs.iTail;
   this->iHead = rhs.iHead;

   try
   {
      data = new T[myCapacity];
   }
   catch(...)
   {
      throw "Unable to allocate buffer.";
   }
   for (int i = 0; i < (rhs.myCapacity); i++)
   {
       data[i] = rhs.data[iHead + i];
   }
}

/******************
 * NON DEFAULT CONSTRUCTOR
 ****************/
template<class T>
Deque<T> :: Deque(int myCapacity) throw (const char *)
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
   this->iHead=0;
   this->iTail=-1;
}

/**********************************
 * RESIZE
 * reallocates the data if no more space
 * is available for data to be saved.
 **********************************/
template <class T>
void Deque <T> :: resize() throw (const char *)
{
   if (myCapacity == 0)
   {
      myCapacity += 1;
      data = new T[myCapacity];
   }
   else if (myCapacity == size())
   {
      T * newData;
      myCapacity *= 2;
      try
      {
         newData = new T[myCapacity];
      }
      catch(...)
      {
         throw "Unable to allocate a new buffer for Deque";
         myCapacity /= 2;
      }
      int i = 0;
      for (; i < (size()); i++)
      {
         newData[i] = data[(iAbsoluteFromI(iHead) + i) % (myCapacity/2)];
      }
      iTail = i - 1;
      iHead = 0;

      delete [] data;
      data = newData;
   }
}

#endif
