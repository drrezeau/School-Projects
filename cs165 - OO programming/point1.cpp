#include <iostream>
using namespace std;

class Point
{
public:
   int xCoord;
   int yCoord;

   void display();

};

void Point :: display()
{
   cout << "(" << xCoord << "," << yCoord << ")" << endl;
}

Point readPoint() throw (const char *)
{
   Point p;
   cout << "Enter x: ";
   cin >> p.xCoord;
   
   if (cin.fail())
   {
      throw "Error reading x coordinate.";
   }

   cout << "Enter y: ";
   cin >> p.yCoord;
   return p;
}

int main()
{
   Point userPoint;

   bool failed = false;

   do
   {
      try
      {
         userPoint = readPoint();
      }
      catch ( const char * ex)
      {
         cout << "Error: " << ex << endl;
         failed = true;
         cin.clear();
         cin.ignore(256, '\n');
      }
   }
   while (failed);
   userPoint.display();

   cout << endl;

   return 0;
}
