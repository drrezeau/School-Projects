/**********************************************
 * Program:
 *     Lesson 07, Binary Tree
 *     Brother Helfrich, CS265
 * Author:
 *     David Lambertson
 * Summary:
 *     This file holds the definition of the binary node
 *     used to create a binary tree.
 * Time:
 *    this part of the program took me around 5 hours.
 *********************************************/
#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cassert>

/***************************************************
 * This is the class that holds our Binary Node Definition.
 * It allows us to create Binary Nodes which are used for the tree.
 ************************************************/
template <class T>
class BinaryNode
{
  public:
   T data;
   BinaryNode<T> * pLeft;
   BinaryNode<T> * pRight;
   BinaryNode<T> * pParent;
   bool isRed;


   //Default Constructor
  BinaryNode() :pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
   
   //Non-Default Constructor
  BinaryNode(T data) : data(data), pLeft(NULL), pRight(NULL),pParent(NULL),
      isRed(true) { case1(); }

   /********************************
    * These are our two add Left functions.
    * One takes data and the other takes a Node
    **********************************/
   void addLeft(const T & data);
   void addLeft(BinaryNode<T> * pNew);

   /********************************
    * Similar to our add Lefts, just for right.
    *******************************/
   void addRight(const T & data);
   void addRight(BinaryNode<T> * pNew);

   /****************************************
    *This checks to see if I am the Right child.
    ************************************/
   bool amIRight() const
   { return ((this->pParent) && (this->pParent->pRight == this)); }

   /*************************************
    * This checks if I am the Left child.
    ************************************/
   bool amILeft() const
   { return ((this->pParent) && (this->pParent->pLeft == this)); }

   //Prototype for copying a binary tree
   void copyBinaryTree(const BinaryNode<T> * pSrc, BinaryNode<T> * & pDest)
      throw (const char *);

   
  private:
   void case1(); //user doesn't need to know that I implemented
   void case2(); //a red-black tree along with my binary node.
   void case3();
   void case4();
   void balance();
};

/**************************************
 * case 1 for Black-Red Tree
 *************************************/
template<class T>
void BinaryNode<T> :: case1()
{
   //if I don't have a parent I must be the root
   //so I need to be black
   if(this->pParent == NULL)
      this->isRed = false;
}

/************************************
 * case 2 for Black-Red Tree
 **************************************/
template<class T>
void BinaryNode<T> :: case2()
{
   //makes the parent black
   pParent->isRed == false;
}

/******************************************************
 * case 3 for Black-Red Tree
 ****************************************************/
template<class T>
void BinaryNode<T> :: case3()
{
   //these are the nodes we need to change
   BinaryNode<T> * pGran = this->pParent->pParent;
   BinaryNode<T> * pAunt = ((pGran->pRight == this->pParent) ?
                             pGran->pLeft : pGran->pRight);

   //recolor the node appropriately
   pGran->isRed = true;
   pAunt->isRed = false;
   pParent->isRed = false;

   //balance or check to see that we are all good
   pGran->balance();
}

/******************************
 * Case 4 for Black Red Tree
 ******************************/
template<class T>
void BinaryNode<T> :: case4()
{
   //these are so we don't lose this data in the four functions
   //while rearranging the pointers for rotating
   BinaryNode<T> * pGran = pParent->pParent;
   BinaryNode<T> * pAunt = ((pGran->pRight == pParent) ?
                             pGran->pLeft : pGran->pRight);
   BinaryNode<T> * pSibling = ((pParent->pRight == this) ?
                               pParent->pLeft : pParent->pRight);

   //case 4a
   //if I am the left child and my parent is the left child
   if(this->amILeft() && this->pParent->amILeft())
   {
      //change the colors of parent and grandparent
      pParent->isRed = false;
      pGran->isRed = true;

      //rearrange pointers for rotation
      pParent->pRight = pGran;

      //these are for seeing if we have a great-grandparent
      //and if I do, set the appropriate pointer to new child
      if(pGran->amIRight())
         pGran->pParent->pRight = pGran->pLeft; 
      if(pGran->amILeft())
         pGran->pParent->pLeft = pGran->pLeft;

      //set pointers of parent and grandparent
      pParent->pParent = pGran->pParent;
      pGran->pParent = pParent;

      //bring back sibling if we have one
      pGran->pLeft = pSibling;
      if(pSibling)
         pSibling->pParent = pGran;

      //to break out of case 4 function
      return;
   }

   //case 4b
   //if I am the right child and my parent is the left child
   if(this->amIRight() && this->pParent->amILeft())
   {
      //change the colors of grandparent and I
      this->isRed = false;
      pGran->isRed = true;

      //rearrange pointers for rotation
      this->pParent->pRight = this->pLeft;

      //check if I have children
      //if I do, change pointers appropriately
      if(this->pLeft != NULL)
         this->pLeft->pParent = this->pParent;
      pGran->pLeft = this->pRight;
      if(this->pRight != NULL) 
         this->pRight->pParent = pGran;

      //change parents and grandparents pointers
      this->pLeft = pParent; 
      this->pRight = pGran;

      //these are for seeing if we have a great-grandparent
      //and if I do, set the appropriate pointer to new child
      if(pGran->amIRight())
         pGran->pParent->pRight = this;
      if(pGran->amILeft())
         pGran->pParent->pLeft = this;

      //finish changing pointers
      this->pParent = pGran->pParent;
      this->pRight->pParent = this;
      this->pLeft->pParent = this;

      //to break out of case 4 function
      return;
   }

   //case 4c
   //if I am the right child and my parent is the right child
   if(this->amIRight() && this->pParent->amIRight())
   {
      //change the colors of parent and grandparent
      pParent->isRed = false;
      pGran->isRed = true;

      //rearrange pointers for rotation
      pParent->pLeft = pGran;

      //these are for seeing if we have a great-grandparent
      //and if I do, set the appropriate pointer to new child
      if(pGran->amILeft())
         pGran->pParent->pLeft = pGran->pRight;
      if(pGran->amIRight())
         pGran->pParent->pRight = pGran->pRight;

      //set pointers of parent and grandparent
      pParent->pParent = pGran->pParent;
      pGran->pParent = pParent;

      //bring back sibling if we have one
      pGran->pRight = pSibling;
      if(pSibling)
         pSibling->pParent = pGran;

      //to break out of case 4 function
      return;
   }
   
   //case 4d
   //if I am the left child and my parent is the right child
   if(this->amILeft() && this->pParent->amIRight())
   {
      //change the colors of grandparent and I
      this->isRed = false;
      pGran->isRed = true;

      //rearrange pointers for rotation
      this->pParent->pLeft = this->pRight;

      //check if I have children
      //if I do, change pointers appropriately
      if(this->pRight != NULL)
         this->pRight->pParent = this->pParent;
      pGran->pRight = this->pLeft;
      if(this->pLeft != NULL) 
         this->pLeft->pParent = pGran;
      
      //change parents and grandparents pointers
      this->pRight = pParent; 
      this->pLeft = pGran;  

      //these are for seeing if we have a great-grandparent
      //and if I do, set the appropriate pointer to new child
      if(pGran->amIRight())
         pGran->pParent->pRight = this;
      if(pGran->amILeft())
         pGran->pParent->pLeft = this;

      //finish changing pointers
      this->pParent = pGran->pParent;
      this->pLeft->pParent = this;
      this->pRight->pParent = this;

      //to break out of case 4 function
      return;
   }
}

/***************************
 * this is the overall function
 * that controls the balancing
 * it calls the different cases.
 **************************/
template<class T>
void BinaryNode<T> :: balance()
{
   //if I am the root
   if(pParent == NULL)//case 1
   {
      case1();
      return;
   }

   //if my parent is not the right color
   if(pParent->isRed == false)//case 2
   {
      case2();
      return;
   }

   //create these to check between case 3 and case 4
   BinaryNode<T> * pGran = this->pParent->pParent;
   BinaryNode<T> * pAunt = ((pGran->pRight == this->pParent) ?
                             pGran->pLeft : pGran->pRight);

   //if I have an aunt
   if(pAunt != NULL) //case 3
   {
      case3();
      return;
   }
   //if I don't have an aunt
   else //case 4
   {
      case4();
      return;
   }
}

/*********************************
 * overloaded insertion operator allows us to display. 
 ********************************/
template <class T>
std::ostream& operator <<(std::ostream& out,  const BinaryNode<T> * tmp)
{
   if (tmp == NULL)
      return out;
   return out << tmp->pLeft << tmp->data  << ' ' << ((tmp->isRed)? 'R' : 'B')
              << ' ' << tmp->pRight;
}

/**************************************
 * Function definition of our first addLeft
 *************************************/
template <class T>
void BinaryNode<T> :: addLeft(const T & data)
{
   //if I don't already have a left child
   if (this->pLeft == NULL)
   {
      BinaryNode<T> * left = new  BinaryNode<T>;
      left->data = data;
      this->pLeft = left;
      left->pParent = this;
   }
   //go down to that next left node
   else
      this->pLeft->addLeft(data);
   //balance that new node after we have inserted
   pLeft->balance();  
}

/****************************************
 * second definition of addLeft
 ***************************************/
template <class T>
void BinaryNode<T> :: addLeft(BinaryNode<T> * left)
{
   //if I don't already have a left child
   if (this->pLeft == NULL)
   {
      this->pLeft = left;
      left->pParent = this;
   }
   //go down to that next left node
   else
      this->pLeft->addLeft(left);
}

/**********************************
 * first definition of addRight
 ********************************/
template <class T>
void BinaryNode<T> :: addRight(const T & data)
{
   //if I don't already have a right child
   if (pRight == NULL)
   {
      BinaryNode<T> * right = new BinaryNode<T>;
      right->data = data;
      this->pRight = right;
      right->pParent = this;
      
   }
   //go down to that next right node
   else
      this->pRight->addRight(data);
   //balance that new node after we have inserted
   pRight->balance();
}

/****************************************
 * Second definition of addRight
 ************************************/
template <class T>
void BinaryNode<T> :: addRight(BinaryNode<T> * right)
{
   //if I don't already have a right child
   if (pRight == NULL)
   {
      this->pRight = right;
      right->pParent = this;
   }
   //go down to that next right node
   else
      this->pRight->addRight(right);
}

/********************************************
 * function definition of deleteBinaryTree allowing us
 * to delete a binary tree we have created. 
 ******************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> * & root)
{
   if (root == NULL)
      return;
   deleteBinaryTree(root->pLeft);
   deleteBinaryTree(root->pRight);
   delete root;
   root = NULL; //needed this to get rid of last node
}


/********************************************
 * starting at the root, deep copies the tree.
 *********************************************/
template<class T>
void BinaryNode<T> :: copyBinaryTree(const BinaryNode<T> * pSrc,
                                     BinaryNode<T> * & pDest)
throw (const char *)
{
   //create node to be able to iterate through source
   BinaryNode<T> * p = NULL;

   try
   {
      //if I am the root
      if (pSrc->pParent == NULL)
      {
         p = new BinaryNode<T>(pSrc->data);
         p->isRed = pSrc->isRed;
         pDest = p;
      }
      //if I have a right child, copy data to destination
      if (pSrc->pRight)
      {
         p = new BinaryNode<T>(pSrc->pRight->data);
         p->isRed = pSrc->pRight->isRed;
         pDest->addRight(p);
         copyBinaryTree(pSrc->pRight, pDest->pRight);
      }
      //if I have a left child, copy data to destination
      if (pSrc->pLeft)
      {
         p = new BinaryNode<T>(pSrc->pLeft->data);
         p->isRed = pSrc->pLeft->isRed;
         pDest->addLeft(p);
         copyBinaryTree(pSrc->pLeft, pDest->pLeft);
      }
   }
   catch(...)
   {
      throw "ERROR!!!!";
   }
}

#endif //BNODE_H
