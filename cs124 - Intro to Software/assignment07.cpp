/***********************************************************************
* Program:
*    Assignment 07, Temperature Conversion          
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    This program will allow the user to input a fahrenheit temperature, and
*    will be given Celsius at the end of the program
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Hardest part was to get the division to work accurately
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* Input a number as Fahrenheit degrees.
***********************************************************************/
float getTemperature()
{
   float fahrenheit;
   
   cout << "Please enter Fahrenheit degrees: ";
   cin >> fahrenheit;
   return fahrenheit;
}

/***********************************************************************
* takes the input, and calculates Celsius
************************************************************************/
int main()
{
   
   cout.setf(ios::fixed);
   cout.precision(0);
   
   float fahrenheit;
   float celsius;
   
   fahrenheit = getTemperature();
   celsius = (5.0 / 9.0) * (fahrenheit - 32);
   cout << "Celsius: " << celsius << endl;
   return 0;
}
