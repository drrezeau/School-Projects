/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    This contains the class for our Node. It also contains the different
 *    stand alone functions allowing us to insert into a list, copy, find and
 *    free the data.
 * Author
 *    David Lambertson
 ************************************************************************/


#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>

/**********************
 *Node class to create nodes
 * to be used within a linked list
 **********************/
template <class T>
class Node
{
  public:
   T data;
   Node<T> * pNext;
   Node<T> * pPrev;

   Node() : data(), pNext(NULL), pPrev(NULL) {}
   Node(T data)
   {
      this->data = data;
      pNext = NULL;
      pPrev = NULL;
   }
};

/****************************
 * allows the program to create copy
 * a list of Nodes 
 ****************************/
template <class T>
Node<T> * copy(Node<T> * p)
{
   Node<T> * pHead = NULL;
   Node<T> * pNew = new Node<T>;

   for (; p; p = p->pNext)
   {
      Node<T> * tmp = new Node<T>;
      tmp->data=p->data;
      if (pHead == NULL)
      {
         tmp->pNext = NULL;
         tmp->pPrev = NULL;
         pNew = tmp;
         pHead = pNew;
      }
      else
      {
         pNew->pNext = tmp;
         tmp->pPrev = pNew;
         pNew = tmp;
         tmp->pNext = NULL;
      }
      
   }

   return pHead;
}

/*****************************
 * lets us insert into the list
 ******************************/
template <class T>
void insert(T value, Node<T> * & p)
{
 
   if (p == NULL)
   {
      insert(value, p, true);
   }
   else
   {
      Node<T> * pNew = new Node<T>;
      pNew->data = value; 
      pNew->pNext = p->pNext;
      pNew->pPrev = p;
      if (p->pNext != NULL)
         p->pNext->pPrev = pNew;
      p->pNext = pNew;
      
   }
}

/****************************
 *insert when at front of head
 ******************************/
template <class T>
void insert(T value, Node<T> * & p, bool head)
{
   assert(head);
   Node<T> * pNew = new Node<T>;
   pNew->data = value;
   pNew->pNext = p;
   if (p != NULL)
      p->pPrev = pNew;
   p = pNew;
   pNew->pPrev = NULL;
}

/******************************
 *finds if the value given is within the list we have
 ***************************************/
template <class T>
Node<T> * find(Node<T> * & pHead, T value)
{

    if (pHead == NULL)
   {
      return NULL;
   }
   Node<T> * found = new Node<T>;
   for (Node<T> * p = pHead; p != NULL; p = p->pNext)
   {
      if (p->data == value)
      {
         found = p;
         break;
      }
      else
         found = NULL;
      
   }
   return found;
}

/*********************************
 *frees the data taken up by the list
 *********************************/
template <class T>
void freeData(Node<T> * & pHead)
{
   Node<T> * p;
   for (p = pHead; p; p = p->pNext)
   {
      Node<T> * tmp = p;
      delete tmp;
   }
   pHead = NULL;
}

/********************************************************
 *overloaded insertion operator allowing us to make displaying more easy
 *****************************************************/
template <class T>
std::ostream& operator << (std::ostream& out, const Node<T> * p)
{
   for (const Node<T> * pNew = p; pNew; pNew = pNew->pNext)
   {
      if (pNew->pNext != NULL)
         out << pNew->data << ", ";
      else
         out << pNew->data;
   }

   return out;
}
           
#endif
