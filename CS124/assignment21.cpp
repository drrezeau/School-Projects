/***********************************************************************
* Program:
*    Assignment 21, Count Spaces 
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will ask the user for a sting of text and then will
*       count the number of spaces.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.15 hrs
*       the hardest part was having my brain think it was a file.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************
 * this function counts the number of spaces in the string
 *********************************************/
int countSpaces(char text[], int count)
{
   for (int i = 0; i < 256; i++)
      if (text[i] == ' ')
         count++;
   return count;
}

/**********************************************************************
* this function asks the user for text and then calls countSpaces and displays
* how many spaces there are.
***********************************************************************/
int main()
{
   char text[256];
   int count = 0;
   cout << "Enter text: ";
   cin.getline(text, 256);
   count = countSpaces(text, count);
   cout << "Number of spaces: " << count << endl;
   return 0;
}
