/**********************************
* Program:
*    Assignment 03, Student Database
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
* this function lets the user input a filre
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
   ifstream fin(fileName);
   do
   {
      
      if (fin.fail())
      {
         fin.close();
         cout << "Error loading file.";
      }
      else
      {
         cout << "Loading File..." << endl;
         fin >> numberStudents;
         for (int i = 0 ; i < numberStudents; i++)
         {
            fin >> group[i].firstName;
            fin >> group[i].lastName;
            fin >> group[i].id;
         }
      }
      
   }
   while (fin.fail());

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
   cout << group[i].id << " - " << group[i].lastName << ", " << group[i].firstName << endl;
   return;
}
   
/*************************
* this program asks the user for the last name
* and then checks for matching last names.
************************/
void getLastName(char lastName[], int numberStudents, Student group[])
{
   while (lastName != "quit")
   {
      cout << endl;
      cout << "Enter last name: ";
      cin >> lastName;
      char quit[5] = "quit";
      if (strcmp(lastName, quit) != 0)
      {
        
      }
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
   getFileName(fileName);
   readFile(group, fileName, numberStudents);
   getLastName(lastName, numberStudents, group);


   return 0;
}
