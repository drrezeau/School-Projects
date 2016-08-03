#include <iostream>
using namespace std;

/**************************************************************
 * The Predicate class is an abstract base class with pure virtual
 * abstract functions (per the =0 suffix).
 ***************************************************************/
class Predicate
{
public:
   /**************************************************************
    * Is this Predicate true for the given x and y?
    ***************************************************************/
   virtual bool isTrue(int x, int y)=0;

   /**************************************************************
    * Is this Predicate false for the given x and y?
    ***************************************************************/
   virtual bool isFalse(int x, int y)=0;

   /**************************************************************
    * Is this Predicate true for all x for all y
    * in the supplied sets?
    ***************************************************************/
   bool forAllForAll(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
    * Is this Predicate true for all x for some y
    * in the supplied sets?
    ***************************************************************/
   bool forAllForSome(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
    * Is this Predicate true for some x for all y
    * in the supplied sets?
    ***************************************************************/
   bool forSomeForAll(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
    * Is this Predicate true for some x for some y
    * in the supplied sets?
    ***************************************************************/
   bool forSomeForSome(int setX[], int sizeX, int setY[], int sizeY);
};

bool Predicate::forAllForAll(int setX[], int sizeX, int setY[], int sizeY)
{
   for(int i = 0; i < sizeX; i++)
   {
      for (int e = 0; e < sizeY; e++)
      {
         if (isFalse(setX[i], setY[i]))
         {
            return false;
         }
      }
   }
   return true;
}

bool Predicate::forAllForSome(int setX[], int sizeX, int setY[], int sizeY)
{
   for(int i = 0; i < sizeY; i++)
   {
      for (int e = 0; e < sizeX; e++)
      {
         if (isTrue(setX[i], setY[i]))
         {
            return true;
         }
      }
   }
   return false;
}

bool Predicate::forSomeForAll(int setX[], int sizeX, int setY[], int sizeY)
{
   for(int i = 0; i < sizeX; i++)
   {
      for (int e = 0; e < sizeY; e++)
      {
         if (isTrue(setX[i], setY[i]))
         {
            return true;
         }
      }
   }
   return false;
}

bool Predicate::forSomeForSome(int setX[], int sizeX, int setY[], int sizeY)
{
   for(int i = 0; i < sizeX; i++)
   {
      for (int e = 0; e < sizeY; e++)
      {
         if (isTrue(setX[i], setY[i]))
         {
            return true;
         }
      }
   }
   return false;
}

class Number : public Predicate
{
   bool isTrue(int x, int y)
   {
      return (x + y > (x*y));
   };

   bool isFalse(int x, int y)
   {
      return !isTrue(x, y);
   };

};
   
main()
{
   Number number;
   
   int X[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int Y[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   int X1[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
   int Y1[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

   int X2[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
   int Y2[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49};

   int X3[] = {2, 12, 52, 16, 19, 8, 65, 78, 102, 3};
   int Y3[] = {87, 12, 65, 48, 41, 24, 94, 51, 36, 97};




   cout << boolalpha
        << "The expected output of X and Y for forAllForAll is False\n"
        << "The actual output is...\n"
        << number.forAllForAll(X, 10, Y, 10)
        << endl
        << "The expected output of X and Y for forAllForSome is True\n"
        << "The actual output is...\n"
        << number.forAllForSome(X, 10, Y, 10) << endl
        << "The expected output of X and Y for forSomeForAll is True\n"
        << "The actual output is...\n"
        << number.forSomeForAll(X, 10, Y, 10)
        << endl
        << "The expected output of X and Y for forSomeForSome is True\n"
        << "The actual output is...\n"
        << number.forSomeForSome(X, 10, Y, 10)
        << endl;

      cout << boolalpha
        << "The expected output of X1 and Y1 for forAllForAll is False\n"
        << "The actual output is...\n"
        << number.forAllForAll(X1, 10, Y1, 10)
        << endl
        << "The expected output of X1 and Y1 for forAllForSome is False\n"
        << "The actual output is...\n"
        << number.forAllForSome(X1, 20, Y1, 10) << endl
        << "The expected output of X1 and Y1 for forSomeForAll is False\n"
        << "The actual output is...\n"
        << number.forSomeForAll(X1, 10, Y1, 10)
        << endl
        << "The expected output of X1 and Y1 for forSomeForSome is False\n"
        << "The actual output is...\n"
        << number.forSomeForSome(X1, 10, Y1, 10)
        << endl;

      cout << boolalpha
        << "The expected output of X2 and Y2 for forAllForAll is False\n"
        << "The actual output is...\n"
        << number.forAllForAll(X2, 10, Y2, 10)
        << endl
        << "The expected output of X2 and Y2 for forAllForSome is False\n"
        << "The actual output is...\n"
        << number.forAllForSome(X2, 10, Y2, 10) << endl
        << "The expected output of X2 and Y2 for forSomeForAll is False\n"
        << "The actual output is...\n"
        << number.forSomeForAll(X2, 10, Y2, 10)
        << endl
        << "The expected output of X2 and Y2 for forSomeForSome is False\n"
        << "The actual output is...\n"
        << number.forSomeForSome(X2, 10, Y2, 10)
        << endl;

      cout << boolalpha
        << "The expected output of X3 and Y3 for forAllForAll is False\n"
        << "The actual output is...\n"
        << number.forAllForAll(X3, 10, Y3, 10)
        << endl
        << "The expected output of X3 and Y3 for forAllForSome is False\n"
        << "The actual output is...\n"
        << number.forAllForSome(X3, 10, Y3, 10) << endl
        << "The expected output of X3 and Y3 for forSomeForAll is False\n"
        << "The actual output is...\n"
        << number.forSomeForAll(X3, 10, Y3, 10)
        << endl
        << "The expected output of X3 and Y3 for forSomeForSome is False\n"
        << "The actual output is...\n"
        << number.forSomeForSome(X3, 10, Y3, 10)
        << endl;



   

   return 0;
   
}
