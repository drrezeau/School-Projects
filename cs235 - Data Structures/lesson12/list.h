/***********************************************************************
 * Header:
 *    List
 * Summary:
 *    This is the List and ListIterator classes which are needed
 *    to create a list that can be inserted, removed, and cleared
 *    in constant time rather than a longer computational time.
 * Author:
 *    Derek Calkins
 * Hardest Part:
 *    Finding out how the ListIterator is supposed to use the methods
 *    and member variables of the List class.
 * Time:
 *    Expected: Approx. 5  hours
 *    Actual:   Approx. 10 hours
 ************************************************************************/


#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>
#include "node.h"

template <class T>
class ListIterator; 

/**********************
 * List class to which creates Nodes
 * which are used to create a list
 **********************/
template <class T>
class List
{
public:

   friend std::ostream& operator << (std::ostream& out, const List<T> & rhs)
   {
      out << rhs.pHead;
      return out;
   }
   
   //default constructor
  List() : pHead(NULL), pTail(NULL) {}

   //non-default constructor
   List(T data)
   {
      pHead = NULL;
      pTail = NULL;
   }

   //copy constructor
   List(const List & rhs)
   {
      this->pHead = rhs.pHead;
      this->pTail = rhs.pTail;
   }

   //overloaded assignment operator
   List<T> operator = (const List<T> & rhs);

   //checks if the list is empty
   bool empty()
   {
      if (pHead == NULL)
         return true;
      else
         return false;
   }

   //removes all nodes and pointers
   void clear();

   //adds the value to the end of the list
   void push_back(T value) throw (const char *);
   
   //adds a value to the beginning of the list
   void push_front(T value) throw (const char *);
   
   //returns the value at the beginning of the list
   T & front() throw (const char *) 
   {
      if(empty())
         throw "ERROR: unable to access data from empty list";
      return pHead->data;
   }

   //returns the value at the end of the list
   T & back() throw (const char *)
   {
      if(empty())
         throw "ERROR: unable to access data from empty list";
      return pTail->data;
   }

   //inserts a value into the specified spot in the list
   void insert(ListIterator <T> & it, const T & value);

   //removes a node at the specified spot in the list
   void remove(ListIterator <T> & it) throw (const char *);

   //returns the pointer to the first node in the list
   ListIterator<T> begin() const
   {
      if (pHead == NULL)
      {
          return NULL;
      }
      return pHead;
   }

   //returns the pointer to past the last element of the list
   ListIterator<T> end() const
   {
      if (pTail == NULL)
         return NULL;
      return pTail->pNext;
   }

   //returns the pointer to the first element of the reverse list
   ListIterator<T> rbegin() const
   {
      //if (pTail == NULL)
      //   return NULL;
      return pTail;
   }

   //returns the pointer to the past the last element of the reverse list
   ListIterator<T> rend() const
   {
      if(pHead == NULL)
         return NULL;
      return pHead->pPrev;
   }
   
private:
   Node<T> * pHead;  //Node to the beginning of the list
   Node<T> * pTail;  //Node to the end of the list
};

/************************************
 * ListIterator class which has one Node
 * to determine where an item needs to be
 * inserted or removed from a List
 ***********************************/
template <class T>
class ListIterator
{
public:
   //Default Constructor
  ListIterator() : p(NULL) {}

   //Non Default Constructor
  ListIterator(Node<T> * p) : p(p) {}

   //copy Constructor
   ListIterator(const ListIterator & rhs) { this->p = rhs.p; }

   //overloaded assignment operator
   ListIterator & operator = (const ListIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   bool operator == (const ListIterator & rhs)
   {
      return this->p == rhs.p;
   }
   
   //overloaded not equal operator
   bool operator != (const ListIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   //overloaded by-reference operator
   T & operator * ()
   {    
      return p->data;
   }

   //overloaded prefix add one operator
   ListIterator <T> & operator ++ ()
   {
      p = p->pNext;
      return *this;
   }

   //overloaded postfix add one operator
   ListIterator <T> operator ++ (int postfix)
   {
      ListIterator tmp(*this);
      p = p->pNext;
      return tmp;
   }

   //overloaded prefix subtract one operator
   ListIterator <T> & operator -- ()
   {
      p = p->pPrev;
      return *this;
   }
   
   //overloaded postfix subtract one operator
   ListIterator <T> operator -- (int postfix)
   {
      ListIterator tmp(*this);
      p = p->pPrev;
      return *this;
   }

   //ListIterator Insert uses methods and variables from List
   template <class U>
   friend List<T> insert(ListIterator <U> & it,
                         const T & value);

   //ListIterator Remove uses methods and variables from List
   template <class U>
   friend List<T> remove(ListIterator <U> & it) throw (const char *);

  
   Node<T> * p; //Node where the ListIterator is pointing
};

/****************************
 * OVERLOADED ASSIGNMENT OPERATOR
 * Allows the program to copy
 * one list into another list
 ****************************/
template <class T>
List<T> List<T> :: operator = (const List<T> & rhs)
{
   for (ListIterator<T> it = rhs.begin(); it != rhs.end(); ++it)
   {
      this->push_back(*it);
   }

   return *this;

}

/*****************************
 * INSERT
 * Lets us insert a Node into the middle
 * of the List
 ******************************/
template <class T>
void List<T> :: insert(ListIterator<T> & it, const T & value)
{
   Node<T> * pNew = new Node<T>;
//   catch(std::bad_alloc&)
//      throw "Unable  to allocate a new node for a list";
   pNew->data = value;
   
   if(it.p == NULL)
   {
      push_back(value);
   }
   else if(it.p->pPrev == NULL)
   {
      push_front(value);
   }
   else
   {
      pNew->pNext = it.p;
      pNew->pPrev = it.p->pPrev;
      it.p->pPrev->pNext = pNew;
      it.p->pPrev = pNew;
   }
}

/******************************
 * REMOVE
 * Takes the iterator to the Node we want to remove
 * and depending where that is, deletes the Node
 * and fixes the other Nodes so we don't lose the List.
 ***************************************/
template <class T>
void List<T> :: remove(ListIterator<T> & it) throw (const char *)
{
   if(it.p == NULL)
      throw "unable to remove from an invalid location in list";
   else if(it.p->pNext == NULL)
   {
      pTail = it.p->pPrev;
      it.p->pPrev->pNext = NULL;
      delete [] it.p;
   }
   else if(it.p->pPrev == NULL)
   {
      pHead = it.p->pNext;
      it.p->pNext->pPrev = NULL;
      delete [] it.p;
   }
   else
   {
      it.p->pNext->pPrev = it.p->pPrev;
      it.p->pPrev->pNext = it.p->pNext;
      delete [] it.p;
   }
}

/*********************************
 * CLEAR
 * Frees the data by deleting all the
 * Nodes in the list
 *********************************/
template <class T>
void List<T> :: clear()
{
   Node<T> * p1;
   for (p1 = pHead; p1; p1 = p1->pNext)
   {
      Node<T> * tmp = p1;
      delete tmp;
   }
   pHead = NULL;
   pTail = NULL;
}

template <class T>
void List<T> :: push_back(T value) throw (const char *)
{

   //if we have nothing in the list just push_front
   if(pTail == NULL)
      push_front(value);
   else
   {
      Node<T> * pNew;
      //Cr eate a new Node
      try
      {
         pNew = new Node<T>;
      }
      catch(...)
      {
         throw "Unable to allocate a new node for a list";
      }
      
      pNew->data = value;
      
      
      //if we already have something in the list add at the end
      pNew->pNext = pTail->pNext;
      pNew->pPrev = pTail;
      if (pTail->pNext != NULL)
         pTail->pNext->pPrev = pNew;
      pTail->pNext = pNew;
      pTail = pNew;
      if (pNew->pPrev == NULL)
         pHead = pTail;
   }
}
   
//adds a value to the beginning of the list
template <class T>
void List<T> :: push_front(T value)  throw (const char *)
{
   Node<T> * pNew;
   //Create a new Node
   try
   {
      pNew = new Node<T>;
   }
   catch(...)
   {
      throw "Unable to allocate a new node for a list";
   }
   pNew->data = value;

   //adds at the beginning of the list
   pNew->pNext = pHead;
   if (pHead != NULL)
      pHead->pPrev = pNew;
   pHead = pNew;
   pNew->pPrev = NULL;
   pHead = pNew;
   if (pNew->pNext == NULL)
      pTail = pHead;
}
           
#endif // LIST_H
