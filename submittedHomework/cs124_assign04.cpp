/***********************************************************************
* Program:
*    Assignment 04, Display Budget          (e.g. Assignment 01, Hello World)  
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*     This program will display the budget given to us and the outcome.
*
*
*    Estimated:  0.3 hrs   
*    Actual:     0.25 hrs
*      figuring out how to get everything aligned the same.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* This program will display a budget.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "\tItem           Projected" << endl;
   cout << "\t=============  ==========" << endl;
   cout << "\tIncome         $  " << "1000.00" << endl;
   cout << "\tTaxes          $   " << "100.00" << endl;
   cout << "\tTithing        $   " << "100.00" << endl;
   cout << "\tLiving         $   " << "650.00" << endl;
   cout << "\tOther          $    " << "90.00" << endl;
   cout << "\t=============  ==========" << endl;
   cout << "\tDelta          $    " << 60.00 << endl;

   return 0;
}
