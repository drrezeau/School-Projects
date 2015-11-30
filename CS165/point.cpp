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

Point readPoint()
{
   Point p;

   try
   {
      cout << "Enter x: ";
      cin >> p.xCoord;
      
      if (cin.fail())
      {
         throw "Error reading x coordinate.";
      }
   }
   catch (const char * message)
   {
      cout << "Caught an error... Message: ";
      cout << message << endl;
   }

   cout << "Enter y: ";
   cin >> p.yCoord;
   return p;
}

int main()
{
   Point userPoint = readPoint();
   userPoint.display();

   

   return 0;
}
