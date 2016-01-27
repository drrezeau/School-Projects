/***********************************************************************
* Program:
*    Assignment 19, Letter Grade from Number Grade 
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    this program allows the user to input a grade and it will return
*    the grade with what letter grade.
*    Estimated:  0.45 hrs   
*    Actual:     0.3 hrs
*      getting switch to work
************************************************************************/

#include <iostream>
using namespace std;

/*************************************
 * this changes the number grade to letter grade
 ************************************/
char computeLetterGrade(int grade)
{
   char letterGrade[10] = {'F','F','F','F','F','D','C','B','A','A'};
   if (grade == 0)
      grade = 10;
   return letterGrade[(grade - 10) / 10];
}

/**********************************************************************
* main calls computeLetterGrade and then displays the grade and what letter
***********************************************************************/
int main()
{
   int grade;
   cout << "Enter number grade: ";
   cin >> grade;
   cout << grade << "% is " << computeLetterGrade(grade);
   if (grade % 10 >= 7 && grade > 60 && grade < 90)
      cout << "+";
   else if (grade % 10 <= 2 && grade > 60 && grade < 90)
      cout << "-";
   
   return 0;
}
