/********************************************************
* Program:
*    Test 1, Child Tax Credit
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will allow the user to input how many children
*       under 17 that they have and then ask for the income and finally
*       will calculate their child tax credit.
****************************************************/
#include <iostream>
using namespace std;

/****************************************************
 * this will ask the user to input how many children
 ***************************************************/
int numbChildren()
{
   int children;
   cout << "How many children: ";
   cin >> children;

   return children;
}

/**************************************************
 * this function asks the user for their income 
 *************************************************/
int getIncome()
{
   int income;
   cout << "What is your income: ";
   cin >> income;

   return income;
}

/***************************************************
 * this will display what child tax credit you have
 **************************************************/
void taxcredit(int income, int children)
{
   if (income <= 110000)
      cout << "\tYour child tax credit is $" << (children * 1000) << endl;
   else
      cout << "\tYour child tax credit is $0\n";

   return;
}

/**************************************************************
 * this will execute the program calling to the other functions
 *************************************************************/
int main()
{
   int children = numbChildren();
   int income = getIncome();

   taxcredit(income, children);

   return 0;
}
