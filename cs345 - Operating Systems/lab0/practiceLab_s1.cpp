/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS345
* Author:
*    Shane Jensen
* Summary: 
*    Counts the number of nonzero integers entered on stdin.
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************
 * Reads in integers from stdin and exits when a zero is entered.
 * Prints the number of nonzero integers that were entered on exit.
 ***********************************************************************/
int main()
{
   int num;
   vector<int> numbers;
   cout << "Enter an integer: ";
   while (cin >> num)
   {
      if (num == 0)
      {
         break;
      }
      numbers.push_back(num);
      cout << "Enter an integer: ";
   }
   switch (numbers.size())
   {
      case 0:
         cout << "No non-zero integers were entered.\n";
         break;
      case 1:
         cout << "You entered 1 integer.\n";
         break;
      default:
         cout << "You entered " << numbers.size() << " integers.\n";
   }
   return 0;
}

