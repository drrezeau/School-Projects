#ifndef LOAN_H
#define LOAN_H

#include "account.h"

//this class will allow the creation of loan accounts
class Loan : public Account
{
  private:
   double interest;

  public:
  Loan(double rate, string name, double balance, int accountNum)
     : Account(accountNum, balance, name)
   {
      interest = rate;
   }
   double getInt() { return interest; }
   void setInt(double newInt) { interest = newInt; }

   void update();
   void transaction(double acount);
   void display();
};

#endif //LOAN_H
