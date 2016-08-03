/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 01, Hello World)  
*    Brother Helfrich, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 1024

void promptKeyWord(char adjPrompt[][32], int count);

bool readFile(char fileName[], char text[], int &numchars)
{
   ifstream fin(fileName);
   
   if(fin.fail())
      return false;
   
   for (int i = 0; i < MAX; i++)
   {
      fin >> text[i];
   }
   for (char *pText = text; *pText; pText++)
      numchars++;
   
   text[numchars + 1] = '\0';
   
   if (fin.fail())
   {
      fin.close();
      return false;
   }
   
   fin.close();
   return true;
}

void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   return;
}

void changeKeyword(char text[], int numchars, char adjPrompt[][32])
{
   int count = 0;
   for (int i = 0; i < numchars; i++)
   {
      if (text[i] == '<')
      {
         if (text[i + 1] == '#')
            text[i + 1] = '\n';
         else if (text[i + 1] == '{')
            text[i + 1] = '"';
         else if (text[i + 1] == '}')
            text[i + 1] = '"';
         else if (text[i + 1] == '[')
            text[i + 1] = '\'';
         else if (text[i + 1] == ']')
            text[i + 1] = '\'';
         else
         {
            count++;
            cout << '\t';
            text[i + 1] = toupper(text[i + 1]);
            for (int n = 0; n < 32 && text[i + n] != '>'; i++)
            {
               if ( text[n + i] == '_')
                  text[n+i] = ' ';
               
               else if ( text[n + i] != '<')
                  cout << text[i + n];
            }
            cout << ':';
            promptKeyWord(adjPrompt, count);
            
         }
      }
   }
}

void promptKeyWord(char adjPrompt[][32], int count)
{
   for ( int i = 0; i < count; i++)
   cin.getline(adjPrompt[count], 32);
   return;

}

/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOOSE POINTS.
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
   for (int i = 0; i < numchars; i++)
   {
      if (text[i] == ' ')
         cout << ' ';
      cout << text[i];
   }
   cout << endl;
   return 0;
}
