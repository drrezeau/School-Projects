/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author:
 *    Derek Calkins
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/**********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   Node <T> * pHead = NULL;           //initialize pHead
   Node <T> * pNew = new Node <T>;    //create a new Node
   insert(array[0], pHead, true);     //put first item into list

   //loops through the array and puts them into a
   //list of Nodes. 
   for (int i = 1; i < num; i++)
   {
      pNew = compare(pHead, array[i]); //moves pNew pointer to compare function
      if (pNew == NULL)                //checks if pNew is NULL
         insert(array[i], pHead, true);//insert to head
      else       
         insert(array[i], pNew);       //insert after pNew pointer
   }


   //This loops to read back the Nodes into the array
   int j;
   Node <T> * p;
   for (p = pHead, j = 0; p; p = p -> pNext, j++)
   {
      array[j] = p->data;              //assigns elements from list to array
   }   
}

/****************************************
 * COMPARE
 * This function was to take the Node compare
 * the data in pHead to the data from the array
 * and return the pointer to the Node before where
 * we want to insert.
 ****************************************/
template <class T>
Node<T> * compare(Node <T> * & pHead, T value)
{
   Node <T> * pFound = NULL;           //initailize pFound
   for (Node <T> * p = pHead; p; p = p->pNext)
   {    
      if(p->data < value)              //if value is greater than the Node
         pFound = p;                   //pFound is assigned to that Node
      else                             //else break from loop
         break; 
   }
   return pFound;                      //return position of Node for insert
}

#endif // INSERTION_SORT_H

