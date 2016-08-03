/***********************************************************************
* Program:
*    Project 5, Sudoku
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*   This program will allow the user to open a sudoku file and then 
*   interact with it and change the values of squares
*   (I think it follows the rules)
*   (also can't show the possible values)
*    Estimated:  6.0 hrs   
*    Actual:     6.0 hrs
*      getting the rules to work and the program to show possible values
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 82 // sets MAX to 82 b/c thats how many a sudoku file 
               // needs

/****************************************************
 * this function gets the filename
 * getFileName(fileName)
 * PROMPT where is board located
 * GET fileName
 * RETURN
 ***************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
   return;
}

/************************************************
 * this function reads the file into the square array
 * readFile(fileName, square)
 * OPEN fileName
 * IF fin.fail
 *    RETURN false
 * FOR i = 0; i < MAX; i++
 *    READ square[i]
 * SET square[MAX] = null character
 * IF fin.fail
 *   fin.close
 *   RETURN false
 * fin.close
 * RETURN true
 ************************************************/
bool readFile(char fileName[], int square[])
{
   ifstream fin(fileName); // opens file
   if (fin.fail())
      return false;
   
   for (int i = 0; i < MAX - 1; i++)
      fin >> square[i]; // reads the values in the file into square array
   square[MAX] = '\0'; // sets to end of file character
   
   if (fin.fail())
   {
      fin.close();
      return false;
   }
   
   fin.close();
   return true;
}

/**********************************************
 * this function displays the sudoku on the screen 
 * when prompted to
 * display(square)
 * SET count = 1
 * PUT A B C D E F G H I 
 * PUT 1  
 * FOR i = 0; i < MAX; i++
 *     IF i == 10 OR i == 19 OR i == 28 OR i == 37 OR i == 46 OR
 *        i == 55 OR i == 64 OR i == 73
 *        IF count == 3 OR count == 6
 *           PUT -----+-----+-----
 *        count++
 *        PUT count  
 *     IF i % 9 == 0
 *        IF square [i - 1] == 0
 *           PUT ' ' 
 *        ELSE
 *           PUT square[i - 1]
 *     ELSE IF square[i - 1] == 0
 *        IF i % 3 == 0
 *           PUT ' |'
 *        ELSE
 *           PUT '  '
 *     ELSE IF i % 3 == 0
 *        PUT square[i - 1]|
 *     ELSE
 *        PUT square[i - 1] 
 * RETURN
 **********************************************/
void display(int square[])
{
   int count = 1;
   cout << "   A B C D E F G H I\n"; // header
   cout << "1  "; // starts the side numbering
   for (int i = 1; i < MAX; i++)
   {
      if (i == 10 || i == 19 || i == 28 || i == 37 || i == 46 ||
          i == 55 || i == 64 || i == 73)
      {
         if (count == 3 || count == 6)
         {
            cout << "   -----+-----+-----\n";
         }
         count++;
         cout << count << "  ";
      }
      if (i % 9 == 0) // end of sudoku
      {
         if (square[i - 1] == 0)
            cout << " " << endl;
         else 
            cout << square[i - 1] << endl;
      }
      else if (square[i - 1] == 0)
      {
         if ( i % 3 == 0) // middle of sudoku
            cout << " |";
         else
            cout << "  ";
      }
      else if (i % 3 == 0) // middle of sudoku
         cout << square[i - 1] << "|";
      else
         cout << square[i - 1] << " ";
   }
   cout << endl;
   return;
}

/*********************************************
 * this option prompts the user for their option
 * getOption(option)
 * PUT > 
 * GET option
 * RETURN option
 ********************************************/
char getoption(char option)
{
   cout << "> ";
   cin >> option;
   return option;

}

/*********************************************************
 * this function changes the value the to the what the user puts in
 * changeValue(square, row, column, number)
 * IF square[9 * row - number] != 0
 *    PUT square column row is filled
 * ELSE
 *    PUT what is the value at 'A row ':
 *    GET square[9 * row - number]
 *    FOR i = 0; i < 9; i++
 *        IF square[9 * (row -1) + 1] == valueSquare OR
 *           square[9 * (i + 1) - number] == valueSquare
 *              PUT ERROR  Value valueSquare in square column
 *              row is invalid 
 *              RETURN
 * square[ 9 * row - number] = valueSquare
 * RETURN
 *********************************************************/
void changeValue(int square[],int row, char column, int number)
{
   int valueSquare = 0;
   if (square[(9 * row) - number] != 0) // determines if number is already there
      cout << "ERROR: Square '" << column << row << "' is read-only\n";
   else
   {
      cout << "What is the value at '" << column << row << "': ";
      cin >> valueSquare;
      for (int i = 0; i < 9; i++)
      {
         if (square[9 *  (row - 1) + i] == valueSquare ||
             square[(9 * (i + 1)) - number] == valueSquare) // cycles through row
         {                                                  // and column to check
            cout << "ERROR: Value '" << valueSquare << "' in square '" // for number
                 << column << row << "' is invalid\n";
            return;
         }
      }
      square[9 * row - number] = valueSquare; // saves value if its not in row or column
   }
   return;
}

/*********************************************
 * this function edits a square the users wants to edit
 * editSquare(square)
 * SET column
 * SET row = 0
 * PROMPT user for what square to edit
 * GET column row
 * SET A = 1
 * SET B = 2
 * SET C = 3
 * SET D = 4
 * SET E = 5
 * SET F = 6 
 * SET G = 7
 * SET H = 8
 * SET I = 9
 * SET column = toupper(column)
 * IF row > 9 OR row < 0
 *    PUT ERROR: Square column row is read-only
 * ELSE
 *   IF column == 'A'
 *     PUT changeValue(square, row, column, I)
 *   ELSE IF column == 'B'
 *     PUT changeValue(square, row, column, H)
 *   ELSE IF column == 'C'
 *     PUT changeValue(square, row, column, G)
 *   ELSE IF column == 'D'
 *     PUT changeValue(square, row, column, F)
 *   ELSE IF column == 'E'
 *     PUT changeValue(square, row, column, E)
 *   ELSE IF column == 'F'
 *     PUT changeValue(square, row, column, D)
 *   ELSE IF column == 'G'
 *     PUT changeValue(square, row, column, C)
 *   ELSE IF column == 'H'
 *     PUT changeValue(square, row, column, B)
 *   ELSE IF column == 'I'
 *     PUT changeValue(square, row, column, A)
 * RETURN
**********************************************/
void editSquare(int square[])
{
   char column;
   int row = 0;
   
   cout << "What are the coordinates of the square: ";
   cin >> column >> row; // gets what column and row
   const int A = 1;
   const int B = 2;
   const int C = 3;
   const int D = 4;
   const int E = 5;
   const int F = 6; 
   const int G = 7;
   const int H = 8;
   const int I = 9;
   column = toupper(column);
   if (row > 9 || row < 0) //error checking
      cout << "ERROR: Square '" << column << row << "' is read-only\n";
   else
   {
      if (column == 'A')
      {
         changeValue(square, row, column, I); //letter is part of equation
      }
      else if (column == 'B')
      {
         changeValue(square, row, column, H);
      }
      else if (column == 'C')
      {
         changeValue(square, row, column, G);
      }
      else if (column == 'D')
      {
         changeValue(square, row, column, F);
      }
      else if (column == 'E')
      {
         changeValue(square, row, column, E);
      }
      else if (column == 'F')
      {
         changeValue(square, row, column, D);
      }
      else if (column == 'G')
      {
         changeValue(square, row, column, C);
      }
      else if (column == 'H')
      {
         changeValue(square, row, column, B);
      }
      else if (column == 'I')
      {
         changeValue(square, row, column, A);
      }
   }
   cout << endl;
   return;  
}

/***************************************************
 * this is suppose to show possible values.
 * showValues(square)
 * SET column
 * SET row
 * PROMPT for the coordinates
 * GET column row
 * SET column = toupper(column)
 * FOR iColumn = 9; iColumn > 0; iColumn--
 *     IF square[9 * iColumn - 9] != 0
 *        PUT square[9 * iColumn - 9]
 * RETURN
 ***************************************************/
void showValues(int square[])
{
   char column;
   int row = 0;
   
   cout << "What are the coordinates of the square: ";
   cin >> column >> row;

   column = toupper(column);
   
   for ( int iColumn = 9; iColumn > 0; iColumn--)
   {
      if (square[9 * iColumn - 9] != 0)
         cout << square[9 * iColumn - 9] << ", ";
   }
   cout << endl;
   return;
}

/*********************************************
 * this function writes the array to a new file
 * writeFile(square)
 * PROMPT for fileName
 * GET fileName
 * OPEN fileName
 * IF fin.fail 
 *    RETURN false
 * FOR i = 1; i < MAX; i++
 *    IF i % 9 == 0 && i != 0
 *       WRITE square[i - 1] ENDL
 *    ELSE 
 *       WRITE square[i - 1] ' '
 * IF fout.fail
 *    fout.close
 *    RETURN false
 * fout.close
 * RETURN true
 *******************************************/
bool writeFile(int square [])
{
   char fileName[256];
   
   cout << "What file would you like to write your board to: ";
   cin >> fileName;
   
   ofstream fout(fileName); //opens file
   if (fout.fail())
      return false;
   for (int i = 1; i < MAX; i++)
   {
      if ( i % 9 == 0 && i != 0)
         fout << square [i - 1] << endl; // reads array to file
      else
         fout << square[i - 1] << " ";
   }
   if (fout.fail())
   {
      fout.close();
      return false;
   }
   fout.close();
   return true;
   
}

/********************************************
 * this function allows the user to quit and save
 * quit(square)
 * PUT writeFile(square)
 * RETURN
 *******************************************/
void quit(int square[])
{
   writeFile(square);
   return;

}

/*********************************************
 * this function shows the options available to the user
 * showOptions
 * PUT ?  Show these instructions
 *     D  Display the board
 *     E  Edit one square
 *     S  Show the possible values for a square
 *     Q  Save and Quit
 * RETURN
 ********************************************/
void showOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n";
   cout << endl;
   return;
}

/*********************************************
 * this function lets the user interact with the program
 * interact(fileName, square)
 * SET option = a
 * PUT showOptions
 * ENDL
 * DO
 *   option = getoption(option)
 *   option = toupper(option)
 *   SWITCH
 *        CASE '?':
 *            PUT showOptions
 *        CASE 'D':
 *            PUT display(square)
 *        CASE 'E':
 *            PUT editSquare(square)
 *        CASE 'S':
 *            PUT showValues(square)
 *        CASE 'Q':
 *            PUT quit(square)
 *        DEFAULT:
 *            PUT ERROR: Invalid command
 * WHILE option != 'q'
 * RETURN
 ********************************************/
void interact(char fileName[], int square[])
{
   
   char option = 'a';
   showOptions();
   display(square);
   do
   {
      option = getoption(option); //gets option
      option = toupper(option);
      
      switch (option)
      {
         case '?': // directions
            showOptions();
            break;
         case 'D': // display
            display(square);
            break;
         case 'E': //edit
            editSquare(square);
            break;
         case'S': // show
            showValues(square);
            break;
         case 'Q': // quit 
            quit(square);
            break;
         default: //anything that isnt a valid command
            cout << "ERROR: Invalid command\n";
            break;
      }
   }
   while ( option != 'Q'); // keeps going until quit
   return;
}

/**********************************************************************
* this function holds all the variables and calls the other functions
* main
* SET square
* SET fileName
* PUT getFileName(fileName)
* PUT readFile(fileName, square)
* PUT interact(fileName, square) 
* RETURN 0
***********************************************************************/
int main()
{
   int square[MAX]; // array that holds the sudoku numbers
   char fileName[256]; // holds filename
   getFileName(fileName); // calls get filename
   readFile(fileName, square); // reads file
   interact(fileName, square); // lets user interact
   
   return 0; //ends program
}
