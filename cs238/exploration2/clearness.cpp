/***********************************************************************
 * Program:
 *    Exploration 2, Clearness
 *    Brother Neff, CS 238
 * Author:
 *    You
 * Summary:
 *    Amortization Calculating Program
 *    Exploring a practical recurrence relation.
 ***********************************************************************/
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

/***********************************************************************
 * Amortize class for amortization calculations.
 * See, for example:
 * http://www.bankrate.com/calculators/mortgages/mortgage-calculator.aspx
 *
 * DO NOT CHANGE ANYTHING IN THIS CLASS!
 ***********************************************************************/
class Amortize
{
private:
   int mTermInMonths;              // term in months (n)

   double mRate;                   // annual interest rate (r)

   double mPeriodicRate;           // periodic (monthly) rate (i)

   double mPrincipal;              // principal (p)

   double mMonthlyPayment;         // monthly payment (m)

   double mExtraMonthlyPayment;    // extra monthly payment (x)

   bool mShowAmortizationSchedule; // verbose (v)

   int mStart; // extra payment starting month number (s)

   int mEnd;   // extra payment ending month number (e)

   bool mHavePrincipal;      // p

   bool mHavePeriodicRate;   // r

   bool mHaveTermInMonths;   // n

   bool mHaveMonthlyPayment; // m

   /***********************************************************************
    * Find p given i, m, n.
    ***********************************************************************/
   void findPrincipal();

   /***********************************************************************
    * Find i given p, m, n.
    **********************************************************************/
   void findPeriodicRate();

   /***********************************************************************
    * Find m given p, i, n.
    **********************************************************************/
   void findMonthlyPayment();

   /***********************************************************************
    * Find n given p, i, m.
    **********************************************************************/
   void findTermInMonths();

   /***********************************************************************
    * Find all missing parameters.
    * Implemented below. 
    **********************************************************************/
   bool findAll();

   /****************************************************************
    * Check information for consistency.
    * Implemented below.
    ****************************************************************/
   bool checkConsistency();

   /****************************************************************
    * Displays the month, interest paid, principal paid and balance.
    * Implemented below.
    ****************************************************************/
   void showAmortizationLine(int month, double interestPaid,
                             double principalPaid,
                             double balance);

   /****************************************************************
    * When the balance goes negative, do the right thing;
    * Implemented below.
    ****************************************************************/
   bool balanceGoesNegative(double balance, double &principalPaid,
                            double &totalPaid);

public:
   /****************************************************************
    * Construct an Amortize instance.
    * Implemented below.
    ****************************************************************/
   Amortize(int termInMonths, double rate, double principal,
            double monthlyPayment, double extraMonthlyPayment,
            bool showAmortizationSchedule, int start, int end,
            bool havePrincipal, bool haveRate,
            bool haveTermInMonths, bool haveMonthlyPayment);

   /****************************************************************
    * Displays the month, interest paid, principal paid and balance.
    * Implemented below.
    ****************************************************************/
   void display();

   /****************************************************************
    * Conditionally runs with the data found (if consistent).
    * Implemented below.
    ****************************************************************/
   void run();
};


/***********************************************************************
 * Find p given i, m, n.
 * TODO: implement me
 ***********************************************************************/
void Amortize::findPrincipal()
{
   mPrincipal = (mMonthlyPayment / mPeriodicRate) *
      ( 1 - pow((1 + mPeriodicRate), -mTermInMonths));
}


/*************************************************************
 *formula for one f(q)
 ************************************************************/
double f(double x, double amount, double numPay, double payment) {
   return amount * x * pow(1 + x,numPay)/(pow(1 + x,numPay) - 1) - payment;
}

/*********************************************************************
 * derivative of f(q)
 ********************************************************************/
double  f_1(double x, double amount, double numPay, double payment) {
   return amount * (pow(1 + x,numPay)/(-1 + pow(1 + x,numPay)) - numPay * x * pow(1 + x,-1 + 2*numPay)/pow(-1 + pow(1 + x,numPay),2) + numPay * x * pow(1 + x,-1 + numPay)/(-1 + pow(1 + x,numPay))); 
}
/***********************************************************************
 * Find i given p, m, n.
 * TODO: implement me
 **********************************************************************/
void Amortize::findPeriodicRate()
{
   double error = pow(10, -5);
   double numPay = mTermInMonths;
   double payment = mMonthlyPayment;
   double amount = mPrincipal;
   double oldApprox;
   double approx = 0.05/12;
   double diff;
   
   for (int i = 0; i < 20; ++i)
   {
      oldApprox = approx;
      approx = oldApprox - f(oldApprox, amount, numPay, payment)/f_1(oldApprox, amount, numPay, payment);
      diff = abs(approx-oldApprox);
      if(diff < error)
         break;
   }

   mPeriodicRate = approx;
   mRate=mPeriodicRate * 12 * 100;
  
}

/***********************************************************************
 * Find m given p, i, n.
 * TODO: implement me
 **********************************************************************/
void Amortize::findMonthlyPayment()
{
   mMonthlyPayment = mPrincipal*(mPeriodicRate/(1 - pow((1 + mPeriodicRate), -mTermInMonths)));
}

/***********************************************************************
 * Find n given p, i, m.
 * TODO: implement me
 **********************************************************************/
void Amortize::findTermInMonths()
{

   
   double rate = mMonthlyPayment/mPeriodicRate;
   double top = ((mPrincipal - (rate)) /(-rate));
   double bottom = 1 + mPeriodicRate;

   mTermInMonths = int(-log(top) / log(bottom) + 0.5);

   
}


/*************************************************************************
 * Learned:
 * TODO: implement this to report what you learned.
 *************************************************************************/
void learned()
{
   cout << "Learned:\n";
   cout << "\t\tIn this exploration, we explored the different numbers of the\n \tmortgage"
        << " formula. We had take each variable and use an equation to be\n \table to"
        << " solve for each. The hardest formula to do was when we were\n"
        << "\tsolving for the APR. While all the others were straight forward, the\n"
        << "\tformula for APR was a recurance relation. We learned the formula by\n"
        << "\tusing google to find one.\n"
        << "\t\tWe found a formula that someone had created and implemented it.\n \tWe kept"
        << " running into a problem of bad or missing information. By\n \ttalking to Brother"
        << " Neff, we learned what we were doing wrong. Our\n \tformula for solving the term"
        << " of months was not doing it right. He showed\n \tus the proper way of solving the"
        << " term of months, fixing our code. We\n \trealized though, our current formula for"
        << " solving the APR was in fact\n \twrong. We used google once again to find a"
        << " formula. We found one,\n \twhich we implemented in a different file, for testing"
        << " purposes. Once\n \twe confirmed we had the right APR calculated, we plugged it"
        << " in and our\n \tcode was a success. I learned that understanding that not every\n"
        << "\tfrom google can be trusted and even though code looks like it works, it\n \tmay"
        << " not.\n"
        << "\t\tI also learned that not all formulas are easily solved from\n \tAlgebra, but"
        << " require a recurance relation, or coding a recursive\n \t(or looped) function.\n\n";
}

/*************************************************************************
 * Usage:
 * TODO: flesh this out to give the user some good guidance.
 *************************************************************************/
void usage(char* programName)
{
   cout << "Usage: " << programName << " <filename> or <parameters>" << endl;
   cout << "\ti.e. " << programName << " /home/cs238/files/amortize.1" << endl;
   cout << "\ti.e. " << programName << " p=117600 n=360 r=6.375 v=1 x=200 m=457.12" << endl
        << "\tWhere p is loan amount; n is term in months; r is APR and v is if\n"
        << "\twe show the Amortization table; m is the monthly payment; x is\n"
        << "\tany extra Monthly Payment. Only three of p, n, r, m are required.\n";

}

// DO NOT CHANGE ANYTHING BELOW THIS LINE!

/****************************************************************
 * Check information for consistency:
 *
 * (E.g., the monthly payment as given should equal
 *  the monthly payment as calculated, and if
 *  the start month has been given but not the end month,
 *  set the end month to the term in months.
 *
 * Called after findAll() in run().
 ****************************************************************/
bool Amortize::checkConsistency()
{
   double monthlyPayment = mMonthlyPayment;
   // calculate monthly payment to make sure it's consistent,
   // as it could have just been given, but not yet calculated.
   findMonthlyPayment();
   if (abs(mMonthlyPayment - monthlyPayment) > 0.001)
   {
      // not close enough, we have a problem...
      return false;
   }
   else
   {
      if (mStart > 0 && mEnd == 0)
      {
         mEnd = mTermInMonths;
      }
      return true;
   }
}

/****************************************************************
 * Displays the month, interest paid, principal paid and balance.
 *
 * Called when displaying the amortization schedule.
 ****************************************************************/
void Amortize::showAmortizationLine(int month, double interestPaid,
                                    double principalPaid, double balance)
{
   cout << setw(5)  << month
        << setw(12) << interestPaid
        << setw(12) << principalPaid
        << setw(16) << balance
        << endl;
}

/****************************************************************
 * When the balance goes negative, correctly adjust the
 * principal paid and the total paid.
 *
 * Return true if the balance did go negative, false otherwise.
 *
 * Called when iterating through the amortization calculations.
 ****************************************************************/
bool Amortize::balanceGoesNegative(double balance, double &principalPaid,
                                   double &totalPaid)
{
   if (balance < 0)
   {
      principalPaid += balance;
      totalPaid += (mMonthlyPayment + balance);
      return true;
   }
   else
   {
      return false;
   }
}

/****************************************************************
 * Construct an Amortize instance.
 * Beaucoup parameters.
 ****************************************************************/
Amortize::Amortize(int termInMonths, double rate, double principal,
                   double monthlyPayment, double extraMonthlyPayment,
                   bool showAmortizationSchedule, int start, int end,
                   bool havePrincipal, bool haveRate,
                   bool haveTermInMonths, bool haveMonthlyPayment)
{
   mTermInMonths = termInMonths;
   mRate = rate;
   mPrincipal = principal;
   mMonthlyPayment = monthlyPayment;
   mExtraMonthlyPayment = extraMonthlyPayment;
   mShowAmortizationSchedule = showAmortizationSchedule;
   mStart = start;
   mEnd = end;
   mHavePrincipal = havePrincipal;
   mHavePeriodicRate = haveRate;
   mPeriodicRate = mRate * 0.01 * (1.0 / 12.0);
   mHaveTermInMonths = haveTermInMonths;
   mHaveMonthlyPayment = haveMonthlyPayment;
}

/****************************************************************
 * Conditionally runs with the data found (if consistent).
 * Reports an error if not found or inconsistent.
 ****************************************************************/
void Amortize::run()
{
   if (findAll() && checkConsistency())
   {
      display();
   }
   else
   {
      cerr << "Bad or missing information.\n";
   }
}

/****************************************************************
 * Find all missing parameters.
 ****************************************************************/
bool Amortize::findAll()
{
   if (!mHavePrincipal && mHaveMonthlyPayment &&
       mHavePeriodicRate && mHaveTermInMonths)
   {
      findPrincipal();
      mHavePrincipal = true;
   }
   if (!mHavePeriodicRate && mHavePrincipal &&
       mHaveMonthlyPayment && mHaveTermInMonths)
   {
      findPeriodicRate();
      mHavePeriodicRate = true;
   }
   if (!mHaveTermInMonths && mHavePrincipal &&
       mHaveMonthlyPayment && mHavePeriodicRate)
   {
      findTermInMonths();
      mHaveTermInMonths = true;
   }
   if (!mHaveMonthlyPayment && mHavePrincipal &&
       mHavePeriodicRate && mHaveTermInMonths)
   {
      findMonthlyPayment();
      mHaveMonthlyPayment = true;
   }

   return (mHavePrincipal && mHaveMonthlyPayment &&
           mHavePeriodicRate && mHaveTermInMonths);
}

/****************************************************************
 * Display the details of the principal, term, annual rate,
 * periodic rate, monthly payment, and extra payment (if any).
 *
 * Optionally display the amortization schedule.
 ****************************************************************/
void Amortize::display()
{
   double totalInterestPaid = 0.0;
   double totalPaid = 0.0;
   double totalExtra = 0.0;
   double totalSavings = 0.0;
   double balance = mPrincipal;
   cout << fixed << endl;
   cout << "##############################################\n\n";
   cout << "      Principal: " << setw(8) << setprecision(2) << mPrincipal
        << endl;
   cout << "           Term: " << mTermInMonths << " months\n";
   cout << "    Annual Rate: " << setprecision(3) << mRate << "%\n";
   cout << "  Periodic Rate: " << setprecision(7) << mPeriodicRate << endl;
   cout << endl;
   cout << "Monthly Payment: " << setw(8) << setprecision(2) << mMonthlyPayment
        << endl;
   if (mExtraMonthlyPayment > 0)
   {
      cout << "  Extra Payment: " << setw(8) << mExtraMonthlyPayment << endl;
   }
   cout << endl;
   if (mShowAmortizationSchedule)
   {
      cout << "Month     Interest   Principal       Balance\n";
   }
   int month;
   for (month = 1; month <= mTermInMonths; month++)
   {
      double interestPaid = balance * mPeriodicRate;
      totalInterestPaid += interestPaid;
      double principalPaid = mMonthlyPayment - interestPaid;
      balance -= principalPaid;
 
      if (balanceGoesNegative(balance, principalPaid, totalPaid))
      {
         if (mShowAmortizationSchedule)
         {
            showAmortizationLine(month, interestPaid, principalPaid, 0.0);
         }
         break;
      }

      totalPaid += mMonthlyPayment;

      if (month >= mStart && month <= mEnd)
      {
         balance -= mExtraMonthlyPayment;
         principalPaid += mExtraMonthlyPayment;
         totalExtra += mExtraMonthlyPayment;
      }
      if (mShowAmortizationSchedule)
      {
         showAmortizationLine(month, interestPaid, principalPaid, balance);
      }
   }

   if (mShowAmortizationSchedule)
   {
      cout << endl;
   }

   if (totalExtra > 0)
   {
      cout << "   Reduced Term: " << month << " months (shorter by "
           << (mTermInMonths - month) << " month(s) = "
           << (mTermInMonths - month) / 12 << " year(s) "
           << (mTermInMonths - month) % 12 << " month(s))\n";
   }

   cout << " Total Payments:" << setw(10) << totalPaid + totalExtra << endl;

   if (totalExtra > 0)
   {
      cout << " Extra Payments:" << setw(10) << totalExtra << endl;
   }

   cout << " Total Interest:" << setw(10)
        << totalInterestPaid << endl;

   if (totalExtra > 0)
   {
      totalSavings =
         ((mTermInMonths * mMonthlyPayment) - totalPaid - totalExtra);
      cout << "  Total Savings:" << setw(10)
           << totalSavings << endl;
   }

   cout << "  Intrst/Prncpl:" << setw(7)
        << (totalInterestPaid / mPrincipal * 100)
        << "%\n";
}

/*******************************************************************
 * runWithData is a global function declared in the clearnessCLI.cpp
 * file and implemented here.
 *
 * It serves as the interface between the CLI and the Amortize class.
 *** ****************************************************************/
void runWithData(int termInMonths, double rate, double principal,
                 double monthlyPayment, double extraMonthlyPayment,
                 bool showAmortizationSchedule, int start, int end,
                 bool havePrincipal, bool haveRate,
                 bool haveTermInMonths, bool haveMonthlyPayment)
{
   Amortize(termInMonths, rate, principal,
            monthlyPayment, extraMonthlyPayment,
            showAmortizationSchedule, start, end,
            havePrincipal, haveRate,
            haveTermInMonths, haveMonthlyPayment).run();
}
