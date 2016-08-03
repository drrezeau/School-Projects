#include <iostream>
using namespace std;

void reverseString(char str[], int length)
{
   for(length >= 0, length--)
   {
      cout << str[length] << endl;
   }

}


int main()
{
   char str[2] = 'a', 'b', 'c',;
   int length = 2;
   reverseString(str, length);
   return 0;
}
