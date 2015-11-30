#include <iostream>
using namespace std;

#include "time.h" //includes the file time.h



/****************
 * defines the constructor of Time
 *****************/
Time :: Time()
{
   hours = 0;
   minutes = 0;
   seconds = 0;
}

/*********************
 * creates a non default contstructor of Time
 ********************/
Time :: Time(int hours, int minutes, int seconds)
{
   this->hours = hours;
   this->minutes = minutes;
   this->seconds = seconds;

   if (this->minutes >= 60)
   {
      this->minutes -=60;
      ++this->hours;
   }
   
   if (this->seconds >= 60)
   {
      this->seconds -= 60;
      ++this->minutes;
   }
}


/********************
 * a destructor for time. when Time
 * is destroyed, also clears the new data taken.
 ********************/
Time :: ~Time()
{
  
}

/**************************
 * sets the variable useMilitaryAsDefault to true.
 *************************/
bool Time :: useMilitaryAsDefault = true;

/**********************
 * this method prompts the user for
 * them to enter time. 
 **********************/
void Time:: promptForTime()
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

/***************************
 * this will overload the >> operator
 **************************/
istream & operator >> (istream & in, Time & rhs)
{
   int hours;
   int minutes;
   int seconds;
   in >> hours;
   in.ignore();
   in >> minutes;
   in.ignore();
   in >> seconds;
   rhs.set(hours, minutes, seconds);
   return in;
}

/*******************************
 * this will overload << operator
 *****************************/
ostream & operator << (ostream & out, const Time & rhs)
{
   out << rhs.getHours();
   if (rhs.getMinutes() < 10)
   {
      out << ":0" << rhs.getMinutes();
   }
   else
   {
      out << ":" << rhs.getMinutes();
   }
   if (rhs.getSeconds() < 10)
      out << ":0" << rhs.getSeconds();
   else
      out << ":" << rhs.getSeconds();
   
   return out;
}

/******************************
 * overload the + operator to do math
 *****************************/
Time operator + (const Time & lhs, const Time & rhs)
{
   //mmreturn Time(lhs.addHours(rhs.getHours()),
   //lhs.addMinutes(rhs.getMinutes()),
   //mlhs.addSeconds(rhs.getSeconds()));
    return  lhs;
}

/***********************
 * allows for comparison
 **********************/
bool operator == (const Time & lhs, const Time & rhs)
{
   return (lhs.getHours() == rhs.getHours() &&
           lhs.getMinutes() == rhs.getMinutes() &&
           lhs.getSeconds() == rhs.getSeconds());
}

/************************
 * allows for not equal to
 ************************/
bool operator != ( const Time & lhs, const Time & rhs)
{
   return !(lhs == rhs);
}

/********************
 * compares to for which is bigger
 *********************/
bool operator > (const Time & lhs, const Time & rhs)
{
   return (lhs.getHours() > rhs.getHours());
}

/********************
 * this will do greater than or equal to
 **********************/
bool operator >= (const Time & lhs, const Time & rhs)
{
   return (lhs.getHours() >= rhs.getHours() &&
           lhs.getMinutes() >= rhs.getMinutes() &&
           lhs.getSeconds() >= rhs.getSeconds()); 
   //return lhs > rhs || lhs == rhs;
}

/********************
 * less than
 ***********************/
bool operator < (const Time & lhs, const Time & rhs)
{
   return lhs.getHours() < rhs.getHours();
   /*  
   return (lhs.getHours() < rhs.getHours() ||
           lhs.getMinutes() < rhs.getMinutes() ||
           lhs.getSeconds() < rhs.getSeconds());
   */
}

/*********************
 * less than or equal
 ***********************/
bool operator <= (const Time & lhs, const Time & rhs)
{
   return (lhs.getHours() <= rhs.getHours() ||
           lhs.getMinutes() <= rhs.getMinutes() ||
           lhs.getSeconds() <= rhs.getSeconds());
   // return lhs < rhs || lhs == rhs;
}

/************************
 * add and assign
 *************************/
Time & Time :: operator += (const Time & rhs)
{
   this->hours += rhs.hours;
   if (this->hours >= 24)
      hours -=24;
   this->minutes += rhs.hours;
   if (this->minutes >= 60)
   {
      this->minutes -= 60;
      ++this->hours;
   }
   this->seconds += rhs.seconds;
   if (this->seconds >= 60)
   {
      this->seconds -= 60;
      ++this->minutes;
   }
   return *this;
}

/***********************
 * assign operator
 ********************/
Time & Time :: operator = ( const Time & rhs)
{
   this->hours = rhs.hours;
   this->minutes = rhs.minutes;
   this->seconds = rhs.seconds;
   return *this;
}
