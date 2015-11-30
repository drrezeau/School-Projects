#include "leg.h"
#include "date.h"

#include <string>
#include <iomanip>
using namespace std;

/**********************************************************************
* Default Constructor - calls constructors for two Date class member 
* variables and initializes the other member variables.
*********************************************************************/
Leg::Leg()
  : startDateTime(), arrivalDateTime()
{
   startCity = "";
   destCity = "";
   transMode = "Car";
   milesBetween = 0;
}

/*****************************************************************************
* Constructor -
* Parameters are passed to this constructor to initialize all the
* member variables for the Leg object.
* Inputs:  sCity - start city
*          dCity - destination city
*   theTransMode - transportation mode ("car", "bus", "bike", "foot", "Plane")
*          miles - mileage between start city and destination city
*      startDate - "Date" object that specifies when leaving the start city.
*    arrivalDate - "Date" object that specifies expected arrival in dest city 
******************************************************************************/
Leg::Leg(string sCity, string dCity, string theTransMode, int miles,
    Date startDate, Date arrivalDate)
{
   startCity = sCity;
   destCity = dCity;
   transMode = theTransMode;
   milesBetween = miles;
   startDateTime = startDate;
   arrivalDateTime = arrivalDate;
   // you must write this function
}

/***************************************************************************
* Overload Equals operator - compares two leg objects to see if they both
* contain the same start and destination cities.
* returns:  true - start city and destination city in both objects are
*                  the same.       
*           false - start and destination cities are not the same.
***************************************************************************/
bool Leg::operator == (Leg rightSide)
{
   // you must write this function
   if (startCity == rightSide.startCity && destCity == rightSide.destCity)
      return true;
   else return false;
}

/****************************************************************************
* Overloaded "not equals" operator
* return: True - The left side object's start and destination cities
*                are not equal to the rightside object's start and destination cities.
*       False -  The start and destination cities of the two objects are equal
*****************************************************************************/
bool Leg::operator != (Leg rightSide)
{
   // you must write this function
    return false;
}

/***************************************************************************
* Display - displays the object
*    startCity, startDate, destCity, arrivalDate, transportation mode, Miles 
***************************************************************************/
void Leg::display()
{
   // you must write this function
   cout << setw(21) << left << startCity
        << startDateTime
        << setw(3) << " "
        << setw(23) << destCity
        << setw(1) << arrivalDateTime
        << setw(3) << " "
        << setw(8) << transMode
        << setw(3) << right << milesBetween << endl;


  
} 
