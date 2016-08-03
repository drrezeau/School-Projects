/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS460
* Author:
*    James Meldrum
* Summary: 
*    This program counts the number of strings that begin with uppercase
*  Letters
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
*  Function to determine if a string starts with an uppercase letter
************************************************************************/
bool doesStartUppercase(const string& value)
{
   string::const_iterator it = value.begin();
   
   return isupper (*it);
}

/**********************************************************************
 * This is the driver for the program and will run the whole algorithm
 ***********************************************************************/
int main()
{
   string userInput;
   int count = 0;
   do
   {
      cout << "Enter a string: ";
      getline(cin, userInput);
      if (doesStartUppercase(userInput) && userInput != "")
      {
         ++count;
      }
   } while (userInput != "");
   switch (count)
   {
      case 0:
         cout << "No strings starting with an upper case letter were seen.\n";
         break;
      case 1:
         cout << "One string starting with an upper case letter was seen.\n";
         break;
      default:
         cout << "You entered " 
              << count
              << " strings that started with an upper case letter.\n";
         break;
   }   
   
   return 0;
}