#include <iostream>
using namespace std;

#include "time.h" //includes the file time.h



/****************
 * defines the constructor of Time
 *****************/
Time :: Time()
{
   data = new int[3];
}

/*********************
 * creates a non default contstructor of Time
 ********************/
Time :: Time(int hours, int minutes, int seconds)
{
   hours = 0;
   minutes = 00;
   seconds = 00;

   data[0] = hours;
   data[1] = minutes;
   data[2] = seconds;

}


/********************
 * a destructor for time. when Time
 * is destroyed, also clears the new data taken.
 ********************/
Time :: ~Time()
{
   delete[] data;
}

/**************************
 * sets the variable useMilitaryAsDefault to true.
 *************************/
bool Time :: useMilitaryAsDefault = true;

/**********************
 * this method prompts the user for
 * them to enter time. 
 **********************/
void Time:: prompt()
{
   int hours = 0;
   int minutes = 0;
   int seconds = 0;

   do
   {
      if (hours > 23 || hours < 0)
         cout << "Invalid amount. Please try again." << endl;
      cout << "Hours: ";
      cin >> hours;
      //if (cin.fail())
      //{
         //cout << "Invalid amount. Please try again." << endl;
         // cin.clear();
         //cin.ignore(256, '\n');
         //hours = 100;
      //}
      
   }
   while (hours > 23 || hours < 0);

   do
   {
      if (minutes > 59 || minutes < 0)
         cout << "Invalid amount. Please try again." << endl;
      cout << "Minutes: ";
      cin >> minutes;
   }
   while (minutes > 59 || minutes < 0);

   do
   {
      if (seconds > 59 || seconds < 0)
         cout << "Invalid amount. Please try again." << endl;
      cout << "Seconds: ";
      cin >> seconds;
   }
   while (seconds > 59 || seconds < 0);

   set(hours, minutes, seconds);
}

/***************************
 * this method sets each variable in data to the
 * time entered each time. 
 *************************/
void Time :: set(int hours, int minutes, int seconds)
{
   setHours(hours);
   setMinutes(minutes);
   setSeconds(seconds);
}

/****************
 * this will display depending
 * on what the user wants.
 ***************/
void Time :: display() const
{
   if (useMilitaryAsDefault)
      displayMilitary();
   else
      displayStandard();
}

/************************
 * this will display in military time
 ***********************/
void Time :: displayMilitary() const
{
   int hours = getHours();
   int minutes = getMinutes();
   int seconds = getSeconds();
   cout << hours << ":";
   if (minutes < 10)
      cout << "0" << minutes;
   else
      cout << minutes;
   cout << ":";
   if (seconds < 10)
      cout << "0" << seconds;
   else
      cout << seconds;
}

/***************************
 * this will display in standard time.
 **************************/
void Time :: displayStandard() const
{
   int hours = getHours();
   int minutes = getMinutes();
   int seconds = getSeconds();
   bool isAfternoon = false;
   if (hours >= 12)
   {
      if (hours > 12)
         hours = hours - 12;
      isAfternoon = true;
   }


   if (isAfternoon)
   {
      cout << hours << ":";
      if (minutes < 10)
         cout << "0" << minutes;
      else
         cout << minutes;
      cout << ":";
      if (seconds < 10)
         cout << "0" << seconds;
      else
         cout << seconds;
      cout << " PM";
   }

   else
   {
      cout << hours << ":";
      if (minutes < 10)
         cout << "0" << minutes;
      else
         cout << minutes;
      cout << ":";
      if (seconds < 10)
         cout << "0" << seconds;
      else
         cout << seconds;
      cout << " AM";
   }
}
