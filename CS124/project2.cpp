/***********************************************************************
* Program:
*    Project 2, Calender Program     
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will allow the user to input a year from 1753 or later
*       and what month they want between 1 and 12, and will display
*       the given month.
*
*    Estimated:  3.75 hrs   
*    Actual:     4.5 hrs
*      getting the offset to work properly.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************
 * this function will ask the user to input a month.
 * get Month
 * month
 * WHILE month <= 0 OR month > 12
 *      PROMPT user for month
 *      GET month
 *      IF month <= 0 OR month > 12
 *              PUT Month must be between 1 and 12
 * RETURN month value
 *******************************************************/
int getMonth()
{
   int month;
   
   do
   {
      cout << "Enter a month number: ";
      cin >> month;
      if (month <= 0 || month > 12)
         cout << "Month must be between 1 and 12.\n";
   }
   while (month < 0 || month > 12);

   return month;
}

/*****************************************************
 * this function will ask the user to input a year.
 * get Year
 * year
 * WHILE year < 1753
 *      PUT Enter Year
 *      GET year
 *      IF year < 1753
 *              PUT Year must be 1753 or later
 * RETURN year
 *****************************************************/
int getYear()
{
   int year;
   do
   {
      cout << "Enter year: ";
      cin >> year;
      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
   }
   while (year < 1753);

   return year;
}

/**************************************************
 * this function will use the year to decide if year is
 * leap year or not.
 *
 * isLeapYear(year)
 * IF year % 4 != 0
 *      RETURN false
 * ELSE IF year % 100 != 0
 *      RETURN true
 * ELSE IF year $ 400 == 0
 *      RETURN true
 * ELSE
 *      RETURN false
 ***************************************************/
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

/*****************************************************
 * this function will calculate the number of days
 * from January 1st, 1753 to the first day of the year
 * the user inputs.
 * daysYear(year)
 * SET days = 0
 * WHILE year > 1753
 *      year = year - 1
 *      IF isLeapYear(year)
 *              days = days + 366
 *      ELSE
 *              days = days + 365
 * RETURN days
 *******************************************/
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

/********************************************************
 * this function will calculate the number of days from the
 * first of the year, to the first day of the given month.
 * daysMonth(month, year)
 * SET daysmonth = 0
 * FOR i = 0; i < month; i++
 *      IF i == 1 OR i == 3 OR i == 5 OR i == 7
 *         OR i == 8 OR i == 10 OR i == 12
 *              daysmonth = daysmonth + 31
 *      ELSE IF i == 4 OR i ==6 OR i == 9 OR i == 11
 *              daysmonth += 30
 *      ELSE IF i == 2 AND isLeapYear(year)
 *              daysmonth += 29
 *      ELSE
 *              daysmonth += 28
 * RETURN daysmonth
 ******************************************************/
int daysMonth(int month, int year)
{
   int daysmonth = 0;
   for (int i = 1; i < month; i++)
   {
      if (i == 1 || i == 3 || i == 5
         || i == 7 || i == 8 || i == 10
         || i == 12)
         daysmonth += 31;
      else if (i == 4 || i == 6 || i
              == 9 || i == 11)
         daysmonth += 30;
      else if (i == 2 && isLeapYear(year))
         daysmonth += 29;
      else
         daysmonth += 28;
   }
   return daysmonth;
}

/************************************************
 * this function will give the program displayTable
 * the amount of days in the month.
 * daysinMonth(month, year)
 * SET daysmonth = 0
 *
 * FOR i = 0; i < month; i++
 *      IF i == 1 OR i == 3 OR i == 5 OR i == 7
 *         OR i == 8 OR i == 10 OR i == 12
 *              daysmonth = 31
 *      ELSE IF i == 4 OR i ==6 OR i == 9 OR i == 11
 *              daysmonth = 30
 *      ELSE IF i == 2 AND isLeapYear(year)
 *              daysmonth = 29
 *      ELSE
 *              daysmonth = 28
 * RETURN daysmonth
 ************************************************/
int daysinMonth(int month, int year)
{
   int daysmonth = 0;
   for (int i = 1; i <= month; i++)
   {
      if (i == 1 || i == 3 || i == 5
                  || i == 7 || i == 8 || i == 10
         || i == 12)
         daysmonth = 31;
      else if (i == 4 || i == 6 || i
              == 9 || i == 11)
         daysmonth = 30;
      else if (i == 2 && isLeapYear(year))
         daysmonth = 29;
      else
         daysmonth = 28;
   }
   return daysmonth;
}

/******************************************
 * this function will determine the offset using the number 
 * of days since January first, 1753.
 * getOffset(month, year)
 * days 1753 = daysYear(year) + daysMonth(month, year)
 * week1753 = days1753 % 7
 * offset = weeks1753 % 7
 * RETURN offset
 ******************************************/
int getOffset(int month, int  year)
{
   int days1753 = daysYear(year) + daysMonth(month, year);
   int weeks1753 = days1753 % 7;
   int offset = weeks1753 % 7;
   return offset;
}

/***********************************************************
 * this function will display the Header for the given month and year.
 * displayHeader(month, year)
 * IF month == 1
 *      PUT January
 * ELSE IF month == 2 
 *      PUT February
 * ELSE IF month == 3
 *      PUT March
 * ELSE IF month == 4
 *      PUT April
 * ELSE IF month == 5
 *      PUT May
 * ELSE IF month == 6
 *      PUT June
 * ELSE IF month == 7
 *      PUT July

 * ELSE IF month == 8
 *      PUT August
 * ELSE IF month == 9
 *      PUT September
 * ELSE IF month == 10
 *      PUT October
 * ELSE IF month == 11
 *      PUT November
 * ELSE IF month == 12
 *      PUT December
 **********************************************************/
void displayHeader(int month, int year)
{
   if (month == 1)
      cout << "January, " << year << endl;
   else if (month == 2)
      cout << "February, " << year << endl;
   else if (month == 3)
      cout << "March, " << year << endl;
   else if (month == 4)
      cout << "April, " << year << endl;
   else if (month == 5)
      cout << "May, " << year << endl;
   else if (month == 6)
      cout << "June, " << year << endl;
   else if (month == 7)
      cout << "July, " << year << endl;
   else if (month == 8)
      cout << "August, " << year << endl;
   else if (month == 9)
      cout << "September, " << year << endl;
   else if (month == 10)
      cout << "October, " << year << endl;
   else if (month == 11)
      cout << "November, " << year << endl;
   else if (month == 12)
      cout << "December, " << year << endl;
}

/******************************************************
 * this function will display the table for the month
 * displayTable(month, year, offset)
 * SET numDays = daysinMonth(month, year)
 * SET column = offset + 1
 * PUT Su Mo Tu We Th Fr Sa
 * IF offset == 6
 *      column = 0
 * ELSE
 *      FOR - offset <= 0; offset--
 *              PUT "    "
 * SET day
 * FOR day = 1; day <= numDays; day++
 *      IF column >= 6
 *              PUT day
 *              column = 0
 *      ELSE
 *              PUT day
 *              column++
 * RETURN
 *******************************************************/
void displayTable(int month, int year, int offset)
{

   int numDays = daysinMonth(month, year);
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

/****************************************************************************
 * this function will call displayHeader and displayTable to display
 * the month the user has asked for
 * display(month, year, offset)
 * displayHeader(month, year)
 * displayTable(month, year, offset)
 **********************************************************************/
void display(int month, int year, int offset)
{
   displayHeader(month, year);
   displayTable(month, year, offset);
}



/**********************************************************************
* this function, main, will call getMonth to get the month, getYear to get year
* getOffset to get the offset, and then will call display to display
* the calender on the screen.
* main
* SET month = getMonth
* SET year = getYear
* SET offset = getOffset(month, year)
* display( month, year, offset)
* RETURN 0
***********************************************************************/
int main()
{
   int  month =  getMonth();
   int year =  getYear();
   int offset = getOffset(month, year);
   cout << endl;
   display(month, year, offset);
  
   return 0;
}
