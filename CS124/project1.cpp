/***********************************************************************
* Program:
*    Project 1, Personal Finance
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       this program will allow the use to input their income, projected
*       living, actual living, actual taxes, actual tithe due, and actual other
*       and then will use those to compute projected other, projected tax,
*       projected tithe and the delta and then will take all that information
*       and display it neatly on the screen.
*
*    Estimated:  4.0 hrs   
*    Actual:     3.75 hrs
*      writing out all the different functions
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * this part of the program will ask for the income
 ***********************************************************************/
float getIncome()
{
   float income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/******************************************************************
* this part will ask for projected living
*****************************************************************/
float getProjectedLiving()
{
   float projectedLiving;
   cout << "\tYour projected living expenses: ";
   cin >> projectedLiving;
   return projectedLiving;
}

/***************************************************************
* this part of the program will get actual living
***************************************************************/
float getActualLiving()
{
   float actualLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/******************************************************************
* this part of the program will get the actual taxes
*****************************************************************/
float getActualTaxes()
{
   float actualTaxes;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   return actualTaxes;
}

/**************************************************************
* this part of the program will get the actual tithing
*************************************************************/
float getActualTithing()
{
   float actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/*************************************************************
* this part of the program will get the actual other
************************************************************/
float getActualOther()
{
   float actualOther;
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/*******************************************************
* this program will compute the projected tax using income
*******************************************************/
float computeTax(float income)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float yearlyincome = income * 12;
   
   if (yearlyincome < 15100)
      return (yearlyincome * .10) / 12.0;
   if (15100 <= yearlyincome && yearlyincome < 61300)
      return (1510.00 + ((yearlyincome - 15100) * .15)) / 12.0;
   if (61300 <= yearlyincome && yearlyincome < 123700)
      return (8440.00 + ((yearlyincome - 61300) * .25)) / 12.0;
   if (123700 <= yearlyincome && yearlyincome < 188450)
      return (24040.00 + ((yearlyincome - 123700) * .28)) / 12.0;
   if (188450 <= yearlyincome && yearlyincome < 336550)
      return (42170.00 + ((yearlyincome - 188450) * .33)) / 12.0;
   if (336550 <= yearlyincome)
      return (91043.00 + ((yearlyincome - 336550) * .35)) / 12.0;
}

/***********************************************************
* this function will compute the minimum amount of tithe due
***********************************************************/
float computeTithe(float income)
{
   float tithing = income * 0.1;

   return tithing;
}

/******************************************************************
 * this function will use variables to compute the other amount spent
 *****************************************************************/
float computeOther(float income, float projectedTax, float projectedTithing,
                   float projectedLiving)
{
   float projectedOther = income - projectedTax - projectedTithing
      - projectedLiving;
   return projectedOther;
}

/******************************************************************
* this part will be displaying everything and will be called in main
*****************************************************************/
void display(float income, float projectedLiving, float actualLiving,
             float actualTaxes, float actualTithing, float actualOther)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float projectedTax = computeTax(income);
   float projectedTithing = computeTithe(income);
   float projectedOther = computeOther(income, projectedLiving,
                                       projectedTax,
                                       projectedTithing);
   float actualDelta = income - actualLiving - actualTaxes
      - actualTithing - actualOther;
   
   cout << endl;
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem            Projected       Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(10) << income << "     $" << setw(14)
        << income << endl;
   cout << "\tTaxes           $" << setw(10) << projectedTax << "     $"
        << setw(14) << actualTaxes << endl;
   cout << "\tTithing         $" << setw(10) << projectedTithing << "     $"
        << setw(14) << actualTithing << endl;
   cout << "\tLiving          $" << setw(10) << projectedLiving << "     $"
        << setw(14) << actualLiving << endl;
   cout << "\tOther           $" << setw(10) << projectedOther << "     $"
        << setw(14) << actualOther << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDelta           $" << setw(10) << 0.00 << "     $"
        << setw(14) << actualDelta << endl;
}


/******************************************************************
* this part will take everything, and compute personal finance
*****************************************************************/
int main()
{
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:" << endl;
      
   float income;
   float projectedLiving;
   float actualLiving;
   float actualTaxes;
   float actualTithing;
   float actualOther;
   

   income = getIncome();
   projectedLiving = getProjectedLiving();
   actualLiving = getActualLiving();
   actualTaxes = getActualTaxes();
   actualTithing = getActualTithing();
   actualOther = getActualOther();

   display(income, projectedLiving, actualLiving, actualTaxes,
           actualTithing, actualOther);
   
   return 0;
}
