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
#include <fstream>
using namespace std;

bool readFile(char filename1[256], int grade[10])
{
   ifstream fin;
   fin.open(filename1);
   if(fin.fail())
      return false;
   for(int i = 0; i < 10; i++)
   {
      fin >> grade[i];
   }
   fin.close();
   return true;
}

/*************************************************************
 * this will average the grades.
 ************************************************************/
int averageGrades(int grade[10], int numberofgrades, int gradesentered)
{
   int total = 0;
   for( int i = 0; i < numberofgrades; i++)
   {
      if (grade[i] == -1)
         gradesentered--;
      total += grade[i];
   }
   int averagegrade = total / gradesentered;
   return averagegrade;
}

bool writeFile(int grade[10], char filename2[])
{
   ofstream fout;
   fout.open(filename2);
   for(int i = 0; i < 10; i++)
      fout << grade[i] << " ";
   fout.close();
   return true;
}

/**********************************************************************
* main will call getGrades, and then averageGrades and will display the
* average grade.
***********************************************************************/
int main()
{
   char filename[256];
   cout << "Source file: ";
   cin >> filename;
   int grade[10];
   readFile(filename, grade);
   int numberofgrades = 10;
   int gradesentered = 10;
   int average = averageGrades(grade, numberofgrades, gradesentered);
   if (average > 0)
      cout << "Average Grade: " << average << "%" << endl;
   else
      cout << "Average Grade: ---%" << endl;
   cout << "Destination file: ";
   cin >> filename;
   writeFile(grade, filename);
   return 0;
}
