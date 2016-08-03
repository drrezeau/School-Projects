#include <iostream>
#include <cmath>
using namespace std;

main()
{
   float number = 1;
   
   while (int i = 0; i <= number; i++)
   {
      number = pow(number, 2);
      cout << number << endl;
   }
   return 0;
}
