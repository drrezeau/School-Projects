/***********************************************************************
 * Module:
 *    Lesson 10, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins (using code from textbook)
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
   quickSort(array, 0, num - 1);
}

/****************************************************
 * Split Function
 * This function separates and swaps the values based
 * on the pivot.
 ****************************************************/
template <class T>
int split(T array[], const int & iLeft, const int & iRight)
{
   //set pivot to value of iLeft
   T pivot = array[iLeft];
   //start at index of left
   int left = iLeft;
   //start at index of right
   int right = iRight;

   //loop while the indexes are not equal
   while(right > left)
   {
      //until we find a value less than or equal to pivot
      while(array[right] > pivot)
         right--;

      //until we find a value more than pivot
      while((right > left) &&
            (pivot > array[left] || pivot == array[left]))
         left++;

      //if the indexes haven't meet yet
      if(right > left)
      {
         //swap left and right values compared to pivot
         T data = array[left];
         array[left] = array[right];
         array[right] = data;
      }
   }
   int position = right;           //creates position that is right index
   array[iLeft] = array[position]; //assigns data in left index to
                                   //data in position
   array[position] = pivot;        //assigns data in position to pivot
   return position;                //return position index
}

/*******************************************
 * Recursive Quick Sort
 * This function sets the position as the new pivot
 * and changes the range of values we compare by one
 * for each recursive function call.
 *******************************************/
template <class T>
void quickSort(T array[], const int & iLeft, const int & iRight)
{
   int position;
   //while index of right is less than index of left
   if(iRight > iLeft)
   {
      //set position as new pivot
      position = split(array, iLeft, iRight);
      //moves iRight to position minus one
      quickSort(array, iLeft, position - 1);
      //moves iLeft to position plus one
      quickSort(array, position + 1, iRight);
   }
}
#endif // SORT_QUICK_H
