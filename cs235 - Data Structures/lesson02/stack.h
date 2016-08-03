/***********************************************************************
* Header:
*    Stack
* Summary:
*    This container will hold items in it with the notion that
*    the first item in the container is the last item to be taken
*    out of the container.
*
*    Time:
*    5 hours, most difficult part was figuring out how the
*             push() function uses the growing function
*             similar to vector.
*    Author:
*    Derek Calkins
************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

/************************************************
 * STACK
 * A class that holds things in an array
 * based on the fact of "First in, last out"
 ***********************************************/
template <class T>
class Stack
{
public:
   // default constructor : empty and kinda useless
   Stack() : numItems(0), myCapacity(0), data(0x00000000) {}

   // copy constructor : copy it
   Stack(const Stack & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Stack(int myCapacity) throw (const char *);
   
   // destructor : free everything
   ~Stack()        { if (myCapacity) delete [] data; }
   
   // is the stack currently empty
   bool empty() const  { return numItems == 0;         }

   // how many items are currently in the stack?
   int size() const    { return numItems;              }

   // add an item to the top of the stack
   void push(const T & t) throw (const char *);

   // checks to see if we need to make the stack size bigger
   void resize(const T & t);

   // removes an item from the top of the stack
   void pop() throw (const char *);

   // looks at what is on the top of the stack
   const T top() const throw (const char *);
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Stack?
   int myCapacity;    // how many items can I put on the Stack before full?
};

/*******************************************
 * STACK :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
{
   assert(rhs.myCapacity >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.myCapacity == 0)
   {
      myCapacity = numItems = 0;
      data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.myCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the stuff
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.myCapacity);
   myCapacity = rhs.myCapacity;
   numItems = rhs.numItems;
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];
}

/**********************************************
 * STACK :: NON-DEFAULT CONSTRUCTOR
 * Preallocate the stack to "myCapacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int myCapacity) throw (const char *)
{
   assert(myCapacity >= 0);
   
   // do nothing if there is nothing to do
   if (myCapacity == 0)
   {
      this->myCapacity = this->numItems = 0;
      this->data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[myCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   // copy over the stuff
   this->myCapacity = myCapacity;
   this->numItems = 0;
}

/*******************************************
 * STACK :: PUSH
 * Adds to the top of the stack
 *******************************************/
template <class T>
void Stack <T> :: push(const T & t) throw (const char *)
{
   resize(t);
   data[numItems++] = t;
}

/*******************************************
 * STACK :: POP
 * Removes the top of the stack
 *******************************************/
template <class T>
void Stack <T> :: pop() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: Unable to pop from an empty Stack";
   else
      data[numItems] = data[numItems--]; 
}

/*******************************************
 * STACK :: TOP
 * Looks at the top of the stack
 *******************************************/
template <class T>
const T Stack <T> :: top() const throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: Unable to reference the element from an empty Stack";
   else
      return data[numItems - 1];      
}

/*******************************************
 * STACK :: RESIZE
 * Reallocates the size of the stack if you need
 * to push more items than current capacity.
 *******************************************/
template <class T>
void Stack <T> :: resize(const T & t)
{
   if (myCapacity == 0)
   {
      myCapacity += 1;
      data = new T[myCapacity];
   }
   else if (myCapacity == numItems)
   {
      T * newData;
      myCapacity *= 2;
      try
      {
         newData = new T[myCapacity];
      }
      catch(std::bad_alloc)
      {
         throw "Unable to allocate a new buffer for Stack";
         myCapacity /= 2;
      }
      
      int i;
      for (i = 0; i < numItems; i++)
         newData[i] = data[i];
      newData[i] = '\0';

      delete [] data;
      data = newData;
   }
}     
      
#endif // STACK_H
      
      
