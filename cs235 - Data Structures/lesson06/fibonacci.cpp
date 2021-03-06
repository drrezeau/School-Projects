/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    David Lambertson
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;


/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers


   WholeNumber number1(1);
   WholeNumber number2(1);
   cout << "\t" << number1 << endl;
   cout << "\t" << number2 << endl;   //create two WholeNumbers and display them for the first two fibonacci numbers
 
   for (int i = 2; i < number; i++) //keep going until I get to where they want me.
   {
      if (i%2 == 0) //even
      {
         number1 += number2;
         cout << "\t" << number1 << endl;
      }
      else       //odd
      {
         number2 += number1;
         cout << "\t" << number2 << endl;
      }
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   number1.reset();  //resets my WholeNumbers back to the beginning
   number2.reset();
   
   for (int i = 2; i < number; i++)
   {
      if (i%2 == 0)
      {
         number1 += number2;
      }
      else
      {
         number2 += number1;
      }
   }

   if (number%2 == 0) //display only the number they want.
      cout << "\t" << number2 << endl;
   else
      cout << "\t" << number1 << endl;
   // your code to display the <number>th Fibonacci number
}

/************************************
 * overloaded insertion opperator to display my WholeNumbers
 ************************************/
std::ostream& operator <<(std::ostream& out, WholeNumber number)
{
   for (list<int>::const_reverse_iterator it = number.fibo.rbegin();
        it != number.fibo.rend(); ++it)
   {
      if (it != --number.fibo.rend())//do this until I am at end of list
      {
         if (it == number.fibo.rbegin())
            out << *it << ',';
         else 
            out << setfill('0') << setw(3) << *it << ',';
      }
      else // do this when I am at end of list
      {
         if (it == number.fibo.rbegin())
            out << *it;
         else
            out << setfill('0') << setw(3) << *it;
      }
   }
      
   return out;
}

/******************************************
 * overloaded += operator to allow me to go through the fibonacci numbers
 *****************************************/
void WholeNumber :: operator += (WholeNumber & rhs)
{
   list<int>::iterator it2 = rhs.fibo.begin();
   list<int>::iterator it = fibo.begin();
 
   int carry = 0;
   for (; it2 != rhs.fibo.end(); ++it2)
   {

      int x=0, y=0;
      if (it != fibo.end())
         x = *it;
      else
         x = 0; //fibo

      if (it2 != rhs.fibo.end())
         y = *it2; //rhs fibo
      else
         y = 0;
      
      int a = x + y + carry;
      
      carry = a / 1000;
      
      if (it == fibo.end())
      {
         fibo.push_back(a);
         break;
      }
      *it = (a%1000);
      ++it;
   }

   if (carry)
      fibo.push_back(carry);
}

