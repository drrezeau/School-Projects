/***********************************************************************
* Program:
*    Assignment 09, Tax Bracket          (e.g. Assignment 01, Hello World)  
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       this program will allow the user to input their income, and
*       will tell them how much
*       percent of their income their taxes will be.
*
*    Estimated:  0.4 hrs   
*    Actual:     0.25 hrs
*      forgetting to use the && symbols.
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* this function will tell main what tax bracket the person is in.
**********************************************************************/
int computetax(float income)
{
   if (income < 15100)
      return 10;
   if (15100 <= income && income < 61300)
      return 15;
   if (61300 <= income && income < 123700)
      return 25;
   if (123700 <= income && income < 188450)
      return 28;
   if (188450 <= income && income < 336550)
      return 33;
   if (336550 <= income)
      return 35;
}




/**********************************************************************
* this will start the main program, calling the function computetax
* which will return a value telling the user their tax bracket.
***********************************************************************/
int main()
{
   float income;
   cout << "Income: ";
   cin >> income;

   int taxbracket = computetax(income);
   cout << "Your tax bracket is " << taxbracket << "%\n";
   
   
   return 0;
}
