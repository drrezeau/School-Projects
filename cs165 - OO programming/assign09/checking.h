#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"
#include <string>

/******************
 * this class is derived from account
 * and allows the creation of a checking account. 
 ******************/
class Checking : public Account
{
  private:
   float fee;

  protected:
   int checks;
  public:
   Checking(float fee, string name, int number, double balance) : Account(number, balance, name)
   {
      this->fee = fee;
   }
   float getFee() { return fee; }
   void setFee(float newFee) { fee = newFee; }
   
   void transaction(double check); 
   void display(); 
   void update(); 
};

#endif //CHECKING_H
