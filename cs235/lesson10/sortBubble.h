/***********************************************************************
 * Module:
 *    Lesson 10, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{
   T data;
   int numComp = num - 1; //to know how many times we have swapped
   //go until i have moved my last item or we don't need to swap
   while(numComp)
   {
      int last = 0; //to check if we have swapped
      //loop until we reach the end of the unsorted items
      for(int i = 0; i < numComp; ++i)
      {
         //if the current spot's item is greater than
         //the next spot's item, switch the two.
         if(array[i] > array[i + 1]) 
         {
            //swap items
            data = array[i];
            array[i] = array[i + 1];
            array[i + 1] = data;
            //if we swapped we change last to i
            last = i;
         }
      }
      //we go until we have reached the last swapped item
      numComp = last;
   }
}


#endif // SORT_BUBBLE_H
