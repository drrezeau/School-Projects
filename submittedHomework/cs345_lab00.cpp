/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS345
* Author:
*    David Lambertson
* Summary: 
*    This program will count how many times the user inputs a non-zero integer.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Will ask the user for a number and check if given number is not 0.
 * Will keep counting until the user inputs the number 0. Then it displays
 * the number of non-zero numbers.
 ***********************************************************************/
int main()
{
   int number; //user-inputted number
   int count = 0; //variable to keep track of non-zero #s entered
   
   /*
     DO
     ask for a number and get number
     WHILE number != 0
    */
   do
   {
      cout << "Enter an integer: ";
      cin >> number;
      if (number != 0)
         count++;

   } while (number != 0);

   //IF count IS GREATER THAN 0
   //display how many we counted
   if (count > 0)
   {
      //case handling singular and plural
      if (count == 1)
         cout << "You entered " << count << " integer.\n";
      else
         cout << "You entered " << count << " integers.\n";
   }
   else
      cout << "No non-zero integers were entered.\n";
   return 0;
}

