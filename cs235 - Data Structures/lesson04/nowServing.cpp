/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    David Lambertson
 * Time
 *    2.5 hours
 **********************************************************************/

#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
#include <iostream>
#include <string>
using namespace std;

//prototypes for the functions I call in nowServing()
void setSpot(inLine & spot, const string & Class, const string & name,
             const int & studentMins, const string & command);
void getData(inLine & spot, string & Class, string & command,
             Deque<inLine> & waiting);

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here

   int minute;                //the current minute
   string command;            //the command given to us (IE !! or finished)
   inLine spot;               //creates an inLine to save the information
   Deque<inLine> waiting;     //a deque of inLine data for the waiting line
   string Class;              //saves the class the person is in

   inLine serving;            //the person currently being served
   int time = 0;              //allows us to minus one for time elapsed
                              //for serving
   
   do //loop until we have command == finished
   {
      cout << "<" << minute << "> ";
      cin >> command;
      minute++;

      if(command == "!!")             //if there is an emergency do this
      {
         cin >> Class;
         getData(spot, Class, command, waiting);
      }
      
      else if (command == "none")     // no command we do nothing
         ;
      
      else if (command == "finished") //we are done, get thee out of the loop
         break;
      
      else                            //default case of someone lining up.
      {
         Class = command;             //since our class got saved as a command
         getData(spot, Class, command, waiting);
      }

      if (time == 0)                 //when the last person has been finished
                                     //being helped
      {
         if (!waiting.empty())       //only copy if there is stuff to copy
         {
            serving = waiting.front();
            waiting.pop_front();
            time = serving.getStudentMins();
         }
      }
      
      if (serving.getStudentMins() != 0) //only does this while the student
                                         //has time left
      {
         time--;

         cout << (serving.getCommand() == "!!" ? "\tEmergency for "
                  : "\tCurrently serving ")
              << serving.getName()
              << " for class " << serving.getClass()
              << ". Time left: " << serving.getStudentMins() << endl;
         serving.setStudentMins(time);
      }
   }
   while( command != "finished");

   // finished!
   cout << "End of simulation\n";
}


/*******************************
 *a simple function just setting everything
 *for the one in line.
 *********************************/
void setSpot(inLine & spot, const string & Class, const string & name,
             const int & studentMins, const string & command)
{
   spot.setName(name);
   spot.setClass(Class);
   spot.setStudentMins(studentMins);
   spot.setCommand(command);
}

/************************************
 *gets and sets the data within the deque
 ************************************/
void getData(inLine & spot, string & Class, string & command, Deque<inLine> & waiting)
{
   string name;
   int studentMins;
   cin >> name >> studentMins;
   setSpot(spot, Class, name, studentMins, command);
   if (command == "!!")
      waiting.push_front(spot);
   else
      waiting.push_back(spot);
}
