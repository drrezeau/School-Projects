/*****************************************************
 * File: driver.cpp
 * Author: Brother Burton
 *
 * Description: This file helps to test the time class
 *    included int the current directory.
 *
 * You should not need to change this file.
 ****************************************************/

#include <iostream>
using namespace std;

#include "time.h"

// function prototypes
void displayGreeting();
bool getIsMilitaryTime();

/****************************************************
 * Function: main
 * Prompts the user for three times, then for the type
 * of display, and finally displays the times.
 ****************************************************/
int main()
{
   Time time1;
   Time time2;
   Time time3;

   displayGreeting();

   // input each time object, via their prompt methods
   time1.prompt();
   cout << endl;

   time2.prompt();
   cout << endl;

   time3.prompt();
   cout << endl;

   // call a function to decide if we are using military time
   bool isMilitary = getIsMilitaryTime();
   
   // set the static member variable, so all times will be
   // in the proper format
   Time :: useMilitaryAsDefault = isMilitary;

   // output the times
   cout << "\nYour times are:\n\n";
   
   time1.display();
   cout << endl;

   time2.display();
   cout << endl;

   time3.display();
   cout << endl;

   return 0;
}

/*******************************************************
 * Function: displayGreeting
 * Displays the welcome message.
 *******************************************************/
void displayGreeting()
{
   cout << "Welcome to the time program!\n";
   cout << "You will be prompted for three times, "
        << "and then the display type." << endl;
   cout << endl;
}

/*******************************************************
 * Function: getIsMilitaryTime
 * Prompts the user for whether they want military or
 * standard time and returns the value.
 *******************************************************/
bool getIsMilitaryTime()
{
   bool isMilitary = true;

   char input;

   cout << "Would you like to use military or standard time (m/s): ";
   cin >> input;

   // this could be improved to check for errors...

   if (input == 'm')
   {
      isMilitary = true;
   }
   else if (input == 's')
   {
      isMilitary = false;
   }
   else
   {
      cout << "Unrecognized input. Using military time.\n";
   }

   return isMilitary;
}

// end of file: driver.cpp

