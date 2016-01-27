/***********************************************************************
* Program:
*    Assignment 16, Ten Grades        
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will ask the use to input 10 different grades
*       and then will calculate the average grade and display it.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.3 hrs
*    the hardest part was figuring out the array.
************************************************************************/

#include <iostream>
using namespace std;

/********************************************
 * this will ask the user to input the grades
 *******************************************/
int getGrades(int grade[10], int numberofgrades)
{ int total = 0;
   for (int i = 1; i <= numberofgrades; i++)
   {
      cout << "Grade " << i << ": ";
      cin >> grade[i];
      total += grade[i];
   }
   return total;
}

/*************************************************************
 * this will average the grades.
 ************************************************************/
int averageGrades(int total)
{
   int averagegrade = total / 10;
   return averagegrade;
}

/**********************************************************************
* main will call getGrades, and then averageGrades and will display the
* average grade.
***********************************************************************/
int main()
{
   int i = 10;
   int grade[10];
   int numberofgrades = 10;
   int total = getGrades(grade, numberofgrades);
   int average = averageGrades(total);
   cout << "Average Grade: " << average << "%" << endl;
   return 0;
}
