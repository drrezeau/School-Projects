/***********************************************************************
* Program:
*    Assignment 26, Feet to Meters  
*    Brother Helfrich, CS124
* Author:
*    DAvid Lambertson
* Summary: 
*    This program will use the command line to get the input.
*
*    Estimated:  0.3 hrs   
*    Actual:     1.15 hrs
*      converting the string to float or double
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* this function will display the feet to meters conversion of the input
***********************************************************************/
int main(int countArguments, char *listArguments[])
{
   float list[256];
   cout.precision(1);
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   for (int iarg = 1; iarg < countArguments; iarg++)
   {
      list[iarg] = atof( listArguments[iarg] );
      cout << (float)list[iarg] << " feet is "
           << (list[iarg] * 0.3048) << " meters" << endl;
   }
   return 0;
}
