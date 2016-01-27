/***********************************************************************
* Program:
*    Test 2, find the Factors     
*    Brother Helfrich, CS124
* Author:
*    David Lambertson
* Summary: 
*       this program will ask the user to input a number, and then will
*       display each factor of the number and say if the number is prime or
*       not.
*
*
*
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*      getting only prime numbers to say they are prime
************************************************************************/

#include <iostream>
using namespace std;

/*************************************************************
 * this function prompt the user for a positive number.
 ************************************************************/
int getNumber()
{
   int number;
   do
   {
      cout << "Please enter a positive number: ";
      cin >> number;
   }
   while (number < 0);
}

/*************************************************************
 * this program displays any factors of the number given.
 ************************************************************/
void findFactor(int number, int &count)
{
   for (int i = 1; i <= number; i++)
   {
      if (number % i == 0)
      {
         cout << "\t" << i << endl;
         count++;
      }
   }

}

/********************************************************
 * this function will say if the number is prime or not.
 *******************************************************/
bool isPrime(int count)
{
   if (count == 2)
      return true;
   else
      return false;
}

/**********************************************************************
* this will call the other functions getNumber, findFactor, and
* isPrime to do everything needed to be done.
***********************************************************************/
int main()
{
   int count = 0;
   int number = getNumber();
   findFactor(number, count);
   if (isPrime(count))
      cout << number << " is a prime.\n";    
   return 0;
}
