/***********************************************************************
* Program:
*    Assignment 08, Full Tithe Payer
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.2 hrs   
*    Actual:     0.25 hrs
*      the hardest part was that my PuTTY stopped working before i could
*      finish the program
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 *this part will pull the income and tithe and use it to tell
 * if the person is full tithe payer or not
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{
   if (  ((income * 0.1) <= tithe)) 

      return true;

   else
      return false;
}


/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}
