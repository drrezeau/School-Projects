/***********************************************************************
* Program:
*    Assignment 27, Search Speed
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    This program compares the search speed of the linear search
*    and the binary search.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.2 hrs
*      understanding how the intial program worked.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int readNumbers(int numbers[], int max);
float computeAverageLinear(int numbers[], int size);
float computeAverageBinary(int numbers[], int size);
int linear(int numbers[], int size, int search);
int binary(int numbers[], int size, int search);

/**********************************************************************
* main reads the list, determines the speed of the searches, and outputs
* the results.
***********************************************************************/
int main()
{
   int numbers[1024];
   const int MAX = sizeof (numbers) / sizeof (numbers[0]);
   int size;

   // read the numbers
   if (!(size = readNumbers(numbers, MAX)))
      return 1;

   // determine how long it takes for a linear search
   float averageLinear;
   averageLinear = computeAverageLinear(numbers, size);

   // determine how long it takes for a binary search
   float averageBinary;
   averageBinary = computeAverageBinary(numbers, size);

   // display results
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Linear search: " << setw(10) << averageLinear << endl;
   cout << "Binary search: " << setw(10) << averageBinary << endl;

   return 0;
}

/************************************************************
 * READ NUMBERS
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 * Output:
 *    size:    The number of items actually read
 ***********************************************************/
int readNumbers(int numbers[], int max)
{
   char fileName[256];
   int  size = 0;

   // get the filename
   cout << "Enter filename of list: ";
   cin  >> fileName;

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return 0;
   }

   // read the file
   while (!fin.eof() && size < max)
      fin >> numbers[size++ ];

   // make like a tree
   fin.close();
   return size;
}

/*********************************************************
 * COMPUTE AVERAGE LINEAR
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 * Output:
 *    averageLinear: the average number of comparisons it takes
 *                   to find each item in the array
 *******************************************************/
float computeAverageLinear(int numbers[], int size)
{
   float averageLinear = 0.0;

   // put your code here, probably including a collections of
   // calls to linear()
   int search = 0;
   for (int i = 0; i < size; i++)
   {
      search = numbers[i];
      averageLinear = (averageLinear + (linear(numbers, size, search)));
   }
   return averageLinear / size;
}

/*********************************************************
 * COMPUTE AVERAGE BINARY
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 * Output:
 *    averageBinary: the average number of comparisons it takes
 *                   to find each item in the array
 *******************************************************/
float computeAverageBinary(int numbers[], int size)
{
   float averageBinary = 0.0;

   // put your code here, probably including a collections of
   // calls to binary()
   int search = 0;
   for (int i = 0; i < size; i++)
   {
      search = numbers[i];
      averageBinary = (averageBinary + binary(numbers, size, search));
   }

   return averageBinary / size;
}

/*******************************************************
 * LINEAR
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 *    search:  the number that you are searching for
 * Output:
 *    compares: the number of compares that were made
 *              before 'search' was found in the 'numbers' array
 ******************************************************/
int linear(int numbers[], int size, int search)
{
   bool found = false;
   int  compares = 0;  // you will need to compute this

   for (int i = 0; i < size && ! found; i++)
   {
      compares++;
      if (search == numbers[i])
         found = true;
   }

   return compares;
}

/*******************************************************
 * BINARY
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 *    search:  the number that you are searching for
 * Output:
 *    compares: the number of compares that were made
 *              before 'search' was found in the 'numbers' array
 ******************************************************/
int binary(int numbers[], int size, int search)
{
   bool found = false;
   int  compares = 0;  // you will need to compute this

   // set the bounds of the search space, initially the whole list
   int iFirst = 0;
   int iLast = size - 1;

   // continue until found or the search size is not zero
   while (iLast >= iFirst && !found)
   {
      int iMiddle = (iLast + iFirst) / 2;
      compares++;

      // note that both the == and > count as one comparison
      if (numbers[iMiddle] == search)
         found = true;
      else if (numbers[iMiddle] > search)
         iLast = iMiddle - 1;
      else
         iFirst = iMiddle + 1;
   }

   return compares;
}
