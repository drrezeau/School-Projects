/***********************************************************************
* Program:
*    test 3, fix the text  
*    Brother Helfrich, CS124
* Author:
*    david Lambertson
* Summary: 
*   reads a file
*
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
* everything
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
/************************88
 *this gets file name
 ************************/
char getFileName(char fileName[])
{
   cout << "Please specify the file name: ";
   cin >> fileName;
}
/**************************8
 * this reads the file in
 ******************/

bool readFile(char fileName[], char text[MAX], int &numletters)
{
   ifstream fin;
   fin.open(fileName);
   if (fin.fail())
   {
      cout << "Unable to open the file " << fileName << endl;
      return false;
   }
   for ( int i = 0; i < MAX; i++)
   {
      fin >> text[i];
      if(text[i] > 45 && text[i] != '.')
         numletters++;
      else
         ;
   }
   return true;
}
/******************88
 * this displays it
 ******************/
void display(char text[], int numletters)
{
   cout << "There are " << numletters << " letters in the file.\n";
   cout << "The word is \"";
   for ( int i = 0; i < numletters; i++)
   {
      if ( text[i] > 45)
         cout << text[i];
      cout << "\"" << endl;
   }
   return;
}

/**********************************************************************
* calls all the functions
*
***********************************************************************/
int main()
{
   char fileName[256];
   char text[MAX];
   int numletters = 0;
   getFileName(fileName);
   if (readFile(fileName, text, numletters))
      display(text, numletters);
   return 0;
}
