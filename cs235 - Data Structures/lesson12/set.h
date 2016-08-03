/**********************************
 *This is my(and Derek's) set.h File. DO NOT TOUCH!!
 *It implements the class Set and its iterator.
 *Please Do not copy this. thank you, Have a Nice Day.

/***********************************************************************
* Program:
*    Assignment 01, set.h
*    Brother Helfrich, CS 235
* Author:
*    David Lambertson
* Summary: 
*    This program is the implementation of the set class. It creates Sets and
*    all of the necessary functions to go along with them. It also implements
*    the SetIterator class to create iterators for the Sets.
*    
*    Estimated:  5.0 hrs   
*    Actual:     7.0 hrs
*      The most difficult part for me was getting my insert to work properly. 
************************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert>


template <class T>
class SetIterator;

template<class T>
class Set      //HIKE!
{
  public:
   //Default Constructor
  Set() : myCapacity(0), numItems(0), data(0x00000000) {}

   //Non-default Constructor 
   Set(int capacity) throw (const char *);

   //Copy Constructor 
   Set(const Set & rhs) throw (const char *) { *this = rhs; }

   //Destructor
   ~Set() {delete [] data; }


   //Checks if the Set is empty
   bool empty() const { return numItems == 00; }

   //returns the size of the Set
   int size() const {return numItems; }

   //inserts a value into the Set at the right spot.
   void insert(const T & value);

   //erases an item given by the user if found. NEEDs
   void erase(SetIterator<T> item);

   // overloaded assignment operator 
   Set<T> & operator = (const Set<T>& rhs);

   //returns an iterator for the beginning of the Set
   SetIterator<T> begin() { return SetIterator<T>(data); }

   //returns an iterator for the end of the Set
   SetIterator<T> end() { return SetIterator<T>(data + numItems); }

   // finds if a given item is in the Set 
   SetIterator<T> find(const T & value);

   //lets the us access the data without changing it.
   T getData(int spot) const { return data[spot]; }

   //overloaded union operator
   Set<T> operator || (Set<T> rhs);
  
   //overloaded intersection operator
   Set<T> operator && (Set<T> rhs);

   
  private:
   int numItems;
   int myCapacity;
   T * data;

   //implements the reallocation of data if needed;
   void regrowth();

   // locates a value within the Set if it exists
   int locate(const T & value);

};

/*********************************
 * This is the class for the iterator 
 * for set which is shown above. 
 *******************************/
template <class T>
class SetIterator
{
  public:
   
   //Default Constructor
  SetIterator() : p(0x00000000) {}

   //Non Default Constructor
  SetIterator(T * p) : p(p) {}

   //copy Constructor
   SetIterator(const SetIterator & rhs) { this->p = rhs.p; }

   //overloaded assignment operator
   SetIterator & operator = (const SetIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   bool operator == (const SetIterator & rhs) const
   {
      return rhs.p == this->p;
   }

   //overloaded not equal operator
   bool operator != (const SetIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   //overloaded by-reference operator
   T & operator * ()
   {
      return *p;
   }

   //overloaded prefix add one operator
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   //overloaded postfix add one operator
   SetIterator <T> operator++ (int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p; //the pointer for the iterator
   
};

/*************************
 * This is the implementation of
 * the non Default Constructor
 *************************/
template <class T>
Set<T> :: Set(int capacity) throw (const char *)
{
   assert (capacity >= 0);

   if (capacity == 0)
   {
      this->myCapacity = this->numItems = 0;
      this->data = 0x00000000;
      return;
   }

    try
   {
      this->data = new T[capacity];
   }

   catch(...)
   {
      throw "Error: Unable to allocate buffer";
   }

   this->myCapacity = capacity;
   this->numItems = 0;
}
      

/*************************
 * Implementation of the overloaded assignment
 * operator, will be used within copy.
 **************************/
template <class T>
Set<T> & Set<T> :: operator = (const Set<T>& rhs)
{
   assert(rhs.myCapacity >=0);

   if (rhs.myCapacity == 0)
   {
      this->myCapacity = this->numItems = 0;
      this->data = 0x00000000;
      return *this;
   }

   try
   {
      this->data = new T[rhs.myCapacity];
   }

   catch(...)
   {
      throw "Error: Unable to allocate buffer";
   }

   this->myCapacity = rhs.myCapacity;
   this->numItems = rhs.numItems;
   for (int i = 0; i < numItems; i++)
      this->data[i] = rhs.data[i];

   return *this;
}

/****************************
 *INSERT (T Value)
 * this function will take the value given by
 * the user and insert it into the function.
 ******************************/
template <class T>
void Set<T> :: insert(const T & value)
{
   
   if (myCapacity == 0)                             // capacity is zero, makes it one and adds the item
   {
      myCapacity += 1;
      data = new T[myCapacity];
      data[numItems] = value;
      numItems++;
      return;
   }

   if (myCapacity == numItems)                      // if the data needs reallocating, do it here
   {
      regrowth();
   }

   
   int spot = locate(value);

   if (data[spot] == value)                       // if data is found, do nothing
   {
      return;
   }
   else                                           //else find where it belongs and put it there
   {

      T *newData = new T[myCapacity];
 
      if (value < data[spot])
      {

         int i;                                  //just like the reallocation, just in parts to 
                                                 //insert the new value
         for (i = 0; data[i] != data[spot]; i++) // moves the data that comes
         {                                       //before the value user wants to insert.
            newData[i] = data[i];
         }
         newData[i] = value;                     //saves the value into the Set
         for (i; data[i] != data[numItems]; i++) //saves the rest of the data left over.
         {
            newData[i+ 1] = data[i];
         }
         delete [] data;                         //delete the old data
         data = newData;                         //point the data to the newData
      }
      else                                       //saves the user value at the end of the Set
      {
         data[numItems] = value;
      }
   }
 
   numItems++;                                   //increment the number of items
}

/***********************
 *FIND I SHALL FIND YOU!!!
 * Lets the user find if an item
 * is in the Set. if not, it points to
 * the end of the Set.
 *************************/
template <class T>
SetIterator<T> Set<T> :: find(const T & value)
{
   int spot = locate(value);
   
   if ( data[spot] == value)
      return SetIterator<T> (&data[spot]);
   else
      return end();
   
}

/***********************
 *YOU SHALL BE DESTROYED!
 *lets the user erase a value if it
 * can be found. if not, does nothing.
 *************************/
template <class T>
void Set<T> :: erase(SetIterator<T> item)
{
   int spot = locate(*item);
   if (data[spot]  == *item)
   {
      numItems--;
      for (int i = spot; i < numItems; i++)
         data[i] = data[i+1];
   }
}


/**************************
 * This lets us use the ||
 * operator in other code.
 **************************/
template <class T>
Set<T> Set<T> :: operator || (Set<T> rhs)
{
   int iSet1 = 0;
   int iSet2 = 0;
   // SetIterator<T> value;
   Set<T> setReturn;
   while ( iSet1 < numItems || iSet2 < rhs.size())
   {
      // value = rhs.find(iSet2);
      if (iSet1 == numItems)
         setReturn.insert(rhs.getData(iSet2++));
      
      else if (iSet2 == rhs.size())
         setReturn.insert(data[iSet1++]);
      
      else if (data[iSet1] == rhs.getData(iSet2))
      {
         setReturn.insert(data[iSet1]);
         iSet1++;
         iSet2++;
      }
      
      else if ( data[iSet1] < rhs.getData(iSet2))
         setReturn.insert(data[iSet1++]);
      
      else
         setReturn.insert(rhs.getData(iSet2++));
   }
   return setReturn;
}

/***************************
 * this lets us use && in other lines of
 * code when it comes to Sets.
 *****************************/
template <class T>
Set<T> Set<T> :: operator && (Set<T> rhs)
{
   int iSet1 = 0;
   int iSet2 = 0;
   
   Set<T> setReturn;
   while ( iSet1 < numItems || iSet2 < rhs.size())
   {
      if (iSet1 == numItems)
         return setReturn;
      
      else if ( iSet2 == rhs.size())
         return setReturn;
      
      else if ( data[iSet1] == rhs.getData(iSet2))
      {
         setReturn.insert(data[iSet1]);
         iSet1++;
         iSet2++;
      }
      
      else if (data[iSet1] < rhs.getData(iSet2))
         iSet1++;
      
      else
         iSet2++;
   }
   
   return setReturn;
}



/**********************
 * This function takes the capacity of the Set
 * and doubles and reallocates the data.
 *********************/
template <class T>
void Set <T> :: regrowth()
{
   T * newData;
   myCapacity *= 2;

   try
   {
      newData = new T[myCapacity];
   }

   catch(...)
   {
      throw "Unable to allocate a buffer for Set.";
   }

   for (int i = 0; i < numItems; i++)
   {
      newData[i] = data[i];
   }

   delete [] data;
   data = newData;
}

/************************
 * This function uses a binary search to locate
 * the given value in the Set, if it is not found
 * returns the value right below it.
 ***************************/
template<class T>
int Set<T> :: locate(const T & value)
{
   int find  = 0;
   int low = 0;
   int high = (numItems - 1);
   
   while ( low <= high)
   {
      find = (high+low)/2;
      if (data[find] == value)
      {
         return find;
      }
      else if (value < data[find])
      {
         high = find - 1;
      }
      else
         low = find + 1;
   }
   if (data[find] < value)
      find++;

   return find;
}

#endif

