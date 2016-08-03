#include <iostream>
#include <string>

#include "savings.h"

using namespace std;

//this function allows tranactions for a savings
void Savings :: transaction(double amount)
{

   cout << getName() << " (savings):  $" << amount << " applied to account"
        << endl;
   double newBal = getBalance() + amount;
   setBalance(newBal);
}

//this will display savings accounts
void Savings :: display()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << getName() << " (savings):  balance is $" << getBalance() << endl;
}

//this will allow an update for savings 
void Savings :: update()
{
   double amount = getBalance() * getInterest();

   cout << getName() << " (savings):  $" << amount << " applied to account"
        << endl;
   setBalance(getBalance() + amount);
}