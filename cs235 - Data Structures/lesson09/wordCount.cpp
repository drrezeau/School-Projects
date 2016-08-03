/***********************************************************************
 * Module:
 *    Lesson 09, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins and David Lambertson
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/
#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <fstream>
using namespace std;
void readFile(Map <string, Count> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   string fileName;
   string word;
   Map<string, Count> occur;
   
   cout << "What is the filename to be counted? ";
   cin  >> fileName;

   cout << "What word whose frequency is to be found. Type ! when done\n";

   readFile(occur, fileName);

   //to get a word for word frequency from user
   do
   {
      cout << "> ";
      cin  >> word;
      
      cout << "\t" << word << " : " << (occur[word]).getCount() << endl;
   }
   while(word != "!");
   
}

/****************************************
 * this function reads in the words of the file
 * and if finds a repeat, just increments Count
 ***************************************/
void readFile(Map <string, Count> & counts, const string & fileName)
{
   //open the file to be read
   ifstream fin(fileName.c_str());
   if(fin.fail())
      cout << "FAIL";

   Count num;   //to hold the amount of times a word is found
   string word; //to read in each word
   fin >> word;
   while(!fin.eof())
   {
      MapIterator<string, Count> it; //NULL check

      //if we have a new word
      if(it == counts.find(word))
      {
         num = 1;                    //initial count of word
         counts[string(word)] = num; //set Count to word
      }
      //add to Count of the word we already have
      else
      {   
         num = *(counts.find(word)); //Count becomes count of word
         ++num;                      //increase Count
         counts[word] = num;         //set Count to word
      }
      //get next word
      fin >> word;
   }
   
   fin.close();
}


