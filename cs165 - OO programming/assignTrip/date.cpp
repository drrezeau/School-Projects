#include "time.h"
#include "date.h"
#include <iostream>

using namespace std;
//this is a non default contsructor for DAte
Date :: Date(int month, int day, int year, int hours, int minutes, int seconds)
{
   this->month = month;
   this->day = day;
   this->year = year;
   setHours(hours);
   setMinutes(minutes);
   setSeconds(seconds);
}

Date :: Date(int month, int day, int year, int hours, int minutes)
{
   this->month = month;
   this->day = day;
   this->year = year;
   setHours(hours);
   setMinutes(minutes);
   setSeconds(0);
}


//this prompts the user for the date
void Date :: promptForDate()
{
   int month;
   int day;
   int year;

   cout << "Enter month: ";
   cin >> month;

   cout << "Enter day: ";
   cin >> day;

   cout << "Enter year: ";
   cin >> year;

   setDate(month, day, year);
}

//this is the equal operator overloading 
Date & Date :: operator = (const Date & rhs)
{
   this->month = rhs.month;
   this->day = rhs.day;
   this->year = rhs.year;
   setHours(rhs.getHours());
   setMinutes(rhs.getMinutes());
   setSeconds(rhs.getSeconds());

   return *this;
}

//this adds two months to get one
void Date :: addMonths(int monthsAdd)
{
   
   int newMonth = getMonths();
   newMonth += monthsAdd;
   if (newMonth > 12)
   {
      newMonth -= 12;
      year++;
   }
   addYears(0);
   setMonth(newMonth);
}

// this adds two days
void Date :: addDays(int daysAdd)
{
   int newDay = getDays();
   int daysMonth = getDaysinMonth(month, year);
   newDay += daysAdd;
   if (newDay > daysMonth)
   {
      newDay -= daysMonth;
      month++;
   }
   addMonths(0);
   setDay(newDay);
}

//this adds two years
void Date :: addYears(int yearsAdd)
{
   int newYear = getYears();
   newYear += yearsAdd;
   setYear(newYear);
}

//this adds two hours
void Date :: addHours(int hoursAdd)
{
   int newHour = getHours();
   newHour += hoursAdd;
   if (newHour >= 24)
   {
      newHour -= 24;
      day++;
   }
   addDays(0);
   setHours(newHour);
   
}

// overloading the operator << for output
ostream & operator << (ostream & out, const Date & rhs)
{
   if (rhs.getMonths() < 10)
      out << "0" << rhs.getMonths();
   else
      out << rhs.getMonths();
   
   if (rhs.getDays() < 10)
      out << "/0" << rhs.getDays();
   else
      out << "/" << rhs.getDays();
   
   out << "/" << rhs.getYears();

   if (rhs.getHours() < 10)
      out << " 0" << rhs.getHours();
   else
      out << " " << rhs.getHours();
   
   if (rhs.getMinutes() < 10)
      out << ":0";
   else
      out << ":";
   
   out <<  rhs.getMinutes();
   
   if (rhs.getSeconds() < 10)
      out << ":0";
   else
      out << ":";
   
   out << rhs.getSeconds();
   
   return out;
}

