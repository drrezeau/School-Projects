#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
   // name of the program
   cout << "Program name: " << argv[0] << endl;

   // number of paramters
   cout << "There are " << argc - 1 << " parameters\n";

   // show each parameter
   for (int iArg = 1; iArg < argc; iArg++)
      cout << "\tParameter" << iArg
           << ": " << argv[iArg] << endl;

   return 0;
}
