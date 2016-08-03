/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Derek Calkins
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM


//class Stock;
/**
class Transaction
{
  public:
   Transaction() {stocks = 0;}
   float buy(Stock stocks);
   float sell(Stock stocks);
   void display();
   
  private:
   Stock stocks;
};
**/

class Stock
{
  public:
   Stock() {amount = 0, price = 0.00;} //default constructor
   Stock(int amount, Dollars price);   //non-default constructor
   Stock(const Stock & rhs)
   {
       setAmount(rhs.getAmount());
       setPrice(rhs.getPrice());
   }           //copy constructor
   void setAmount(int amount) { this->amount = amount; }
   void setPrice(Dollars price) { this->price = price; }
   //void setSAmount(int sAmount) { this->sAmount = sAmount; }
   //void setSPrice(Dollars sPrice) { this->sPrice = sPrice; }
   
   int getAmount() const { return amount; }
   Dollars getPrice() const { return price; }
   //int getSAmount() const { return sAmount; }
   //Dollars getSPrice() const { return sPrice; }
   
   //float addShares(int amount, Dollars price);
   int subShares();
   void display();

  private:
   int amount;
   int sAmount;
   Dollars price;
   Dollars sPrice;
   Dollars total;
};
/*
Stock :: Stock(const Stock & rhs)
{
   setAmount(rhs.getAmount());
   setPrice(rhs.getPrice());
}
*/
/*
Stock :: Stock(int amount, Dollars price)
{
   
}
*/
/*
Stock :: subShares()
{
   return ((getSPrice() * getSAmount()) - (getPrice() * getAmount()));
}
*/






// the interactive stock buy/sell function
void stocksBuySell();

#endif // STOCK_H

