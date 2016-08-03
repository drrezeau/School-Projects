#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include<string>
using namespace std;

/*********************
 * this class creats an account 
 * class. 
 ********************/
class Account
{
  private:
   int accountNum;
   string name;
   double balance;

  public:
   Account(int number, double balance, string name)
   {
      accountNum = number;
      this->balance = balance;
      this->name = name;
   }
   int getAccount() { return accountNum; }
   double getBalance() { return balance; }
   string getName() { return name; }
   void setAccount(int account) { accountNum = account; }
   void setBalance(double newBalance) { balance = newBalance; }
   void setName(string newName) { name = newName; }
   virtual void display() = 0;
   virtual void update() = 0;
   virtual void transaction(double amount) = 0;

};

#endif
