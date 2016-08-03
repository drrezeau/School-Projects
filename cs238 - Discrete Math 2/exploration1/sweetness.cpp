/***********************************************************************
 * Program:
 *    Exploration 1, Sweetness
 *    Brother Neff, CS 238
 * Author:
 *    David Lambertson
 * Collaborators: kendall Wahnschaffe, Issac Metcalf, Braden Steiner.
 * Summary:
 *    Prime Generation Program, exploring a probability connection.
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

int f(const int & x, const int & C)
{
   return abs((x * x) + x + C);
}

bool isPrime(const vector<bool> & n, const int& i)
{
   return n[i];
}

/******************
 *
 *
 *******************/
vector<bool> sieve(const int& v)
{
   vector<bool> is_prime(v, true);

      
   const int sqrt_limit = (int)(sqrt(v));
   for (int n = 2; n <= sqrt_limit; ++n)
   {
      if (is_prime[n])
      {
         for (int k = n*n; k < v; k += n) 
          is_prime[k] = false;
      }
   }

   is_prime[0] = is_prime[1] = false;

   return is_prime;
}

void learned()
{

   //started out learning...
   cout << "\tWe started with tracking the constant that got a hit for 50%, but\nusing the case for -5,000 to 5,000. "
        << "We then found the sweetness of the\ngiven number, being 115,721, and found the range of -5,420 to 4,579.\n"
        << "We ran the code for the rest of the constants possible (to 5 million).\nThis gave us the result of "
        << "four different constantsbeing: 115,721; 247,757; 595,937;\nand 1,577,987. It was not until we talked "
        << "to Brother Neff,\nthat we learned there would be duplicates. that is when we started over.\n\n";

   //learned after learning right thing to do.
   cout << "\tWe started by running the program with a set range of 0-9,999\n"
        << "but taking the constant up one by one each loop through. I did this\n"
        << "to figure out which constants will give us a yield of 50% or higher\nfor that one range.\n"
        << "\tTo save all the values instead of kicking out at the first 50%,\nI used a vector to save "
        << "the values and displayed them all at the end.\n"
        << "\tFor all constants to 5 million, I only got one hit, being 247,757.\n"
        << "Once I found out this, I took this constant and ran it while incrementing\n"
        << "the range one by one on both sides (to keep it at 10,000). This gave me\nthe result that "
        << "the best range for this constant is 1 to 10,000. This gave\nus the resulting percent of 50.27%.\n";
}

//how to use the whole program. 
void usage()
{
   cout << "USAGE:\n"
        << "\t 0) a.out\n\t- Display Learned and Usage.\n"
        << "\t 1) a.out 1 *ANY NUMBER*\n\t- run 0 PLUS check the primeness of the given number.\n"
        << "\t i.e. a.out 1 45\n"
        << "\t 2) a.out 2\n\t- run 0 PLUS display the percent of the default constant/range.\n"
        << "\t i.e. a.out 2 (run the best case).\n"
        << "\t 3) a.out 3 *MINIMUM* *MAXIMUM*\n\t- run 0 PLUS display the percent for the range given.\n"
        << "\t i.e. a.out 3 10 10009\n"
        << "\t 4) a.out 4 *CONSTANT*\n\t- changes the constant to the given constant.\n"
        << "\t i.e. a.out 4 115721\n"
        << "\t 5) a.out 5 *MINIMUM* *MAXIMUM* *CONSTANT*\n\t- changes the minimum and the maximum and constant to the given values\n"
        << "\t i.e. a.out 5 1 10000 247757 ->(best case)\n";
}

/******************************
 FOR TESTING PURPOSES ONLY
 * PrimePercent
 * Keeps track of the information for those
 * variables that gave us more than 50%
 *  while testing

struct PrimePercent
{
   float p; //percent
   int m; //min 
   int x; //max
   int c; //constant
};


void checkPrimes(vector<bool> prime)
{


   *Code That I used to save the constants and information I wanted to know.
   *int primes = 0;
   *int total = 0;
   *float percent = 0;
   *int min = 1;
   *int max = 10000;
   *int constant =  247757;
   *int temp;
   *float highPercent = 0;
   *
   *vector<PrimePercent> goTeam;
   *PrimePercent pp;
   *
   *while (percent < 50)
   *{
   *
   * for (int x = min; x <= max; x++)
   * {
   *    total++;
   *    int v = f(x, constant);
   *    if (isPrime(v))
   *    {
   *       primes++;
   *    }
   * }
   *
   * percent = ((float)primes/(float)total)*100;
   *
   *  
   * Would change the constant or max and min depending on the
   * part I was working on. If it was greater than 50%, I would
   * save it into a vector.
   *
   *   if(percent <50)
   *   {
   *      min++;
   *      max++;
   *      //constant++;
   *      total = primes = 0;
   *   }
   *   else
   *   {
   *      pp.p = percent;
   *      pp.m = min;
   *      pp.x = max;
   *      pp.c = constant;
     }
  }
} **********************************************/


/*********************************
 * Calculates and displays the percent of the given numbers
 ********************************/
void displayandCalcPercent(const vector<bool>& primes, int min, int max, int constant)
{
   float primesCounted = 0;
   float total = 0;
   float percent = 0;

   if (min < 0)
      min = 1;
   if (max < 0)
      max = abs(max);
   for (int x = min; x <= max; x++)
   {
      total++;
      int size = f(x, constant);
      if (isPrime(primes, size))
      {
         primesCounted++;
      }
   }
   percent = (primesCounted/total)*100;
   cout << "Percent: " << percent << "%\n";
   cout << "Constant: " << constant << "\nRange: " << min << "-"<< max << endl;
}
   
/****************************************************************
 *Calling my other functions to run the code
 ****************************************************************/
int main(int argc, char* argv[])
{
   
   learned();
   usage();
   

   vector<bool> primes;
   int command;

   //get the command
   if (argc > 1)
      command = atoi(argv[1]);

   //default cases
   if (command == 1 || command == 2)
   {
      int size = f(10000, 247757);
      primes = sieve(size);
   }

   //command 1: check primeness
   if (command == 1)
   {
      cout << argv[2] << endl;   
      int spot =atoi(argv[2]);

      cout << (isPrime(primes, spot) == 1 ? "Is a Prime" : "Is not a Prime")
           << endl;    
      
   }
   //command 2: display default sweetness percentage
   else if (command == 2)
   {
      displayandCalcPercent(primes, 1, 10000, 247757);
   }

   //command 3: takes command parameters and changes the range
   else if (command == 3)
   {
      int min = atoi(argv[2]);
      int max = atoi(argv[3]);
      int total = max - min;
      int size = f(abs(max), 247757);
      primes = sieve(size);
      displayandCalcPercent(primes, min, max, 247757);
   }
   
   //command 4: changes the constant from command line
   else if ( command == 4)
   {
      int size = f(10000, atoi(argv[2]));
      primes = sieve(size);
      displayandCalcPercent(primes, 1, 10000, atoi(argv[2]));
   }

   //command 5: changes the range and constant from command line parameters
   else if ( command == 5)
   {
      int constant = atoi(argv[4]);

      int min = atoi(argv[2]);
      int max = atoi(argv[3]);
      int size = f(abs(max), constant);
      primes = sieve(size);
      displayandCalcPercent(primes, min, max, constant);

   }
   

  
   return 0;
}

