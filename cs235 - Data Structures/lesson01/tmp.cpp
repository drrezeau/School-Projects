#include <iostream>
#include "card.h"
#include <fstream>
#include <string>
#include "../faculty/lesson01/set.h"
using namespace std;

int main()
{
   string filename;
   cout << "filename: ";
   cin  >> filename;

   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      cout << "Looser!\n";
      return 1;
   }

   Set <Card> hand;
   Card c;

   while (fin >> c)
      hand.insert(c);
   
   fin.close();

   cout << "my cards: ";
   for (SetIterator <Card> it = v.begin(); it != v.end(); ++it)
      cout << *it << ' ';
   cout << endl;
   return 0;
}
