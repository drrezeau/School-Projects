/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS460
* Author:
*    David Lambertson
* Summary: 
*   Upper case Checker - this program checks a string entered by a user
*   to see if it begins with an upper case letter. At the end, it displays
*   how many the program found.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * This is a simple program that asks the user for strings. If the string
 * begins with a upper case letter, the program increments numOfStrings.
 * At the end, the program displays how many strings were entered that
 * began with an upper case letter.
 ***********************************************************************/
int main()
{
   int numOfStrings = 0;
   string enteredString;
   
   do
   {
      cout << "Enter a string: ";
      getline(cin, enteredString);
      
      if (isupper(enteredString[0])) 
      {
         numOfStrings++;
      }
   }
   while (enteredString != "");
   
   if (!numOfStrings) 
   {
      cout << "No strings starting with an upper case letter were seen.\n";
   }
   else if (numOfStrings == 1) 
   {
      cout << "One string starting with an upper case letter was seen.\n";
   }
   else
   {
      cout << "You entered " << numOfStrings << " strings that started with"
           << " an upper case letter.\n";
   }
   
   return 0;
}

