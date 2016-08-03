#include "account.h"
#include "checking.h"

#include <iostream>
#include <string>
using namespace std;

//this function allosw for a transaction in the checking
void Checking :: transaction(double check)
{
   double newBalance = getBalance();
   
   if ((-1 * check) > getBalance())
   {
      cout << getName() << " (checking):  $" << check
           << " rejected (insufficient funds)" << endl;
      cout << getName() << " (checking):  $-25.00 applied to account"
           << endl;
      setBalance(getBalance() - 25);
      checks++;
      return;
   }
   if (check < 0)
      checks++;

   cout << getName() << " (checking):  $" << check << " applied to account"
        << endl;
   newBalance += check;
   setBalance(newBalance);
}

//this function will display the checking accounts
void Checking :: display()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << getName() << " (checking):  balance is $" << getBalance() << endl;
}

//this function will allow an update for the checking accounts.
void Checking :: update()
{
   double pay = checks * getFee();
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << getName() << " (checking):  $" << (-1 * pay) << " applied to account"
        << endl;
   setBalance(getBalance() - pay);
   checks = 0;
}
