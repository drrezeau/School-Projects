/***********************************************************************
* Program:
*    test 4, String Copy       
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*   this program will prompt the user for a string and then
*   will copy it and display the copy.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*      getting the string to copy
************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/****************************************
 * this function will copy a c-string
 ****************************************/
char *stringCopy(char *destination, char *source)
{
//   strcpy(destination, source);
   destination = source;
   return destination;
}

/**********************************************************************
* this function will prompt the user for a string and call stringCopy
* and then display the copied string.
***********************************************************************/
int main()
{
   char *destination;
   char *source = NULL;
   char text[256];
   
   cout << "Please enter a string: ";
   cin.getline(text, 256);
   for (int i = 0; text[i]; i++)
      source = &text[i];
   
   cout << "The string is: ";
   for (destination = stringCopy(destination, source);
        *destination; destination++)
      cout << destination << endl;
   
   return 0;
}
