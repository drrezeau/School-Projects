/******************************
 * This program will allow a user to interact
 * with the menu and add a new trip, load a file,
 * save the current trip, display current trip, clear trips,
 * and quit. This allows the user to interact at different levels
 * and change things as they desire. 
 *****************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

#include "mileageClass.h"
#include "leg.h"
#include "date.h"
#include "time.h"
#include "node.h"

// gets the option for menu interaction
void getOption(char & option)
{
   cout << ">";
   cin >> option;
   return;
}


//displays the menu
void displayMenu()
{
   cout << "Add Trip(A)\n"
        << "Load Saved Trip(L)\n"
        << "Save Trip(S)\n"
        << "Display Current Trip Itinerary(D)\n"
        << "Display Options Menu(M)\n"
        << "Clear Trip(C)\n"
        << "Quit(Q)\n";
}

//converts the option from lower case to capital
void convertOption(char & option)
{
   if (option == 'a')
      option = 'A';
   if (option == 'l')
      option = 'L';
   if (option == 's')
      option = 'S';
   if (option == 'd')
      option = 'D';
   if (option == 'm')
      option = 'M';
   if (option == 'q')
      option = 'Q';
   if (option == 'c')
      option = 'C';
   return;
}

//saves the file into given file
void saveFile(string fileName, Node<Leg> * & head, int numberOfLegs)
{
   //save file code
   ofstream fout;

   fout.open(fileName.c_str());

   if (fout.fail())
      cout << "Error saving!\n";


   for (Node<Leg> * curLeg = head; curLeg; curLeg = curLeg->getLink())
   {
      fout << curLeg->getData().getStartCity() << endl << curLeg->getData().getDestCity() << endl
           << curLeg->getData().getTransMode() << endl << curLeg->getData().getMiles() << endl
           << curLeg->getData().getStartDate() << endl << curLeg->getData().getArrivalDate() << endl;
   }

   fout.close();

   return;
}

//loads the file from given file name
void loadFile(string fileName, int numberOfLegs, Node<Leg> * & head, Node<Leg> * & endLeg)
{
   //load file code

   ifstream fin;
   fin.open(fileName.c_str());

   int failCount = 0;
   while(fin.fail())
   {
      cout << "Error! File not found. Try again.\n";
      cout << "Filename: \n" << ">";
      cin >> fileName;
      failCount++;
      if (failCount == 3)
      {
         cout << "Too many fails, leaving file load.\n";
         return;
      }
   }
   

   string sCity;
   string dCity;
   string transMode;
   int miles;
   int month, day, year, hour, minute, second;
   cout << "Loading..." << endl;
   getline(fin, sCity);
   while (!fin.eof())
   {

      getline(fin, dCity);
      getline(fin, transMode);
      fin >> miles;
      fin >> month;
      fin.ignore(256, '/');
      fin >> day;
      fin.ignore(256,'/');
      fin >> year;

      fin >> hour;
      fin.ignore(256, ':');
      fin >> minute;
      fin.ignore(256, ':');
      fin >> second;

      cout << "..." << endl;

      Date startDate(month, day, year, hour, minute, second);
      fin >> month;
      fin.ignore(256, '/');
      fin >> day;
      fin.ignore(256, '/');
      fin >> year;

      fin >> hour;
      fin.ignore(256, ':');
      fin >> minute;
      fin.ignore(256, ':');
      fin >> second;
      Date arrivalDate(month, day, year, hour, minute, second);

      cout << "..." << endl; // shows the user something is happening
      
      Leg leg(sCity, dCity, transMode, miles, startDate, arrivalDate);
      
      if (head == NULL) // inserts into the node to create the linked list.
      {
         insert(head, leg);
         endLeg = head;
      }
      else
      {
         insert(endLeg, leg);
         endLeg = endLeg->getLink();
      }
      fin.ignore(256, '\n');
      getline(fin, sCity);
   }

   cout << "Done loading." << endl;
   fin.close();
   
   return;
}

//converts the mode of transportation to capital and into string
string convertMode(char mode)
{
   string transMode;

   if (mode == 'p')
      mode = 'P';
   if (mode == 'c')
      mode = 'C';
   if (mode == 'f')
      mode = 'F';
   if (mode == 'b')
      mode = 'B';
   if (mode == 't')
      mode = 'T';

   switch (mode)
   {
      case 'P':
         return "Plane";
      case 'C':
         return "Car";
      case 'F':
         return "Foot";
      case 'B':
         return "Bus";
      case 'T':
         return "Bicycle";
   }
}

// calculates the arrival time
void arrivalTime(int travelSpeed, int travelTime, Date & arrivalDate, int miles)
{
   int daysToAdd = 0;
   int timeNeeded = miles / travelSpeed;
   daysToAdd = timeNeeded / travelTime;
   int extraHours = timeNeeded % travelTime;
   int extraMinutes = timeNeeded % (travelTime * 60);
   int extraSeconds = timeNeeded % (travelTime * 3600);
   
   
   arrivalDate.addDays(daysToAdd);
   arrivalDate.addHours(extraHours);
   arrivalDate.addMinutes(extraMinutes);
   arrivalDate.addSeconds(extraSeconds);


}
      
// creates a new leg. is called from the menu
void newLeg(string sCity, string dCity, MileageData travelInfo, MileageMap map,
            char & mode, Node<Leg> * & head, Node<Leg> * & endLeg, int & numberOfLegs)
{
   cout << "Where would you like to start your trip(ex. Boise, ID)?\n";
   cin.ignore(256, '\n');
   getline(cin, sCity);

   do
   {
      cout << "Where would you like to end your trip?(ex. Boise, ID)\n";
      getline(cin, dCity);
      
      bool found = map.getMileage(sCity, dCity, travelInfo);

      if (found) //enters if the information for the two cities is found
      {
         cout << endl;
         cout << "the following modes are available:\n";
         if (travelInfo.modes & PLANE)
            cout << "Plane(P)\n";
         if (travelInfo.modes & CAR)
            cout << "Car(C)\n";
         if (travelInfo.modes & FOOT)
            cout << "Foot(F)\n";
         if (travelInfo.modes & BUS)
            cout << "Bus(B)\n";
         if (travelInfo.modes & BICYCLE)
            cout << "Bicycle(T)\n";
         
         cout << "What mode would you like?(P, C, F, B, T)\n" << ">";
         cin >> mode;
      }
      else // allows the user to add the information if not found
      {
         cout << "No information is available. Would you like to create it?(Y/N)\n";
         char createNew;
         cout << ">";
         cin >> createNew;


         if (createNew == 'y')
         {
            MileageKey key;
            key.startCity = sCity;
            key.destCity = dCity;
            cout << "What is the distance between the two cities?(number only)\n" << ">";
            int miles;
            cin >> miles;
            travelInfo.miles = miles;
         }
         else
            return;
      }

      string transMode = convertMode(mode);

      int month, day, year;
      int hour, minute, second;

      cout << "What day do you plan to leave?(MM DD YYYY HH MM SS)\n" << ">";
      cin >> month;
      cin >> day;
      cin >> year;

      cin >> hour >> minute >> second;

      Date startDate(month, day, year, hour, minute, second);

      int travelSpeed;

      cout << "How fast will you travel?\n" << ">";
      cin >> travelSpeed;
      
      int travelTime;
      cout << "How many hours will you travel each day?\n" << ">";
      cin >> travelTime;
      
      Date arrivalDate = startDate;

      int miles = travelInfo.miles;

      arrivalTime(travelSpeed, travelTime, arrivalDate, miles);

      Leg newLeg(sCity, dCity, transMode, travelInfo.miles, startDate, arrivalDate);
      numberOfLegs++;
      if (head == NULL)
      {
         insert(head, newLeg);
         endLeg = head;
      }
      else
      {
         insert(endLeg, newLeg);
         endLeg = endLeg->getLink();
      }
      
      char addLeg;
      cout << "Would you like to add another trip?(Y/N)\n" << ">";
      cin >> addLeg;

      if (addLeg == 'n')
      {
         return;
      }
      cin.ignore(256, '\n');

      sCity = dCity;
      
   }
   while (true);
}



void menu()
{
   char option;
   cout << "How can we help you?\n";
   displayMenu();
   int numberOfLegs = 0;
   Node<Leg> * head = NULL;
   Node<Leg> * endLeg = head;

   do
   {
      string sCity;
      string dCity;

      MileageData travelInfo;
      MileageMap map;
      char mode;

      
      getOption(option);
      
      convertOption(option);
      
      switch(option) // user interaction menu
      {
         case 'A': // add a trip
         {
            newLeg(sCity, dCity, travelInfo, map, mode, head, endLeg, numberOfLegs);
            break;
         }
         case 'L': // load a file
         {
            head = NULL;
            endLeg = head;
            string fileName = "";
            cout << "What file would you like to load?\n";
            
            cout << "file Name: ";
            cin.ignore(256, '\n');
            getline(cin, fileName);
            
            loadFile(fileName, numberOfLegs, head, endLeg);
            break;
         }
         case 'S': //save current trips
         {
            string fileName;
            cout << "Where would you like to save the Trip?\n";

            cout << "File Name: ";
            cin.ignore(256, '\n');
            getline(cin, fileName);

            saveFile(fileName, head, numberOfLegs);
            break;
         }
         case 'D': // display current trip
         {
            cout << endl;
            cout << "Start City           Start Date            Destination City       Arrival Date          Mode    Miles \n";
            cout << "-------------------- -------------------   --------------------   -------------------   -----   -----\n";
            for (Node<Leg>* curLeg = head; curLeg; curLeg = curLeg->getLink())
            {
               curLeg->getData().display();
            }
            cout << endl;
            break;
         }
         case 'M': // displays menu
         {
            displayMenu();
            break;
         }
         case 'C': // clears all nodes to start fresh
         {
            head = NULL;
            endLeg = head;
            break;
         }
         case 'Q': // quits the program
         {
            cout << "Have a good day!\n";
            return;
         }
      }
      cout << "How can we help you?\n";
   }
   while (true); // continues until the user puts in Q
}

int main() 
{
   cout << endl;
   cout << "*** Welcome to Celandir's Travel Agency. Hope we can be of assistance. ***\n";
   cout << endl;
   
   menu();
   

   return 0;
}
