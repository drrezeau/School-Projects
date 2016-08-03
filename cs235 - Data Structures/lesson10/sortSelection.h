/***********************************************************************
 * Module:
 *    Lesson 10, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
   //for the entire array
   for (int i = 0; i < num-1; i++)
   {
      int smallPost = i; //position of the smallest item
      T smallest = array[i];// the actual smallest item
      for (int j = i + 1; j < num; j++)
      {
         if (!(array[j] > smallest)) //if I find something smaller, save it
         {
            smallPost = j;
            smallest = array[j];
         }
      }
      
      //switch the position i, with the smallest
      T temp = array[i];
      array[i] = smallest;
      array[smallPost] = temp;
      
   }
}


#endif // SORT_SELECTION_H
