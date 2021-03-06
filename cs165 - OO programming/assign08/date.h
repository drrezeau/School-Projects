#ifndef DATE_H
#define DATE_H

#include "time.h"
#include <iostream>
#include <string>
using namespace std;
/******************
 * this is a date class
 * to handle the date part of time.
 *****************/
class Date : public Time
{
  private:
   int month;
   int day;
   int year;

   bool isLeapYear(int year) //check if its a leap year.
   {
      if (year % 4 != 0)
         return false;
      else if (year % 100 != 0)
         return true;
      else if (year % 400 != 0)
         return true;
      else
         return false;
   }
         
   
   int getDaysinMonth(int month, int year) // checks number of days in a month
   {
      int daysmonth = 0;

      if (month == 1 || month == 3 || month == 5
          || month == 7 || month == 8 || month == 10
          || month == 12)
         daysmonth = 31;
      else if (month == 4 || month == 6 || month
               == 9 || month == 11)
         daysmonth = 30;
      else if (month == 2 && isLeapYear(year))
         daysmonth = 29;
      else
         daysmonth = 28;
      return daysmonth;
   }
   
  public:
   Date()
   {
      month = 1;
      day = 1;
      year = 1970;
      setHours(0);
      setMinutes(0);
      setSeconds(0);
   }

   Date(int month, int day, int year)
   {
      this->month = month;
      this->day = day;
      this->year = year;
      setHours(0);
      setMinutes(0);
      setSeconds(0);
      if (month > 12 || day > getDaysinMonth(month, year))
      {
         string error = "error";
         throw error;
      }
   }

   Date(int month, int day, int year, int hours, int minutes, int seconds);
   
   Date(const Date & rhs)
   {
      month = rhs.month;
      day = rhs.day;
      year = rhs.year;
      setHours(rhs.getHours());
      setMinutes(rhs.getMinutes());
      setSeconds(rhs.getSeconds());
   }
   
   int getMonths() const { return month; }
   int getDays() const { return day; }
   int getYears() const { return year; }
   void setMonth(int months) { month = months; }
   void setDay(int days) {day = days; }
   void setYear(int years) { year = years; }
   void setDate(int month, int day, int year)
   {
      this->month = month;
      this->day = day;
      this->year = year;
   }

   void promptForDate();
   Date & operator = (const Date & rhs);
   void addMonths(int monthsAdd);
   void addDays(int daysAdd);
   void addYears(int yearsAdd);
   void addHours(int hoursAdd);
   

};

ostream & operator << (ostream & out, const Date & rhs);

#endif // DATE_H
