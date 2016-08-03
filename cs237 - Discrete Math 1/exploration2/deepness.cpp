#include <iostream>
#include <NTL/ZZ.h>

using namespace std;

NTL_CLIENT

double squareRoot2 = sqrt(2);

long double squareRootTwo(long double number)
{
   long double num1;
   num1 = number * squareRoot2;
   return floor(num1);
}

long double squareRootPlusTwo(long double number)
{
   long double num2;
   num2 = number * (squareRoot2 + 2);
   return floor(num2);
}

int main()
{

   long double number = 0;

   cout << "What is your number?\n";
   cin >> number;
   long double num;
   long double num3;
   cout << "Square Root of Two\n";
   for (double i = 1; i < number; i++)
   {
      num = squareRootTwo(i);
   }
   
   cout << endl << "Square Root of two plus two\n";
   

   for (double i = 1; i < number; i++)
   {
      num3 = squareRootPlusTwo(i);
   }
   cout << endl;
   
   return 0;
}
