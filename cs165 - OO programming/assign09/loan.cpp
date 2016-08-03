#include <iostream>
#include <string>

#include "loan.h"

using namespace std;

//this allows for transactions for loans
void Loan :: transaction(double amount)
{
   cout << getName() << " (loan):  $" << amount << " applied to account"
        << endl;
   
   double newBal = getBalance() - amount;

   setBalance(newBal);
}

//this allows for updates in the loan accounts
void Loan :: update()
{
   double amount = getBalance() * interest;

   cout << getName() << " (loan):  $" << (-1 * amount) << " applied to account"
        << endl;
   setBalance(getBalance() + amount);
}

//this will display the loan accounts
void Loan :: display()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << getName() << " (loan):  balance is $" << (-1 * getBalance()) << endl;
}

