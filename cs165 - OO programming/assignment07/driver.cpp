/********************************
 * Program:
 *    Operator Overloading, Assignment 07
 *    Brother Burton, CS165
 * Author:
 *    David Lambertson
 * Summary:
 *    This will allow the user to input two times
 *    and then will compare using ==, <, >, <=,
 *    >=, and do math using +, =, and +=.
 *    it will display the three numbers.
 ***********************************/

#include <iostream>

using namespace std;

#include "time.h"

/****************
 * prompts user for two numbers, then does comparisons
 * on the numbers and displays if true or false.
 * then displays two numbers and does math and displays
 * again.
 ***************/
int main()
{
   Time time1;
   Time time2;
   Time time3;
   
   
   cout << "Welcome to the Time Program." << endl;
   
   cout << endl << "Please enter the first time: ";
   cin >> time1;

   cout << "Please enter the second time: ";
   cin >> time2;

   cout << endl;
   cout << "Your times are: " << time1 << ", and " << time2 << endl;

   cout << endl;
   
   //compare using ==
   cout << "first == second: ";
   if (time1 == time2)
      cout << "true" << endl;
   else
      cout << "false" << endl;
   
   //compare using !=
   cout << "first != second: ";
   if (time1 != time2)
      cout << "true" << endl;
   else
      cout << "false" << endl;
   
   //compare using <
   cout << "first < second: ";
   if (time1 < time2)
      cout << "true" << endl;
   else
      cout << "false" << endl;

   //compare using <=
   cout << "first <= second: ";
   if (time1 <= time2)
      cout << "true" << endl;
   else
      cout << "false" << endl;
   
   //compare using >
   cout << "first > second: ";
   if (time1 > time2)
      cout << "true" << endl;
   else
      cout << "false"<< endl;

   // compare using >=
   cout << "first >= second: ";
   if (time1 >= time2)
      cout << "true" << endl;
   else
      cout << "false" << endl;

   cout << endl;
   
   // using =
   time3 = time1 + time2;
   cout << time1 << " + " << time2 << " = " << time3 << endl;

   //using +=
   time1 += time2;
   cout << "After +=, the times are: " << time1 << ", " << time2 << endl;
   
   return 0;
}


