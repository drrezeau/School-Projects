/***********************************************************************
* Program:
*    Assignment 17, Ten Grades Revisited
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will ask the use to input 10 different grades
*       and then will calculate the average grade and display it.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.3 hrs
*    the hardest part of this program was getting average right.
************************************************************************/

#include <iostream>
using namespace std;

/********************************************
 * this will ask the user to input the grades
 *******************************************/
int getGrades(int grade[10], int numberofgrades, int &gradesentered)
{
   int total = 0;
   for (int i = 0; i < numberofgrades; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grade[i];
      if (grade[i] < 0)
         gradesentered--;
      else
      {
         total += grade[i];
      }
   }
   return total;
}

/*************************************************************
 * this will average the grades.
 ************************************************************/
int averageGrades(int grade[10], int numberofgrades, int gradesentered)
{
   int total = getGrades(grade, numberofgrades, gradesentered);
   if (gradesentered == 0)
      gradesentered = 1;
   int averagegrade = total / gradesentered;
   return averagegrade;
}

/**********************************************************************
* main will call getGrades, and then averageGrades and will display the
* average grade.
***********************************************************************/
int main()
{
   int grade[10];
   int numberofgrades = 10;
   int gradesentered = 10;
   int average = averageGrades(grade, numberofgrades, gradesentered);
   if (average > 0)
      cout << "Average Grade: " << average << "%" << endl;
   else
      cout << "Average Grade: ---%" << endl;
   return 0;
}
