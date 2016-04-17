/***********************************************************************
* Program:
*    Assignment 06, Prompt for Income       (e.g. Assignment 01, Hello World)  
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*   This program will allow you to input your income, and it will display what
*   your income is
*
*    Estimated:  0.3 hrs   
*    Actual:     0.4 hrs
*      Could not get the Get Income function to return the income ammount 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* This program will display your income after you have inputted it. 
************************************************************************/

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double Income;

   cout << "\tYour monthly income: ";
   cin >> Income;
    
 
   cout << "Your income is: $" << setw(9) << Income << endl;

   return 0;
}
