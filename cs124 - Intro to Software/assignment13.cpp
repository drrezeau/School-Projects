/***********************************************************************
* Program:
*    Assignment 13, Days Since 1753   
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    this program will take the year the user inputs and will display how many
*    days it has been since that year.
*
*    Estimated:  0.4 hrs   
*    Actual:     2.5 hrs
*      trying to get the right number when input is a leap year
************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************
* this will figure out if year is leap year or not
******************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 != 0)
      return false;
   else  if (year % 100 != 0)
      return true;
   else if (year % 400 == 0)
      return true;
   else
      return false;
}

/************************************************************
* this will use math to figure out the number of days
***********************************************************/
int daysYear(int year)
{
   int days = 0;
   while ( year > 1753)
   {
      year -= 1;
     
      if ( isLeapYear(year))
      {
         days += 366;
      }
      else
      {
         days += 365;
      }
     
   }

   return days;
}
            

/**********************************************************************
* this is main which will call daysYear function and then display how 
* many days are in the 
***********************************************************************/
int main()
{
   int year;
   cout << "Year: ";
   cin >> year;

   cout << "Number of days: "
        << daysYear(year) << endl;
   
   return 0;
}
