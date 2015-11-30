#ifndef LEG_H
#define LEG_H

#include <string>
#include "date.h"

/******************************************************************************
* Class to be used for the data object that is stored in your node class.
* You must implement each of the public functions (see leg.cpp).
******************************************************************************/
class Leg
{
   private:
      std::string startCity;
      std::string destCity;
      std::string transMode; // transportation mode between cities (car, plane, etc)
      int milesBetween; // mileage between start and destination cities
      Date startDateTime;
      Date arrivalDateTime;
   public:
      Leg();
      Leg(std::string sCity, std::string dCity, std::string transMode, int miles,
          Date startDate, Date arrivalDate);
      void display();
      bool operator == (Leg rightSide);
      bool operator != (Leg rightSide);

      std::string getStartCity() { return startCity; }
      std::string getDestCity() { return destCity; }
      std::string getTransMode() { return transMode; }
      int getMiles() { return milesBetween; }
      Date getStartDate() { return startDateTime; }
      Date getArrivalDate() { return arrivalDateTime; }
};

#endif
