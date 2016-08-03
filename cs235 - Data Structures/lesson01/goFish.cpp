/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Derek Calkins
* Summary: 
*    This is all the functions necessary to play Go Fish!
*    (this information is just for Derek's time)
*
*    Estimated:  10.0 hrs   
*    Actual:     7.0 hrs
*      The most difficult 
************************************************************************/

#include <fstream>
#include <string>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * This function reads in the file into a set, starts the game, and then
 * takes the input from the user and removes it if it is found, and
 * doesn't do anything if it is not found. Then displays what is left
 * over in the hand after the 5 rounds are played.
 ***********************************************************************/
void goFish()
{
   string fileName = "/home/cs235/lesson01/hand.txt";

   ifstream fin(fileName.c_str());
   if (fin.fail())
   {
      cout << "NOT WORKING!!!";
   }
   
   Set <Card> hand;
   Card input;

   //reads file into hand
   while (fin >> input)
   {
      hand.insert(input);
   }

   fin.close();

   int num = 0;
   
   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";
   for (int i = 1; i <= 5; i++)
   {
      cout << "round " << i << ": ";
      cin  >> input;

      //if the input cannot be found, Go Fish, otherwise match and erase. :)
      if(hand.find(input) != hand.end())
      {
         num++;
         hand.erase(hand.find(input));
         cout << "\tYou got a match!\n";
      }
      else
         cout << "\tGo Fish!\n";
   }

   // finds how many items are in the 
   int numItems = hand.size();
   
   cout << "You have " << num << " matches!\n";
   cout << "The remaining cards: ";

   SetIterator<Card> it;
   
   for (it = hand.begin(); it != hand.end(); it++)
   {
      //for already finding at least one more item in hand
      numItems--;

      //if there is something left put comma
      if (numItems)
      {
         cout << *it << ", ";
      }

      //new line when last item in hand 
      else
         cout << *it << endl;
   }
}
