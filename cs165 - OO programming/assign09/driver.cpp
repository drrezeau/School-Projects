#include <iostream>
#include <string>

#include <fstream>

#include "account.h"
#include "checking.h"
#include "savings.h"
#include "loan.h"

using namespace std;


const int NUMBER_OF_ACCOUNTS = 10;


/*************************
 * this function will read the file and use the 
 * commands to perform the right functions
 *************************/
int main()
{
   Account * accounts[NUMBER_OF_ACCOUNTS];

   
   ifstream fin("/home/cs165sb/bank/bank.txt");

   if (fin.fail())
      ;

   while (!fin.eof())
   {
      char command = 'q';
      fin >> command;

      int accountNum;
      fin >> accountNum;

      double balance;
      string name;
      double rate;

      switch (command)
      {
         case 'c': // create checking
         {
            cout << "new account..." << endl;
            fin >> name;
            fin >> balance;
            fin >> rate;
            accounts[accountNum] = new Checking(rate, name, accountNum, balance);
            //accounts[accountNum] = temp;
            accounts[accountNum]->display();
            break;
         }
         case 's': // create savings
         {
            cout << "new account..." << endl;
            fin>> name; 
            fin>> balance;
            fin>> rate;
            accounts[accountNum] = new Savings(rate, name, balance, accountNum);
            
            accounts[accountNum]->display();
            break;
         }
         case 'l': // create loan
         {
            cout << "new account..." << endl;
            fin >> name;
            fin >> balance;
            fin >> rate;
            accounts[accountNum] = new Loan(rate, name, balance, accountNum);
            //accounts[accountNum] = &temp;
            accounts[accountNum]->display();
            break;
         }
         case 't': // transaction
         {
            cout << "transaction..." << endl;
            double amount;
            fin >> amount;
            accounts[accountNum]->transaction(amount);
            accounts[accountNum]->display();
            break;
         }
         case 'u': // update account
         {
            cout << "update..." << endl;
            accounts[accountNum]->update();
            accounts[accountNum]->display();
            break;
         }
      }
      cout << endl;
   }
   fin.close();

   return 0;
}
