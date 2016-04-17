/***********************************************************************
* Program:
*    Test 5, Find a word in a file
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*    this lets the user input words on either the command line or within
*    the program and then will check to see if that word is in the 
*    specified file.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      the hardest part for me was to check the word given to the file.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*****************************************
 * this function gets the fileName
 ****************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   return;
}

/************************************************
 * this function asks the user for the word
 * to look for
 ************************************************/
void getWord(char *word)
{
   cout << "Please enter the word to search for: ";
   cin >> word;
   return;
}

/*****************************************************
 * this function takes the filename and reads what 
 * is in the file to the array file.
 ****************************************************/
bool readFile(char fileName[], char *file, char *word)
{
   ifstream fin(fileName);
   if (fin.fail())
      return false;
   for (int i = 0; i < 254; i++)
   {
      fin >> file;
   }
   
   if (fin.fail())
   {
      fin.close();
      return false;
   }

   return true;
}

/***************************************************
 * this function checks the word to what was read
 * from readFile.
 ***************************************************/
bool checkWord(char word[], char file[])
{
   if (*word == *file)
      return true;
   return false;
}

/**********************************************************************
* this function called main holds all the variables and calls the other
* functions to perform their tasks depending on what the user gave in
* the command line.
***********************************************************************/
int main(int countArguments, char *listArguments[])
{
   char fileName[256];
   char word[256];
   char file[256];

   if (countArguments != 2 && countArguments != 3) 
      getWord(word);

   if (countArguments != 3)
      getFileName(fileName);
   if (countArguments == 2) // do this when countArguments = 2
   {
      readFile(fileName, file, listArguments[1]);
      if (checkWord(word, file))
         cout << "the word \"" << *listArguments[1]
              << "\" is in " << fileName << endl;
      else
         cout << "The word \"" << *listArguments[1]
              << "\" is not in " << fileName << endl;
   }
   if (countArguments == 3) // do this if countArguments = 3
   {
      readFile(listArguments[2], file, listArguments[1]);
      if (checkWord(word, file))
         cout << "the word \"" << *listArguments[1]
              << "\" is in " << *listArguments[2] << endl;
      else
         cout << "The word \"" << *listArguments[1]
              << "\" is not in " << *listArguments[2] << endl;
   }
   if (countArguments == 1) // do this if countArguments = 1
   {
      readFile(fileName, file, word);
      if (checkWord(word, file))
         cout << "the word \"" << word << "\" is in " << fileName << endl;
      else
         cout << "The word \"" << word << "\" is not in " << fileName << endl;
   }
   return 0;
}
