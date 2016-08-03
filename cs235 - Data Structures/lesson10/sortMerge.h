/***********************************************************************
 * Module:
 *    Lesson 10, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins and David Lambertson
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   int arrayNum = 0, array1Num = 0;
   T array1[num];
   int i = 0;
   int numMerges = 1;
   
   //while we keep merging execute this code
   while(numMerges)
   {
      numMerges = 0;
      merge(array, array1, arrayNum, array1Num, num, numMerges);

      arrayNum = 0;
      array1Num = 0;
      //save into the actual array
      for (int m = 0; m < num; ++m)
         array[m] = array1[m];
   }

}

/***********************************************************
 * This takes us through the array, finding the subarrays
 * and merges two subarrays and continues until the end of
 * the full array.
 *********************************************************/
template <class T>
void merge(T array[], T array1[], int arrayNum, int array1Num, const int & num, int & numMerges)
{
   int iStart = 0, iEnd=0, jStart=0, jEnd=0;
   
   //find the first sub array
   iStart = arrayNum;
   for(; arrayNum < num; ++arrayNum)
   {
      //when we found the end of the first sub array
      if(array[arrayNum] > array[arrayNum + 1])
      {
         iEnd = arrayNum;
         break;
      }
   }
   
   //when we reached the end of the array
   if (arrayNum == num)
      iEnd = arrayNum-1;
   ++arrayNum;

   //find the second sub array
   jStart = arrayNum;
   for(; arrayNum < num; ++arrayNum)
   {
      //when we found the end of the second sub array
      if(array[arrayNum] > array[arrayNum + 1])
      {
         jEnd = arrayNum;
         break;
      }
   }

   //when we reached the end of the array 
   if (arrayNum == num)
      jEnd = arrayNum-1;
   
   ++arrayNum;

   //if there only one more sub array rather than two
   if(iEnd == num-1)
      for (; iStart < num; ++iStart)
         array1[iStart] = array[iStart];

   //since we have reached the end, kick out 
   if (arrayNum > num)
      return;

   for (; array1Num <= jEnd; ++array1Num)
   {
      if (iEnd < iStart) //end of i sublist
      {
         array1[array1Num] = array[jStart];
         jStart++;
      }
      else if (jEnd < jStart) //end of array1Num sublist
      {
         array1[array1Num] = array[iStart];
         iStart++;
      }
      // if item in array1Num sublist is less than arrayNum
      else if (array[iStart] > array[jStart]) 
      {
         array1[array1Num]= array[jStart];
         jStart++;
      }
      //if item in array1Num sublist is more than arrayNum
      else 
      {
         array1[array1Num] = array[iStart];
         iStart++;
      }
   }
   
   merge(array, array1, arrayNum, array1Num, num, numMerges);
   numMerges++;
   
}

#endif // SORT_MERGE_H
