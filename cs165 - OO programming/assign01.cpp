/********************************************
* Program:
*    Assignment 02, Mortgage Implementation
*    Brother Burton, CS 165
* Author:
*    David Lambertson
* Summary:
*   this program will ask the user to input a loan amount, interest rate
*   and number of years and will then use those numbers to calculate
*   the necessary numbers and when asked to, display them
*   using an amortization table. 
*********************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/***********************************************************
* this program will display what the monthly payment is 
* when called upon by the program.
**********************************************************/
float monthPay(double payment)
{
   cout << "Monthly Payment: " <<  payment << endl;
   return 1; 
}

/************************************************************
* this program will calculate the monthly payment to be used
* during other parts of the program.
**********************************************************/
void calPay(double loan, double monthInt, int months,
            double &payment)
{
   
   payment = loan * (monthInt * pow(1 + monthInt, months)) /
      (pow(1 + monthInt, months) - 1);
   return;
}

/************************************************************
* this program will calculate the principal and then add it to the 
* cumlative principal to be used within display.
************************************************************/
void cumPrin(double Interest, double &principal, double &cPrin, double payment)
{
   principal = payment - Interest;
   cPrin += principal;
   return;

}

/***********************************************************
* this program will do the same thing as cumPrin, except for
* the interest to be used later in the program.
*********************************************************/
void cumInt(double monthInt, double balance, double &cInt, double &Interest)
{
   Interest = balance * monthInt;
   cInt += Interest;
   return;
}


/*******************************************************
* this program will prompt the user to enter the API. if an 
* invalid input is tried, it will notify the user and repeat until
* given a valid input.
******************************************************/
float getInterest(double &API)
{
   do
   {
      if (cin.fail() || API < 0)
      {
         cout << "Invalid input. Try again.\n";
         cin.clear();
         cin.ignore(256, '\n');
         API = 0;
      }
      else
      {
         cout << "Enter Annual Interest: ";
         cin >> API;
      }
   }
   while (API <= 0);
   return API;

}

/******************************************************************
* just like getInterest function, this will ask the user for the number of 
* years to pay off the loan. also does error checking to make sure a correct
* input is entered.
*****************************************************************/
float getYears(int &years)
{
   do
   {
      if (cin.fail() || years < 0)
      {
         cout << "Invalid input. Try again.\n";
         cin.clear();
         cin.ignore(256, '\n');
         years = 0;
      }
      else
      {
         cout << "Enter number of years: ";
         cin >> years;
      }
   }
   while (years <= 0);
   return years;

}

/******************************************************
* this function will ask the user to enter the amount of loan
* that is needed to be paid and checks to see if a correect input was inputed.
*****************************************************/
float getLoan(double &loan)
{
   do
   {
      if (cin.fail() || loan < 0)
         
      {
         cout << "Invalid input. Try again.\n";
         cin.clear();
         cin.ignore(256,'\n');
         loan = 0;
      }
      
      else
         
      {
         cout << "Enter Loan amount(without comma): ";
         cin >> loan;
      }
   }
   
   while (loan <= 0);
   return loan;
}

/*******************************************
* this function will display the different possible options the user
* can input.
********************************************/
void showOptions()
{
   cout << "Options:\n"
        << "? Show these options.\n"
        << "p show monthly payment\n"
        << "t Show the amortization table.\n"
        << "i New annual interest.\n"
        << "y New number of years.\n"
        << "l New loan amount.\n"
        << "q Quit.\n"
        << endl;
}

/*****************************
* this function will calculate the number of months
* from given years.
********************************/
float calMonth(int years, int &months)
{
   months = (years * 12);
   return months;
}

/**********************************
* this function will calculate the monthly interest.
*********************************/
float calInt(double API, double &monthInt)
{
   API = API / 100;
   monthInt = API / 12;
   return monthInt;

}

/*******************************************
* this function will calculate the remaining balance for each
* month.
***************************************/
void calBalance(double &balance, int i, double monthInt,
                int months, double loan, double principal)
{
   balance = loan * (pow(1 + monthInt, months) - pow(1 + monthInt, i)) /
      (pow(1 + monthInt, months) - 1);
   return;

}


/****************************************
* this function will display the amortization
* table when called upon.
******************************************/
void displayTable(double loan, double API, int years, double monthInt,
                  double principal,double paidInt, double balance,
                  double paidPrin, int months, double payment,
                  double Interest, double cPrin, double cInt)
{
   int i = 0;
   cout << "Pmt      Principal     Interest     Cum Prin     Cum Int"
        << "     Prin Bal\n"
        << "----     ---------     --------     ---------    --------"
        << "    ---------" << endl;
   for (i = 1; i <= months; i++)
   {
      
      cumInt(monthInt, balance, cInt, Interest);
      cumPrin(Interest, principal, cPrin, payment);
      cout.setf(ios::right);
      calBalance(balance, i, monthInt, months, loan, principal);
      cout << setw(3) << i << setw(14) << principal << setw(13) << Interest
           << setw(14) << cPrin
           << setw(12) << cInt << setw(13) << balance << endl;
   }

}

/**************************************
* this function will take the option that the user input and then decide what 
* the rest of the program will do based upon that.
***************************************/
void Option(double loan, double API, int years, double monthInt,
            double principal, double paidInt, double balance,
            double paidPrin, int months, double payment,
            double Interest, double cPrin, double cInt)
{
   showOptions();
   char command = 'a';
   do
   {
      cout << "Enter command: ";
      cin >> command;

      switch (command)
      {
         case '?':
            showOptions();
            break;
         case 'p':
         {
            calPay(loan, monthInt, months, payment);
            monthPay(payment);
            break;
         }
         case 't':
         {
            calPay(loan, monthInt, months, payment);
            displayTable(loan, API, years, monthInt, principal, paidInt,
                         balance, paidPrin, months, payment, Interest,
                         cPrin, cInt);
            break;
         }
         case 'i':
         {
            Interest = 0;
            cInt = 0;
            paidInt = 0;
            API = 0;
            monthInt = 0;
            getInterest(API);
            calInt(API, monthInt);
            break;
         }
         case 'y':
         {
            years = 0;
            getYears(years);
            calMonth(years, months);
            break;
         }
         case 'l':
         {
            principal = 0;
            cPrin = 0;
            paidPrin = 0;
            loan = 0;
            getLoan(loan);
            break;
         }
         case 'q':
            break;
         default:
            cout << "Invalid input. try again.\n";
            break;
      }
   }
   while (command != 'q');
   return;
}


/************************************
* main will create all the variables and then will call
* upon other functions to get the program starting. 
*************************************/
int main()
{
   double loan = 0;
   double API = 0;
   int years = 0;
   double monthInt = 0;
   double principal = 0;
   double paidInt = 0;
   double balance = 0;
   double paidPrin = 0;
   int months = 0;
   double payment = 0;
   double Interest = 0;
   double cPrin = 0;
   double cInt = 0;
   

   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);


   getLoan(loan);
   getYears(years);
   getInterest(API);
   calMonth(years, months);
   calInt(API, monthInt);
   balance = loan;

   Option(loan, API, years, monthInt, principal, paidInt, balance,
          paidPrin, months, payment, Interest, cPrin, cInt);

   return 0;
}
