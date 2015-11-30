/***********************************************************************
 * Module:
 *    Lesson 11, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Derek Calkins and David Lambertson
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "hash.h"
#include "vector.h"
using namespace std;

/****************************************
 * The class for our dictionary Hash. Is-a Hash.
 *****************************************/
class dictHash : public Hash <string>
{
public:
   dictHash(int numBuckets) throw (const char *) : Hash<string> (numBuckets) {}
   dictHash(const dictHash & rhs) throw (const char *) : Hash<string> (rhs)  {}

   //the hash algorithm for sorting the dictionary into the hash
   int hash(const string & s) const
   {
      int value = 0;
      for(const char * p = s.c_str(); *p; p++)
      {
         //tries to randomize the most common letters more than others 
         if(*p == 'a' || *p == 'b' || *p == 'c' || *p == 'd' ||
            *p == 'e' || *p == 'f' || *p == 'm' || *p == 'p' ||
            *p == 's' || *p == 'r' || *p == 't' || *p == 'w')
            value += (*p / 2);
         else
            value += *p;
      }
      return value % capacity();
   }

};

//prototypes for functions we use in spellCheck
void readDictionary(dictHash & dictionary);
string toLower(string temp);

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   dictHash dictionary(140);
   string fileName;
   cout << "What file do you want to check? ";
   cin >> fileName;

   readDictionary(dictionary);

   ifstream fin(fileName.c_str());
   if(fin.fail())
   {
      cout << "FAIL!!\n";
      return;
   }

   Vector <string> misSpelled;
   string word;

   //we check if the word is spelled as we read through the file
   fin >> word;
   while(!fin.eof())
   {
      //if word is not found in the dictionary
      if(!(dictionary.find(word)))
      {
         //we lower the entire word and save it in a temp string
         string temp = toLower(word);

         //we check again if its in the dictionary
         if(!(dictionary.find(temp)))
         {
            //if so, we save it into a vector of mispelled words.
            misSpelled.push_back(word);
         }
      }
      //continue onto the next word
      fin >> word;
   }

   fin.close();

   //if we have any misspelled words display them
   if(misSpelled.size())
   {
      cout << "Misspelled: ";
      for(int i = 0; i < misSpelled.size(); ++i)
      {
         cout << misSpelled[i] << (misSpelled.size() - 1 == i ? "\n" : ", ");
      }
   }
   //otherwise just tell the user no misspelled words
   else
      cout << "File contains no spelling errors\n";
}

/******************************************************
 * read the dictionary into our hash to use in comparing
 *****************************************************/
void readDictionary(dictHash & dictionary)
{
   string dictionaryFile = "/home/cs235/lesson11/dictionary.txt";

   ifstream fin(dictionaryFile.c_str());
   if(fin.fail())
   {
      cout << "CANT READ!!!";
      return;
   }

   string word;
   fin >> word;
   while(!fin.eof())
   {
      dictionary.insert(word);
      fin >> word;
   }
   
   fin.close();
}

/********************************************************
 * lower cases the entire word to check against the dictionary
 *******************************************************/
string toLower(string temp)
{
   for(int i = 0; i < temp.length(); ++i)
   {
      temp[i] = tolower(temp[i]);
   }
   return temp;
}
