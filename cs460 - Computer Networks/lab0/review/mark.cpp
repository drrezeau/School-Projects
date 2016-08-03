/***********************************************************************
* Program:
*    Lab 00, First Lab
*    Brother Jones, CS460
* Author:
*    Mark Soules
* Summary: 
*    The C++ program that you are to submit is to count the number of 
*    strings entered by the user at the command line that have the first 
*    letter of the first word capitalized before a blank 
*    line is entered by the user.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***********************************************************************
* Counts the number of strings with first capital letters.
************************************************************************/
int main()
{
  string userInput;
  int count = 0;
  
  do 
    {
      cout << "Enter a string: ";
      getline(cin, userInput);
      if (isupper(userInput[0])) 
	{
	  count++;
	}
    }
  while (userInput != "");
  
  if (count == 0)
    {
      cout << "No strings starting with an upper case letter were seen.\n";
    }
  else if (count == 1)
    {
      cout << "One string starting with an upper case letter was seen.\n";
    }
  else 
    {
      cout << "You entered " << count 
	   << " strings that started " 
	   << "with an upper case letter.\n";
    }
  return 0;
}

