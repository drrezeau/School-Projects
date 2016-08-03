/***********************************************************************
 * Module:
 *    Lesson 10, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{

   int iWall = 1; //start at one because the first item
                  //in the array is already sorted
   //shift iWall after we insert
   for(iWall; iWall < num; iWall++)
   {
      T data = array[iWall]; //save data in item we want to insert
      int spot = binarySearch(array, iWall, data);
      int i;
      //loop through to shift the data until we want to insert
      for(i = iWall; i > spot; --i)
         array[i] = array[i - 1];
      array[i] = data;  //shift the data
   }
}

/*****************************************************
 * Binary Search
 * This finds the correct position where the data
 * should be inserted.
 *****************************************************/
template <class T>
int binarySearch(const T array[], int size, const T & data)
{
   int iFirst = 0;
   int iLast = size - 1;
   int iMiddle;

   //while the last index is not less than the first index
   while(iLast >= iFirst)
   {
      //for binary search to start at middle for
      //log n find rather than linear find
      iMiddle = (iLast + iFirst) / 2;

      //if the data of iMiddle is greater than data
      //then our position must be before the iMiddle
      if(array[iMiddle] > data)
         iLast = iMiddle - 1;
      //else our position needs to be after iMiddle 
      else
         iFirst = iMiddle + 1;
   }
   //return iFirst because it will be where the position
   //needs to be
   return iFirst;
}


#endif // SORT_INSERTION_H
