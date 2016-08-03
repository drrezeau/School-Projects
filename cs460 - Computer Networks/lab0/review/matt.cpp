/***********************************************************************                              
 * Program:                                                                                            
 *    Lab 00, Practice Lab Submission                                                                  
 *    Brother Jones, CS460                                                                             
 * Author:                                                                                             
 *    Matthew Hansen                                                                                   
 * Summary:                                                                                            
 *    This program inputs multiple strings and counts the number of                                    
 *    strings that have the first character of the first word capitalized.                             
 ************************************************************************/
#include <iostream> //For cout and getline(cin, string)                                               
#include <cctype> // For isupper()                                                                    
#include <sstream> //For ostringstream's .str() function                                              
using namespace std;

/**********************************************************************                               
 * main()                                                                                             
 * Description:                                                                                       
 *      main() prompts the user for strings until the user hits enter                                 
 *      (which inputs a blank string). While main is receiving strings,                               
 *      it checks to see if the first character of the first word is                                  
 *      capitalized. If it is, then it increments the counter,                                        
 *      otherwise it doesn't.                                                                         
 * Inputs:                                                                                            
 *      int argc - Number of command line arguments.                                                  
 *      char** argv - Command line arguments                                                          
 * Outputs:                                                                                           
 *      int errorcode - Always returns 0                                                              
 ***********************************************************************/
int main(int argc, char** argv)
{
  //Variables                                                                                        
  int stringsWithFirstLetterInFirstWordCapitalized = 0;
  string finalMessage = "";
  ostringstream convert;
  string input = "empty";

  //Receive input                                                                                    
  while (input != "")
    {
      input.clear();
      cout << "Enter a string: ";
      getline(cin, input);
      if (isupper(input[0]))
	++stringsWithFirstLetterInFirstWordCapitalized;
    }

  //Format output                                                                                    
  switch (stringsWithFirstLetterInFirstWordCapitalized)
    {
    case(0):
         finalMessage =
	   "No strings starting with an upper case letter were seen.";
         break;
    case(1):
         finalMessage =
	   "One string starting with an upper case letter was seen.";
         break;
    default:
      convert << stringsWithFirstLetterInFirstWordCapitalized;
      finalMessage = "You entered " + convert.str()
	+ " strings that started with an upper case letter.";
      break;
    }

  //Print output                                                                                     
  cout << finalMessage << endl;

  return 0;
}