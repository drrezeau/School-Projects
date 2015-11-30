#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "leg.h"
#include "node.h"

#include "date.h"

/******************************************************************************
* This program reads in the itinerary from the file trip.dat and stores it into
* a linked list.  The linked list is then displayed showing an itinerary.
*
*  YOU MUST FINISH THIS FUNCTION!!!!!
*
******************************************************************************/
int main()
{
   string startCity;
   string destCity;
   string transMode;
   int miles;
   Date startDate;
   Date arrivalDate;

   Node<Leg>* head = NULL;
   Node<Leg>* endLeg = head;

   char fileName[80] = "/home/cs165sb/linkedList/trip.dat";
   ifstream fin;

   int errorCnt = 0;
   fin.open(fileName);
   while (fin.fail())
   {
      errorCnt++;
      cout << "File not found! - '" << fileName << "'" << endl;
      if (errorCnt <= 3)
      {
         cout << "\nPlease enter the complete path or correct file name: ";
         cin >> fileName;
      }
      else
      {
         cout << "\nI'm sorry, the file '" << fileName
              << "' is not found were specified.  Exiting the program!!!\n"; 
         exit(1);
      }
      fin.open(fileName);
   }
   
   // hint: read startCity
   getline(fin, startCity);
   while (!fin.eof())
   {  
      // hint: read  destination city, transportation mode, miles
      getline(fin, destCity);
      
      getline(fin, transMode);

      fin >> miles;

      // hint: read  month, day, year, hr, min
      int sMonth;
      fin >> sMonth;
      int sDay;
      fin >> sDay;
      int sYear;
      fin >> sYear;
      int sHour;
      fin >> sHour;
      int sMinute;
      fin >> sMinute;

      // hint: create start date object
      //startDate(sMonth, sDay, sYear, sHour, sMinute);
      startDate.setMonth(sMonth);
      startDate.setDay(sDay);
      startDate.setYear(sYear);
      startDate.setHours(sHour);
      startDate.setMinutes(sMinute);

      // hint : read month, day, year, hr, min
      int aMonth;
      int aDay;
      int aYear;
      int aHour;
      int aMinute;

      fin >> aMonth;
      fin >> aDay;
      fin >> aYear;
      fin >> aHour;
      fin >> aMinute;

      // hint: create arrival date object
      //arrivalDate(aMonth, aDay, aYear, aHour, aMinute);
      arrivalDate.setMonth(aMonth);
      arrivalDate.setDay(aDay);
      arrivalDate.setYear(aYear);
      arrivalDate.setHours(aHour);
      arrivalDate.setMinutes(aMinute);

      // hint: throw away newline characters so next getline() will work.
      fin.ignore(80,'\n');

      // hint: create a Leg object using startCity, destCity, transMode,
      //       miles, startDate, arrivalDate
      Leg leg(startCity, destCity, transMode, miles, startDate, arrivalDate);

      if (head == NULL)
      {
         insert(head, leg);
         endLeg = head;
      }
      else
      {
         insert(endLeg, leg);
         endLeg = endLeg->getLink();
      }


      
      // hint: insert new leg of the trip at the end of the linked list

      // hint: read next startCity from file
      getline(fin, startCity);
     
   }

   cout << endl;
   cout << "Start City           Start Date         Destination City     Arrival Date       Mode    Miles \n";     
   cout << "-------------------- ----------------   -------------------- ----------------   -----   -----\n";
 
   // Display the itinerary HERE by traversing through the linked list!!
   for (Node<Leg>* curLeg = head; curLeg; curLeg = curLeg->getLink())
   {
      curLeg->getData().display();
   }

   return 0;
}
