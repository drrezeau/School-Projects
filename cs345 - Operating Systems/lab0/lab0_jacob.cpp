/***********************************************************************
* Program:
*    Lab 00, Practice submit          
*    Brother Jones, CS345
* Author:
*    Jacob Bowser
* Summary: 
*    This program will prompt the user for a number then it
*    will output the number of numbers that were input by the
*    user before they input a '0'.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The main function will prompt the user for a number then it
 * will output the number of numbers that were input
 * by the user before they input a '0'.
  ***********************************************************************/
int main()
{
   int input;           
   int i = 0;

   //start a loop
   do
   {
      //continue entering integers until 0 is entered
      cout << "Enter an integer: "; 
      cin >> input;

      //if 0 is entered do not increase the counter
      if(input != 0)
         i++;
   }while(input != 0);

   //if there are more than one integer entered use a plural
   if(i > 1)
      cout << "You entered " << i << " integers.\n";
   //otherwise use a singular
   else if (i == 1)
      cout << "You entered " << i << " integer.\n";
   //use this prompt if no integers were entered
   else
      cout << "No non-zero integers were entered.\n";
   
   return 0;
}
