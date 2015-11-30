/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    David Lambertson
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include "deque.h"     // for DEQUE
#include <string>
#include <iostream>



// the interactive nowServing program
void nowServing();


/*********************
 * this is a class I created to
 * help keep track of those who are in
 * in line and their information
 *********************/
class inLine
{
  public:
   //all the functions to be able to set the private member variables.
   void setName(const std::string & name)       { this->name = name; }
   void setClass(const std::string & Class)     { this->Class = Class; }
   void setStudentMins(const int & studentMins) { this->studentMins = studentMins; }
   void setCommand(const std::string & command) { this->command = command; }

   //all the getters for my custom class 
   int getStudentMins() const     { return studentMins; }
   std::string getClass() const   { return Class; }
   std::string getName() const    { return name; }
   std::string getCommand() const { return command; }

  private:
   int studentMins;
   std::string Class;
   std::string name;
   std::string command;

};


#endif // NOW_SERVING_H

