/***********************************************************************
* Program:
*    Assignment 15, Calender Display        
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    this program will allow the user to input the number of days
*    and the offset number and then will display the correct calender
*
*    Estimated:  1.2 hrs   
*    Actual:     2.5 hrs
*      figuring how to get the columns to line up correctly
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************
 * this function will display the table of the calender
 ************************************************************/
void displayTable(int numDays, int offset)
{
  
   cout.setf(ios::right);
   int column = offset + 1;


   cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu"
        << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr"
        << setw(4) << "Sa" << endl;

   if (offset == 6)
      column = 0;
   else 
      for ( ; - offset <= 0; offset--)
      {
         cout << setw(4) << " ";
      }
   
   
   int day;
   for (day = 1; day <= numDays; day++)
   {
      
      if (column >= 6)
      {
         cout << setw(4) << day;
         cout << endl;
         column = 0;
      }
      
      else
      {
         cout << setw(4) << day;
         column++;
      }
   }
 
   return;
}

/**********************************************************************
* main will ask the user for number of days and offset and then start
* the display Table function
***********************************************************************/
int main()
{

   int numDays;
   int offset;
   
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;

   
   displayTable(numDays, offset);
   return 0;
}
