/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Derek Calkins and David Lambertson
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // your code here...

   
   string command; //check the command
   int amount = 0; //bought stock amount
   Dollars price;  //bought stock price
   int sAmount = 0;//sold stock price
   Dollars sPrice; //sold stock price
   Dollars total;  //bought stock total
   Dollars sTotal; //sold stock total

   Stock bStock; //one element of the bought stocks
   Stock sStock; //one element of the sold stocks
   

   //the check if we have bought or sold at all
   bool buy = false;
   bool sell = false;

   Queue <Stock> bStocks; //one queue for bought stocks
   Queue <Stock> sStocks; //one queue for sold stocks
   Queue <Dollars> profit; //one queue for profits
   
   
   do
   {
      //create a copy for bought stocks
      Queue <Stock> stocks1(bStocks);
      //create a copy for sold stocks
      Queue <Stock> stocks2(sStocks);

      cout << "> ";
      cin >> command;
      if (command == "quit" || command == "display")
      {              
         if (buy && sell)
         {
            int i;
            int j;
            cout << "Currently held:\n";
            for (i = 0; !stocks1.empty(); i++)
            {
               bStock = stocks1.front();
               cout << "\tBought "
                    << bStock.getAmount() << " shares at "
                    << bStock.getPrice() << endl;
               stocks1.pop();
            }
            
            cout << "Sell History:\n";
            for (j = 0; !stocks2.empty(); j++)
            {
               sStock = stocks2.front();
               cout << "\tSold "
                    << sStock.getAmount() << " shares at "
                    << sStock.getPrice() << " for a profit of ";
               cout << (sTotal - total) << endl;
               stocks2.pop();
            }
         }
         else if(buy)
         {
            int i;
            cout << "Currently held:\n";
            for (i = 0; !stocks1.empty(); i++)
            {
               bStock = stocks1.front();
               cout << "\tBought " << bStock.getAmount() << " shares at "
                    << bStock.getPrice() << endl;
               stocks1.pop();
            }
         }
         else if(sell)
            sStock = stocks2.front();

         cout << "\nProceeds: " << (sTotal - total) << endl;
      }
      else if (command == "buy")
      {
         //get bought amount and price from user
         cin >> amount >> price;
         //add to bought total
         total += (price * amount);

         //amount and price of current bought stock transaction
         bStock.setAmount(amount);
         bStock.setPrice(price);
         //we did buy stock
         buy = true;
         //add to the bought stock queue
         bStocks.push(bStock);
      }
      else if (command == "sell")
      {
         //get sell amount and price from user
         cin >> sAmount >> sPrice;
         //add to sell total
         sTotal += (sPrice * sAmount);

         //amount and price of current sold stock transaction
         sStock.setAmount(sAmount);
         sStock.setPrice(sPrice);

         //we did sell stock
         sell = true;

         //add sold stock to queue
         sStocks.push(sStock);

         //to allow us to go into the loop to find total sold stocks
         int tmp = 1;

         // should to handle the selling of stocks
         for (; tmp != 0;)
         {
            //if there are no more bought stocks left leave
            if (bStocks.empty())
               break;
            
            bStock = bStocks.front();
            tmp = (sStock.getAmount() - bStock.getAmount());
            Dollars tmpD = sStock.getPrice() - bStock.getPrice();

            //if we didn't finish selling one bought transaction
            //we save that number into bought stock
            if (tmp < 0)
            {
               tmp *= -1;
               bStock.setAmount(tmp);
               bStocks.front() = bStock;
               tmp = 0;
            }
            else if (tmp > 0)
            {
               bStocks.pop();
            }
               
            Dollars Profit = tmpD * bStock.getAmount();
            profit.push(Profit);
         }
         //while (tmp == 0);
      }
   }
   while (command != "quit");
}

void display()
{

}
