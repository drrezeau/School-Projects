#include <iostream>
#include <string>
#include <cmath>
#include <NTL/ZZ.h>

using namespace std;


NTL_CLIENT

int main()
{
   string message;
   ZZ value;
   ZZ number;

   cout << "Message:\n";
   getline(cin, message);

   for (long i = message.length() - 1; i >= 0; i--)
   {
      double n;
      if (message[n] == '@')
         value = 0;
      else
      {  
         value = int(message[n]) - 64;
         value = value * power(to_ZZ(27), i);
         cout << value << endl;
      }
      
       n++;

      number += value;
      cout << number << endl;
   }
   for (long i = 0; i < 10 ; i++)
   {
      long newV = number % 27;

      cout << newV << ' ' << char(newV+64) << endl;
      number /= 27;
      cout << number << endl;
   }
   
   return 0;
}
