/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well. It includes my Whole
 *    Number class for dealing with big numbers.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"

#include <iostream>
#include <list>
#include <iomanip>


// the interactive fibonacci program
void fibonacci();

class WholeNumber
{
  public:

   //Default constructor
  WholeNumber() : fibo() {}

   //Destructor
   ~WholeNumber()
   {
      //fibo.clear();
   }
   

   //Non-default Destructor
   WholeNumber(unsigned int i)
   {
      fibo.push_back(i);
   }

   /*****************************************
    *this method allows me to clear whats in my list
    ****************************************/
   void reset() { fibo.clear(); fibo.push_back(1); }

   //Prototype for my += operator
   void operator += (WholeNumber & rhs);

   //overloading the
   friend std::ostream& operator <<(std::ostream& out, WholeNumber number);
   

  private:
   std::list<int> fibo;   //my list for my Big numbers
 };



#endif // FIBONACCI_H

