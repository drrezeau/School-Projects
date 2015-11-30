#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"
//this class allows for a creation of a savings account
class Savings : public Account
{
  private:
   double interest;

  public:
  Savings(double interest, string name, double balance, int accountNum) : Account(accountNum, balance, name)
   {
      this->interest = interest;
   }
   
   double getInterest() { return interest; }
   void setInterest(double newInt) { interest = newInt; }

   void transaction(double amount);
   void update();
   void display();
};

#endif // SAVINGS_H
