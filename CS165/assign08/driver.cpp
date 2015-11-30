/***********************************************************
 * File: driver.cpp
 * Author: Brother Burton
 *
 * Purpose: This program will test a Date class, to ensure that
 * it has all the correct functionality.
 ***********************************************************/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "date.h"

void changeAndDisplayDate(Date date);

/***********************************************************
 * Function: main
 *
 * Description: This is the driver function for the program
 * it inputs a date from the user, and modifies it in
 * different ways, displaying it to the screen to make sure
 * the class is implemented correctly.
 ***********************************************************/
int main()
{
   cout << "Welcome to the date program!\n\n";

   Date date1;
   bool isBadDate = false;

   do
   {
      isBadDate = false;
      
      try
      {
         date1.promptForDate();
         date1.promptForTime();
      }
      catch (string error)
      {
         cout << "Error entering date. Please try again.\n";
         isBadDate = true;
      }
   } while (isBadDate);

   // Try a bad date in a constructor
   try
   {
      Date badDate(14, 6, 1830);

      cout << "Error: Should not have gotten to this statement. ";
      cout << "The line before should have thrown an exception.\n\n";

      assert(false);
   }
   catch (string error)
   {
      // the exception was thrown correctly!
   }

   Date date2(4, 6, 1830, 12, 30, 00);
   Date date3;

   cout << endl;
   cout << "Date 1: " << date1 << endl;
   cout << "Date 2: " << date2 << endl;
   cout << "Date 3: " << date3 << endl;

   // verify assignment operator
   date3 = date2;

   cout << "After first assignment, Date 3: " << date3 << endl;
   
   changeAndDisplayDate(date1);
}

/**************************************************
 * Function: changeAndDisplayDate
 *
 * Description: This function will add various amounts
 * to the given date and display it at each step.
 **************************************************/
void changeAndDisplayDate(Date date)
{
   // Note: it would be better to pass this date by reference,
   // but we want to make sure copy constructors work :-)

   cout << "Starting date: " << date << endl;
   
   date.addSeconds(10);
   cout << "Add 10 seconds: " << date << endl;

   date.addMinutes(5);
   cout << "Add 5 minutes: " << date << endl;

   date.addHours(2);
   cout << "Add 2 hours: " << date << endl;

   date.addDays(3);
   cout << "Add 3 days: " << date << endl;

   date.addMonths(1);
   cout << "Add 1 month: " << date << endl;

   date.addYears(100);
   cout << "Add 100 years: " << date << endl;
}

