/***********************************************************************
* Program:
*    Project 4, Mad Lib 
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*   this program allows the user to open a file for mad lib
*   and lets them fill it out.(does not work properly)
*
*    Estimated:  4.0 hrs   
*    Actual:     7.0 hrs
*     getting it to display properly
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 1024 // sets MAX to 1024

void promptKeyWord(char adjPrompt[][32], int count);

/*******************************************
 * this function will read a file to an array
 * readFile(fileName, text, numchars)
 * OPEN fileName
 * IF fin.fail()
 *      RETURN false
 * FOR i = 0; i < MAX; i++
 *      READ text[i]
 * FOR *pText = text; *pText; pText++
 *      numchars++
 * SET text[numchars + 1] = 0
 * IF fin.fail()
 *      RETURN false
 * fin.close()
 * RETURN true
 ********************************************/
bool readFile(char fileName[], char text[], int &numchars)
{
   ifstream fin(fileName);
   
   if (fin.fail())
      return false;
   
   for (int i = 0; i < MAX; i++)
   {
      fin >> text[i]; // reads file into array
   }
   
   for (char *pText = text; *pText; pText++)
      numchars++; // number of characters in array
   
   text[numchars + 1] = '\0'; // sets last value to null
   
   if (fin.fail())
   {
      fin.close();
      return false;
   }
   
   fin.close();
   return true;
}

/********************************************
 * this file prompts the user for the file name
 * getFileName(fileName)
 * PROMPT fileName
 * GET fileName
 * RETURN
 ********************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName; // gets file name
   return;
}

/********************************************************
 * this function finds and changes the keywords
 * changeKeyword(text, numchars, adjPrompt)
 * SET count = 0
 * FOR int i = 0; i < numchars; i++
 *      IF text[i] == '<'
 *         IF text[i + 1] == '#'
 *             text[i + 1] = '\n'
 *         ELSE IF text[i + 1] == '{'
 *             text[i + 1] = '"'
 *         ELSE IF (text[i + 1] == '}'
 *             text[i + 1] = '"'
 *         ELSE IF (text[i + 1] == '['
 *             text[i + 1] = '\''
 *         ELSE IF (text[i + 1] == ']' 
 *             text[i + 1] = '\''
 *         ELSE
 *             PUT tab
 *             SET text[i + 1] = UPPER(text[i + 1])
 *             FOR int n = 0; n < 32 && text[i + n] != '>'; i++
 *                IF  text[n + i] == '_'
 *                   SET text[n + i] = ' '
 *                ELSE IF  text[n + i] != '<'
 *                   PUT text[i + n]
 *             PUT :
 *             SET count++
 *             PUT promptKeyWord(adjPrompt, count)
 * RETURN
 ********************************************************/
void changeKeyword(char text[], int numchars, char adjPrompt[][32])
{
   int count = 0; //number of Adjectives
   for (int i = 0; i < numchars; i++)
   {
      if (text[i] == '<')
      {
         if (text[i + 1] == '#') //changes # to a new line
            text[i + 1] = '\n';
         else if (text[i + 1] == '{') // changes { to :
            text[i + 1] = '"';
         else if (text[i + 1] == '}') // changes } to "
            text[i + 1] = '"';
         else if (text[i + 1] == '[') // changes [ to '
            text[i + 1] = '\'';
         else if (text[i + 1] == ']') // changes ] to '
            text[i + 1] = '\'';
         else // displays word, and asks user to fill it in
         { 
            cout << '\t';
            text[i + 1] = toupper(text[i + 1]); // uppercase
            for (int n = 0; n < 32 && text[i + n] != '>'; i++)
            {
               if ( text[n + i] == '_')
                  text[n + i] = ' ';
               
               else if ( text[n + i] != '<')
                  cout << text[i + n];
            }
            cout << ": ";
            count++;
            promptKeyWord(adjPrompt, count); // gets filler
         }
      }
   }
   return;
}

/**************************************************
 * this function asks the user for the keyword filler
 * promptKeyword(adjPrompt, count)
 * FOR int n = count - 1; n < count; n++)
 *      GET adjprompt[32]
 * RETURN
 ************************************************/
void promptKeyWord(char adjPrompt[][32], int count)
{
   for (int n = count - 1; n < count; n++)
   {
      cin.getline(adjPrompt[n], 32);
   }
   return;

}

/*****************************************
 * this displays the mad lib.
 * display(text, adjPrompt, numchars)
 * FOR int i = 0; i < numchars; i++
 *      IF text[i] == '<'
 *         SET text[i] = ' '
 *      IF text[i] == '>'
 *         SET text[i] = ' '
 *      PUT text[i]
 * PUT new line
 * RETURN
 ******************************************/
void display(char text[], char adjPrompt[][32], int numchars)
{
   for (int i = 0; i < numchars; i++)
   {
      if (text[i] == '<')
      {
         text[i] = ' ';
      }
      if ( text[i] == '>')
         text[i] = ' ';
      cout << text[i];
   }
   cout << endl;
}

/**********************************************************************
* this function holds all the variables used in the lab and calls the other
* functions.
* main()
* fileName
*text
*numchars
**pText
*adjPrompt
* PUT getFileName(fileName)
* PUT readFile(fileName, text, numchars) 
* PUT changeKeyword(text, numchars, adjPrompt)
* PUT display(text, adjPrompt, numchars)
* RETURN 0
***********************************************************************/
int main()
{
   char fileName[256];
   char text[MAX];
   int numchars = 0;
   char *pText = NULL;
   char adjPrompt[256][32];
   getFileName(fileName);
   readFile(fileName, text, numchars);
   changeKeyword(text, numchars, adjPrompt);
   display(text, adjPrompt, numchars);
   return 0;
}
