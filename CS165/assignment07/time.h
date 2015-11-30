#ifndef TIME_H
#define TIME_H

/************************
 * this is a class definition 
 * defining the class Time.
 *************************/
class Time
{
  private:
   int hours;
   int minutes;
   int seconds;
   
  public:
   Time();
   Time(int hours, int minutes, int seconds);
   int getHours() const { return hours; }
   int getMinutes() const {return minutes; }
   int getSeconds() const {return seconds; }
   void setHours(int hours) { this->hours = hours; }
   void setMinutes(int minutes) { this->minutes = minutes; }
   void setSeconds(int seconds) { this->seconds = seconds; }
   void set(int hours, int minutes, int seconds);
   void prompt();
   void displayMilitary() const;
   void displayStandard() const;
   void display() const;
   ~Time();

   static bool useMilitaryAsDefault;

   int addHours(int lHours) const
   {
      return (hours + lHours);
   }

   int addMinutes(int lMinutes) const
   {
      int newMin;
      newMin = minutes + lMinutes;
      
      if (newMin > 60)
      {
         newMin -= 60;
      }
      return newMin;
   }

   int addSeconds(int lSeconds) const
   {
      int newSec;
      newSec = seconds + lSeconds;
      if (newSec > 60)
      {
         //newSec -= 60;
      }
      return newSec;
   }

   Time & operator = (const Time & rhs);
   Time & operator += (const Time & rhs);
};

istream & operator >> (istream & in, Time & rhs);
ostream & operator << (ostream & out, const Time & rhs);
Time operator + (const Time & lhs, const Time & rhs);
bool operator == (const Time & lhs, const Time & rhs);
bool operator != (const Time & lhs, const Time & rhs);
bool operator > (const Time & lhs, const Time & rhs);
bool operator >= (const Time & lhs, const Time & rhs);
bool operator < (const Time & lhs, const Time & rhs);
bool operator <= (const Time & lhs, const Time & rhs);

#endif // TIME_H
