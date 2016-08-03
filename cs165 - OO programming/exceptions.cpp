#include <iostream>
using namespace std;

int main()
{
   try
   {

      cout << "Before throw.\n";

      cout << "Enter number: ";
      int x = 1;
      cin >> x;

      if (x < 0)
      {
         throw 1;
      }

      cout << "After throw.\n";
   }


   catch(int exception)
   {
      cout << "In catch.\n";
      
      cout << "found error: " << exception << endl;
   }

   cout << "After catch.\n";

   return 0;
}
