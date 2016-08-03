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

   //Default Constructor
  BinaryNode() :pLeft(NULL), pRight(NULL), pParent(NULL) {}
   
   //Non-Default Constructor
  BinaryNode(T data) : data(data), pLeft(NULL), pRight(NULL),pParent(NULL) {}

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

};

/*********************************
 * overloaded insertion operator allows us to display. 
 ********************************/
template <class T>
std::ostream& operator <<(std::ostream& out,  const BinaryNode<T> * tmp)
{
   if (tmp == NULL)
      return out;
   return out << tmp->pLeft << tmp->data << ' ' << tmp->pRight;
}

/**************************************
 * Function definition of our first addLeft
 *************************************/
template <class T>
void BinaryNode<T> :: addLeft(const T & data)
{
   if (this->pLeft == NULL)
   {
      BinaryNode<T> * left = new  BinaryNode<T>;
      left->data = data;
      this->pLeft = left;
      left->pParent = this;
   }
   else
      this->pLeft->addLeft(data);
}

/****************************************
 * second definition of addLeft
 ***************************************/
template <class T>
void BinaryNode<T> :: addLeft(BinaryNode<T> * left)
{
   if (this->pLeft != NULL)
      this->pLeft->addLeft(left);
   else
   {
      this->pLeft = left;
      left->pParent = this;
   }
}

/**********************************
 * first definition of addRight
 ********************************/
template <class T>
void BinaryNode<T> :: addRight(const T & data)
{

   if (pRight == NULL)
   {
      BinaryNode<T> * right = new BinaryNode<T>;
      right->data = data;
      this->pRight = right;
      right->pParent = this;
   }
   else
      this->pRight->addRight(data);
}

/****************************************
 * Second definition of addRight
 ************************************/
template <class T>
void BinaryNode<T> :: addRight(BinaryNode<T> * right)
{
   if (this->pRight != NULL)
      this->pRight->addRight(right);
   else
   {
      this->pRight = right;
      right->pParent = this;
   }
}

/********************************************
 * function definition of deleteBinaryTree allowing us
 * to delete a binary tree we have created. 
 ******************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> * root)
{
   if (root == NULL)
      return;
   deleteBinaryTree(root->pLeft);
   deleteBinaryTree(root->pRight);
   delete root;
}


#endif //BNODE_H
