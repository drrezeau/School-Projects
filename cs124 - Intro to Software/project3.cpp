/***********************************************************************
* Program:
*    Project 3, Grades Program 
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       This program will allow the user to create/edit a file that holds
*       file names, points and scores which will then allow him to change
*       any of those 3 or reset the score of an assignment. then it writes
*       the file again saving any changes to the file.
*
*
*    Estimated:  6.0 hrs   
*    Actual:     12.0 hrs
*       the hardest part for me was getting the file to read correctly
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 100 // sets MAX to 100
#define INVALID '*' // sets INVALID to *

/****************************************************************
 * this function will ask the user for the filename
 * getName(fileName)
 * PROMPT filename
 * GET filename
 ******************************************************************/
void getName(char fileName[])
{
   cout << "What is the filename of the grades file? ";
   cin >> fileName;
   return;
}

/*************************************************************
 * this function reads the file and saves it to the arrays
 * readFile(fileName, numbGrades, assignments, points, score)
 * IF file fails to open
 *      RETURN false
 * READ numbGrades
 * FOR
 *      READ assignments, points, score
 * IF file fails
 *      close file
 *      PUT Error in file
 *      RETURN false
 * close file
 * RETURN true
 *************************************************************/
bool readFile(char fileName[], int &numbGrades,
              char assignments[][256], int points[], int score[])
{
   ifstream fin(fileName);
   if (fin.fail())
      return false;
   fin >> numbGrades;
   for (int i = 0; i < numbGrades; i++)
      fin >> assignments[i] >> points[i] >> score[i];
   if (fin.fail())
   {
      fin.close();
      cout << "Error in file " << fileName << endl; // if file can not open
      return false;
   }
   fin.close();
   return true;
}

/*********************************************************
 * this function gets input of how many grades in the file
 * newGrades(numbGrades)
 * DO
 *      PROMPT user for numbGrades
 *      GET numbGrades
 * WHILE numbGrades < 0 OR numbGrades > MAX(100)
 * RETURN
 **********************************************************/
void newGrades(int &numbGrades)
{
   do
   {
  
      cout << "How many records are in the file? ";
      cin >> numbGrades;
   }
   while (numbGrades < 0 || numbGrades > MAX);
   return;
}

/*********************************************************
 * this function writes all the data to the file when prompted
 * writeFile(fileName, numbGrades, assignments, points, score)
 * IF file fails
 *      RETURN false
 * WRITE numbGrades
 * FOR i = 0; i < numbGrades; i++
 *      WRITE assignments, points, score
 * IF file fails
 *      close file
 *      RETURN false
 * close file
 * RETURN true
 *******************************************************/
bool writeFile(char fileName[], int numbGrades, char assignments[][256],
               int points[], int score[])
{
   ofstream fout(fileName);
   if (fout.fail())
      return false;
   fout << numbGrades << endl;
   for (int i = 0; i < numbGrades; i++)
   {
      fout << assignments[i] << " " << points[i] 
           << " " << score[i] << endl;
   }
   if (fout.fail())
   {
      fout.close();
      return false;
   }
   
   fout.close();
   return true;
}

/*****************************************************
 * this function asks the user to input the descriptions of
 * each assignment
 * getAssignments( assignments, numbGrades)
 * FOR i = 0; i < numbGrades, i++
 *      PUT Description for # 'i' :
 *      GET asisgnments[i]
 * RETURN
 ****************************************************/
void getAssignments(char assignments[][256],int numbGrades)
{
   for (int i = 0; i < numbGrades; i++)
   {
      cout << "Description for #" << i + 1 << ": ";
      cin >> assignments[i];
   }
   return;
}

/************************************************
 * this function computes the average of the entered grades
 * computeAverage(points, score, pointstotal, scoretotal, numbGrades)
 * FOR i = 0; i < numbGrades; i++
 *      scoretotal += score[i] * (points[i] / 100)
 *      pointstotal += points[i]
 * IF pointstotal == 0
 *      pointstotal = 1
 * RETURN (scoretotal / pointstotal) * 100
 ***********************************************/
int computeAverage(int points[], int score[], int &pointstotal,
                    int &scoretotal, int numbGrades)
{
   for (int i = 0; i < numbGrades; i++)
   {
      if (score[i] != -1)
      {
         scoretotal += score[i] * (points[i] / 100);
         pointstotal += points[i];
      }
   }
   if (pointstotal == 0)
      pointstotal = 1;
   
   return (int)(((float)scoretotal / (float)pointstotal) * 100.0);

}

/****************************************
 * this function computes what the letter grade is
 * computeLetter(average)
 * letterGrade[10] = F F F F F D C B A A
 * RETURN letterGrade[(average - 10) / 10)
 *****************************************/
char computeLetter(int average)
{
   char letterGrade[10] = {'F','F','F','F','F','D','C','B','A','A'};
   return letterGrade[(average - 10) / 10];
}

/******************************************************
 * this function computes the sign
 * computeSign(average, sign)
 * IF average % 10 <= 3
 *      sign = '-'
 * ELSE IF average % 10 >= 7
 *      sign = '+"
 * RETURN sign
 ***************************************************/
char computeSign(int average, char sign)
{
   if (average % 10 <= 3)
      sign = '-';
   else if (average % 10 >= 7)
      sign = '+';
   else
      sign = INVALID;
   return sign;
}
   
      
/**********************************************
 * this function displays the table with the total at the bottom
 * display(numbGrades, assignments, points, score)
 * PUT your grades are:
 * PUT  Number                Name       Points       Score
 * PUT  ====== =================== ============ ===========
 *FOR i = 0; i < numbGrades; i++
 *      PUT (the table)
 *      IF score == -1
 *              PUT --
 *      ELSE
 *              PUT score[i]%
 * PUT ======= =================== ============ ==========
 * PUT         total
 * IF sign != '*' && average > 60 && average < 95
 *      PUT sign
 * RETURN
 **********************************************/
void display(int numbGrades, char assignments[][256],
             int points[], int score[])
{
   char sign;
   int pointstotal = 0;
   int scoretotal = 0;
   int average = computeAverage(points, score, pointstotal, scoretotal,
                                numbGrades);
   cout << "Your grades are:\n";
   cout << "\tNumber" << setw(16) << "Name" << setw(7) << "Points"
        << setw(7) << "Score\n";
   cout << "\t====== =============== ====== =====\n";
   for (int i = 0; i < numbGrades; i++)
   {
      cout << "\t" << setw(6) << i + 1 << setw(16) << assignments[i]
           << setw(7) << points[i];
      if (score[i] == -1)
         cout << setw(6) << "--";
      else
         cout << setw(5) << score[i] << "%";
      cout << endl;
   }
   cout << "\t====== =============== ====== =====\n";
   cout << "\t" << setw(12) << "Total";
   if ( average < 1)
      cout << "                     --";
   else
      cout << setw(22) << average << "%";
   if (average > 0)
      cout << " " << computeLetter(average);
   sign = computeSign(average, sign);
   if (sign != '*' && average > 60 && average < 95)
      cout << sign;
   cout << endl;
   return;
}

/**************************************
 * this function allows the user to change the name 
 * of the assignment
 * changeName(number, assignments)
 * PROMPT new name
 * GET assignment[number - 1]
 * RETURN
 **************************************/
void changeName(int number, char assignments[][256])
{
   cout << "What is the new name: ";
   cin >> assignments[number - 1];
   return;
}

/***********************************************
 * this function allows the user to change amount of points
 * changePoints(number, points)
 * DO
 *      PROMPT new points
 *      GET points[number - 1]
 * WHILE points[number - 1] < 0
 * RETURN
***********************************************/
void changePoints(int number, int points[])
{
   do
   {
      cout << "What is the new points: ";
      cin >> points[number - 1];
   }
   while (points[number - 1] < 0);
   return;
}

/*********************************************************
 * this function lets users change the score of an assignment
 * changeScore(number, score, numbGrades)
 * DO
 *      PROMPT for new score
 *      GET new score
 * WHILE score[number - 1] > 100 OR score [number - 1] < 0
 * RETURN
 ******************************************************/
void changeScore(int number, int score[], int numbGrades)
{
   do
   {
      cout << "What is the new score: ";
      cin >> score[number - 1];
   }
   while ( score[number - 1] > 100 || score[number - 1] < 0);
   return;
}

/************************************************************
 * this clears a score of an assignment
 * clearScore(number, score)
 * SET score[number - 1] = -1
 * RETURN
 ********************************************************/
void clearScore(int number, int score[])
{
   while (number > 5 || number < 0);
   score[number - 1] = -1;
   return;
}

/**********************************************************
 * this function asks the user for what option to execute
 * getOption(option)
 * DO
 *      PUT >
 *      GET option
 * WHILE option != n  option != p option != s
 *       option != c option != d option != q 
 * RETURN
 ********************************************************/
void getOption(char &option)
{
   do
   {
      cout << "> ";
      cin  >> option;
   }
   while (option != 'n' && option != 'p' && option != 's'
          && option != 'c' && option != 'd'
          && option != 'q'); // while it is anything but the usable options
   return;
}

/****************************************************************
 * this function lets the user quit and calls writeFile
 * quit(fileName, numbGrades, assignments, points, score)
 * IF writeFile(fileName, numbGrades, assignments, points, score)
 *      PUT File saves successfully
 * ELSE PUT Error writing to file <fileName>
 * RETURN
 ************************************************************/
void quit(char fileName[], int numbGrades,
          char assignments[][256], int points[], int score[])
{
   if (writeFile(fileName, numbGrades, assignments, points, score))
      cout << "File saves successfully\n";
   else
      cout << "Error writing to file " << fileName; // if write fails
   return;
}

/*****************************************
 * this function asks the user what item to modify
 * getIndex(number)
 * DO
 *      PROMPT item to edit
 *      GET number
 * WHILE number > 5 OR number < 0
 * RETURN
 ***************************************/
void getIndex( int &number)
{
   do
   {
      cout << "Which item do you want to edit? ";
      cin >> number;
   }
   while (number > 5 || number < 0);
   return;
}

/*******************************************************************
 * this function lets the user interact with the program and allows
 * them to change things
 * interact(fileName, numbGrades, assignments, points, score)
 * PUT display(numbGrades, assignments, points, score)
 * DO
 *      PUT options
 *          (n) : Change the name of an item
 *          (p) : Change the number of points an item is worth
 *          (s) : Change the earned score on an item
 *          (c) : Clear the score on an item
 *          (d) : Display the grade list again
 *          (q) : Quit
 *      PUT getOption(option)
 *      IF option != q AND != d
 *          getIndex(number)
 *      SWITCH option
 *         CASE n
 *             PUT changeName(number, assignments)
 *         CASE p
 *              PUT changePoints(number, points)
 *         CASE s
 *              PUT changeScore(number, score, numbGrades)
 *         CASE c
 *              PUT clearScore(number, score)
 *         CASE d
 *              PUT display(numbGrades, assignments, points, score)
*         CASE q
*              PUT quit(fileName, numbGrades, assignments, points, score)
* WHILE (option != q)
* RETURN
********************************************************************/
void interact(char fileName[], int numbGrades,
              char assignments[][256],int points[], int score[])
{
   int number; // what number to edit
   char option; // user's option
   display(numbGrades, assignments, points, score);
   do
   {
      cout << "Options:\n"
           << "\t(n) : Change the name of an item\n"
           << "\t(p) : Change the number of points an item is worth\n"
           << "\t(s) : Change the earned score on an item\n"
           << "\t(c) : Clear the score on an item\n"
           << "\t(d) : Display the grade list again\n"
           << "\t(q) : Quit\n";
      getOption(option);
      if (option != 'q' && option != 'd')
         getIndex(number);
      switch (option)
      {
         case 'n': // changes assignment name
            changeName(number, assignments);
            break;
         case 'p': // changes point value
            changePoints(number, points);
            break;
         case 's': // changes score value
            changeScore(number, score, numbGrades);
            break;
         case 'c': // clears score value
            clearScore(number, score);
            break;
         case 'd': // displays
            display(numbGrades, assignments, points, score);
            break;
         case 'q': // quits
            quit(fileName, numbGrades, assignments, points, score);
      }
   }
   while (option != 'q');
   return;
}

/**********************************************************************
* this function holds the variables and calls the different functions
* getName(fileName)
* IF !readFile(fileName, numbGrades, assignments, points, score)
*       newGrades(numbGrades)
*       FOR i = 0; i < numbGrades; i++
*          point[i] = MAX
*          score[i] = -1
*       getAssignments(assignments, numbGrades)
* interact(fileName, numbGrades, assignments, points, score)
* RETURN 0
***********************************************************************/
int main()
{
   char fileName[256]; // name of file
   int numbGrades; // how many grades
   char assignments[MAX][256]; // array for assignment names
   int points[MAX]; // array for points
   int score[MAX]; // array for scores
   getName(fileName); // gets file name
   if (!readFile(fileName, numbGrades, assignments, points, score))
   {
      newGrades(numbGrades); //gets how many grades in the file
      for (int i = 0; i < numbGrades; i++) 
      {
         points[i] = MAX; //sets grades to 100
         score[i] = -1; //sets scores to -1
      }
      getAssignments(assignments, numbGrades); // gets assignment names
   }
   interact(fileName, numbGrades,
            assignments, points, score); //lets user interact
   return 0;
}
