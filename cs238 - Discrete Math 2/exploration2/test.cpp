#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{

   int mTermInMonths = 360;              // term in months (n)

   double mPeriodicRate;           // periodic (monthly) rate (i)

   double mPrincipal = 117600;              // principal (p)

   double mMonthlyPayment = 733.67;         // monthly payment (m)

   double mExtraMonthlyPayment;    // extra monthly payment (x)


   
   double minRate = 0;
   double maxRate = 100;
   double midRate;

   int x = 0;
   while (minRate < maxRate-0.0001)
   {
      midRate - (minRate + maxRate) /2;
      double J = midRate / 1200;

      double guessed_pmt = mPrincipal * ( J / pow((double)(1 - (1+J)), -mTermInMonths));
      if (guessed_pmt > mMonthlyPayment)
      {
         maxRate = midRate;
      }
      else
      {
         minRate = midRate;
      }
      x++;
   }

   cout << x << endl;
   mPeriodicRate = midRate/1200;

   return 0;
}
