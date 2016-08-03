#ifndef TIME_H
#define TIME_H

/************************
 * this is a class definition 
 * defining the class Time.
 *************************/
class Time
{
  private:
   int * data; //stores the time data
   
  public:
   Time();
   Time(int hours, int minutes, int seconds);
   int getHours() const { return data[0]; }
   int getMinutes() const {return data[1]; }
   int getSeconds() const {return data[2]; }
   void setHours(int hours) { data[0] = hours; }
   void setMinutes(int minutes) { data[1] = minutes; }
   void setSeconds(int seconds) { data[2] = seconds; }
   void set(int hours, int minutes, int seconds);
   void prompt();
   void displayMilitary() const;
   void displayStandard() const;
   void display() const;
   ~Time();

   static bool useMilitaryAsDefault;
};

#endif // TIME_H
