/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS345
* Author:
*    Benjamin Walker
* Summary: 
*    This Lab 0 will continue to prompt for numbers until 0 is entered.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
 * Continue to prompt for numbers till '0' is entered by the user
 ***********************************************************************/
int main()
{
   int num;
   // this is my way of subtracting 1 for the '0' at the end
   int count = -1; 
   do {
      cout << "Enter an integer: ";
      cin >> num;
      count++;
      assert(count >= 0);
   } while (num != 0);

   switch (count)
   {
      case 0:
         cout << "No non-zero integers were entered.\n";
            break;
      case 1:
         cout << "You entered 1 integer.\n";
         break;
      default:
         cout << "You entered " << count << " integers.\n";
         break;
   }

   return 0;
}

