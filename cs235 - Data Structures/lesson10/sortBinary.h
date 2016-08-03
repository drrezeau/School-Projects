/***********************************************************************
 * Module:
 *    Lesson 10, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>
#include <iostream>

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   //create the binary search tree
   BST<T> tree; 

   //insert everything into the tree
   for (int i = 0; i < num; i++) 
   {
      tree.insert(array[i]);
   }
   
   int i = 0;

   //insert the sorted tree back into the array using infix order.
   for (BSTIterator<T> it = tree.begin(); it != tree.end(); ++it, i++)
   {
      array[i] = *it;
   }
}


#endif // SORT_BINARY_H
