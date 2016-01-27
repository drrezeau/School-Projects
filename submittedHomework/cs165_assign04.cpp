/**********************************
* Program:
*    Assignment 04, Student Database
*    Brother Burton, CS 165
* Author: 
*    David Lambertson
* Summary:
*    this program will ask the user to input a file name
*    and then will read the information into a structure
*    and will then let the user input a last name and display
*    the students with that last name. 
**********************************/
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

/*********************
* This creates a structure named Student
* creating a variable to store student info.
***********************/
struct Student
{
   char firstName[50];
   char lastName[50];
   int id;
};

/**************************
* this function lets the user input a file
* name.
************************/
void getFileName(char fileName[])
{
   cout << "Please enter the data file: ";
   cin >> fileName;
   return;
}

/*****************************
* this file reads the file into 
* the structure.
**************************/
bool readFile(Student group[], char fileName[], int &numberStudents)
{
   getFileName(fileName);
   ifstream fin(fileName);
   if (fin.fail())
   {
      fin.close();
      throw 3;
   }
   else
   {
      cout << "Loading File..." << endl;
      fin >> numberStudents;
      fin.ignore(256, '\n');
      char line[256];
      for (int i = 0 ; i < numberStudents; i++)
      {
         try
         {
            fin.getline(line, 256);
            stringstream ss(line);
            ss >> group[i].firstName;
            ss >> group[i].lastName;
            ss >> group[i].id;
            if (ss.fail())
            {
               throw "Error parsing the following record: ";
            }
         }
         catch (const char * message)
         {
            cout << message << '\'' << line << '\''
                 << ". It will be skipped." << endl;
         }
      }
   }
   
   
   fin.close();
   
   cout << "Done loading file." << endl;
   
   return true;
}

/************************
* this program displays when a the lastname entered
* matches a students last name.
********************/
void displayStudent(const Student group[], int i)
{
   cout << group[i].id << " - " << group[i].lastName
        << ", " << group[i].firstName << endl;
   return;
}
   
/*************************
* this program asks the user for the last name
* and then checks for matching last names.
************************/
void getLastName(char lastName[], int numberStudents, Student group[])
{
   while (true)
   {
      int notStudent = 0;
      cout << endl;
      cout << "Enter last name: ";
      cin >> lastName;
      
      char quit[5] = "quit";
      
      for (int i = 0;  i < numberStudents; i++)
      {
         if (strcmp(lastName, group[i].lastName) == 0)
         {
            displayStudent(group, i);
         }
         else if (strcmp(lastName, quit) == 0)
         {
            cout << "Goodbye" << endl;
            return;
         }
         else
         {
            notStudent++;
         }
      }
      
      if (notStudent == numberStudents)
      {
         cout << "No match found." << endl;
      }
   }
}

/*******************
* this function is main and calls
* the rest of functions into action.
*******************/
int main()
{
   int numberStudents = 1;
   char fileName [100];
   Student group[numberStudents];
   char lastName[100];
   bool failed;
   do
   {
      failed = false;
      try
      {
         readFile(group, fileName, numberStudents);
      }
      catch (int num)
      {
         cout << "Error opening file." << endl;
         failed = true;
      }
   }
   while (failed);
   getLastName(lastName, numberStudents, group);

   return 0;
}
