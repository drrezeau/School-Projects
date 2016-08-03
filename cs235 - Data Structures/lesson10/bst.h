/*******************************
 * Module:
 *    Lesson 08, BST
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson and Derek Calkins
 * Summary:
 *    This program contains the necessary
 *    methods for creating a Binary Search
 *    Tree and an iterator for it. 
 ****************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"

template<class T>
class BSTIterator;

/***********************************************
 * This is the class definition for our Binary
 * Search Tree.
 *************************************************/
template <class T>
class BST
{
  public:
  BST() : myRoot()  {}

  BST(BinaryNode<T> * root) : myRoot(root) {}

   ~BST() { clear(); }

   //adds the new data in the appropriate place
   void insert(const T & data);

   //assignment operator using copyBinaryTree from BinaryNode class
   BST<T> operator =(BST<T> & rhs)
   {
      BinaryNode<T> * pSrc = rhs.myRoot;
      myRoot->copyBinaryTree(pSrc, myRoot);
   }
      
   //also a friend of the iterator so we can use it's variable
   void remove(BSTIterator<T> spot);

   //checks to see if we have anything in the tree
   bool empty() const { return (myRoot == NULL); }

   //clears all of the nodes in the tree
   void clear()
   {
      if (myRoot == NULL)
         return;
      deleteBinaryTree(myRoot);
   }

   //allows the user to be able to get the root node
   BinaryNode<T> * getRoot()
   {
      if (myRoot->pParent != NULL)
         myRoot = myRoot->pParent;
      return myRoot;
   }

   //return iterator to data if found
   BSTIterator<T> find(const T & data); 

   //iterator to the lowest value node
   BSTIterator<T> begin();
   //iterator to NULL
   BSTIterator<T> end(){ return BSTIterator<T>(NULL); }  
   //iterator to the highest value node
   BSTIterator<T> rbegin();
   //iterator to NULL
   BSTIterator<T> rend(){ return BSTIterator<T>(NULL); }

  private:
   BinaryNode<T> * myRoot;
   BinaryNode<T> * findForInsert(BinaryNode<T> * & p, const T & data);

};

/***********************************************
 * This is the definition for our insert function
 **********************************************/
template<class T>
void BST<T> :: insert(const T & data)
{
   BinaryNode<T> * pNew = findForInsert(myRoot, data);
   if (myRoot == NULL)
   {
      myRoot = new BinaryNode<T>(data);
   }
   else if (data > pNew->data)
   {
      pNew->addRight(data);
   }
   else
   {
      pNew->addLeft(data);
   }
}

/**************************************
 * This finds the parent Node of which we should add.
 *************************************/
template <class T>
BinaryNode<T> * BST<T> :: findForInsert(BinaryNode<T> * & p, const T & data)
{
   if (p == NULL)
      return p;
   if (p->data > data)
   {
      if (p->pLeft == NULL)
         return p;
      findForInsert(p->pLeft, data);
   }
   else
   {
      if (p->pRight == NULL)
         return p;
      findForInsert(p->pRight, data);
   }
}

/****************************************
 * Begin (returns a pointer to lowest)
 ****************************************/
template <class T>
BSTIterator<T> BST<T> :: begin()
{      
   BinaryNode<T> * tmp = myRoot;
   if (!tmp)
      return tmp;
   while (tmp->pLeft)
   {
      tmp = tmp->pLeft;
   }
   BSTIterator<T> it = tmp;
   return it;
}

/****************************************
 * Reverse Begin (returns a pointer to highest)
 ****************************************/
template <class T>
BSTIterator<T> BST<T> :: rbegin()
{
   BinaryNode<T> * tmp = myRoot;
   if (!tmp)
      return tmp;
   while (tmp->pRight)
   {
      tmp = tmp->pRight;
   }
   BSTIterator<T> it = tmp;
   return it;
} 

/****************************************
 * FIND
 * Finds if we have the data and returns
 * a pointer to that node
 ****************************************/
template <class T>
BSTIterator<T> BST<T> :: find(const T & data)
{
   BinaryNode<T> * tmp = myRoot;
   while (tmp != NULL)
   if (tmp->data == data)
      return BSTIterator<T>(tmp);
   else if (tmp->data > data)
      tmp = tmp->pLeft;
   else
      tmp = tmp->pRight;
   
   return end();
}

/***************************************
 * REMOVE
 * removes node at location given.
 **************************************/
template <class T>
void BST<T> :: remove(BSTIterator<T> p)
{
   //if the node is not within the BST
   if (p == end())
      return;
   
   //if I don't have any children
   if(!p.spot->pLeft && !p.spot->pRight)
   {
      if(p.spot->amIRight())
         p.spot->pParent->pRight = NULL;
      else
         p.spot->pParent->pLeft = NULL;
      //after setting parent to NULL, delete node
      delete p.spot;
   }
   //if I have two children
   else if(p.spot->pLeft && p.spot->pRight)
   {
      //create iterator to point to successor
      BSTIterator<T> it = p;
      //move new iterator to point to successor
      ++it;
      //copy data from successor to node to overwrite
      p.spot->data = it.spot->data;
      //since we know that the successor will have one
      //child or no children, pass back successor node
      //to be able to delete
      remove(it);
   }
   //I have a child
   else
   {
      //do I have a left child?
      if(p.spot->pLeft)
      {
         p.spot->pLeft->pParent = p.spot->pParent;
         if(p.spot->amIRight())
            p.spot->pParent->pRight = p.spot->pLeft;
         else
            p.spot->pParent->pLeft = p.spot->pLeft;
      }
      //I must have a right child
      else
      {
         p.spot->pRight->pParent = p.spot->pParent;
         if(p.spot->amIRight())
            p.spot->pParent->pRight = p.spot->pRight;
         else
            p.spot->pParent->pLeft = p.spot->pRight;  
      }
      //after changing the pointers delete node
      delete p.spot;
   }
}

/************************************************
 * This is the class definition for the Binary
 * Search Tree Iterator.
 **********************************************/
template <class T>
class BSTIterator
{
  public:
   //default constructor
  BSTIterator() : spot() {}

   //non-default constructor
   BSTIterator(BinaryNode<T> * p)
   {
      if (p == NULL)
         spot = NULL;
      else
         spot = p;
   }

   //assignment operator
   BSTIterator<T> operator =(const BSTIterator<T> & rhs)
   {
      this->spot = rhs.spot;
      return *this;
   }

   //are they equal?
   bool operator ==(const BSTIterator<T> & rhs)
   { return (this->spot == rhs.spot); }

   //are they not equal?
   bool operator !=(const BSTIterator<T> & rhs)
   { return (this->spot != rhs.spot); }

   //dereference operator
   T & operator *() { return spot->data; }

   //overloaded operators
   BSTIterator<T> operator ++();
   BSTIterator<T> operator --();

  private:
   BinaryNode<T> * spot;

   //friend so we can access the iterator
   template <class U>
   friend void BST<U> :: remove(BSTIterator<U> p);
};

/*********************************************
 * Increment Operator
 * Goes to the successor
 *********************************************/
template <class T>
BSTIterator<T> BSTIterator<T> :: operator ++()
{
   // has right child
   if (spot->pRight != NULL)
   {
      spot = spot->pRight;
      while (spot->pLeft)
         spot = spot->pLeft;
   }
   
   // has no right child 
   else
   {
      while (spot->amIRight())
         spot = spot->pParent;
      if (spot->pParent != NULL)
         spot = spot->pParent;
      else
         spot = NULL;
   }
   return *this;
}

/*********************************************
 * Decrement Operator
 * Goes to the predecessor
 *********************************************/
template <class T>
BSTIterator<T> BSTIterator<T> :: operator --()
{
   // has left child
   if (spot->pLeft != NULL) 
   {
      spot = spot->pLeft;
      while (spot->pRight)
         spot = spot->pRight;
   }
   
   // has no left child
   else
   {
      while (spot->amILeft())
         spot = spot->pParent;
      if (spot->pParent != NULL)
         spot = spot->pParent;
      else
         spot = NULL;
   }
   return *this;
}


#endif // BST_H
