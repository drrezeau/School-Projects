/***********************************************************************
* Program:
*    Assignment 10, Compute Tax          (e.g. Assignment 01, Hello World)  
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       this program will allow the user to input their income, and
*       will tell them how much
*       tax they will need to pay
*
*    Estimated:  0.4 hrs   
*    Actual:     0.5 hrs
*      forgetting to minus the first amount.
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* this function will tell main what tax the person has to pay.
**********************************************************************/
float computetax(float income)
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




/**********************************************************************
* this will start the main program, calling the function computetax
* which will return a value telling the user their amount of tax to pay.
***********************************************************************/
int main()
{
   float income;
   cout << "Income: ";
   cin >> income;

   float tax = computetax(income);
   cout << "Your tax is $" << tax << endl;
   
   
   return 0;
}
