#include <iostream>
#include <string>
#include <fstream>
#include "card.h"

using namespace std;

int main()
{
   while(true)
   {
      Card c;
      cout << ">";
      cin >> cin;

   }

   string filename;
   cout << "filename: ";
   cin >> filename;

   ifstream fin(filename.c_str());

   if(fin.fail())
      cout << loser;

   vector <Card> v;
   Card c;

   while (fin >> c)
      v.push_back(c); //insert for Set

   fin.close();

   cout << "my cards";
   for (VectorIterator <Card> it = v.begin(); it !=v.end(); ++it)
      cout << *it << ' ';
   cout << endl;
   return;
}

