/***************************************************************************
 * Program:
 *    Relations as Connection Matrices
 * Author:
 *    You
 * Purpose:
 *    Exploring and enhancing an implementation of a
 *    representation of relations to discover their basic properties.
 *
 * Summary:
 *    Represents relations as connection (zero-one) matrices, and provides
 *    functionality for testing properties of relations.
 *
 *    NOTE: deliberately (mostly) uncommented!
 *
 ***************************************************************************/
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;




/******************************
 * A class to check the relation between two matrices
 ****************************/
class Relation
{
private:
   bool** mMatrix;
   int mSize;

   //initialize the matrix
   void init()
   {
      mMatrix = new bool*[mSize];
      for (int i = 0; i < mSize; i++)
      {
         mMatrix[i] = new bool[mSize];
      }
   }

public:

   //Non-default constructor
   Relation(int size)
   {
      mSize = size;
      init();
   }

   //overloaded equals operator
   Relation& operator=(const Relation& rtSide)
   {
      if (this == &rtSide)
      {
         return *this;
      }
      else
      {
         mSize = rtSide.mSize;
         for (int i = 0; i < mSize; i++)
         {
            delete [] mMatrix[i];
         }
         delete [] mMatrix;
         init();
         for (int x = 0; x < mSize; x++)
         {
            for (int y = 0; y < mSize; y++)
            {
               mMatrix[x][y] = rtSide[x][y];
            }
         }
      }
      return *this;
   }

   //copy contructor
   Relation(const Relation& relation)
   {
      mSize = relation.getConnectionMatrixSize();
      init();
      *this = relation;
   }

   //destructor
   ~Relation()
   {
      for (int i = 0; i < mSize; i++)
      {
         delete [] mMatrix[i];
      }
      delete [] mMatrix;
   }

   //gets the size of the matrix
   int getConnectionMatrixSize() const
   {
      return mSize;
   }

   //overloaded sqaure brackets operator
   bool* operator[](int row) const
   {
      return mMatrix[row];
   }

   //overloaded is equals operator
   bool operator==(const Relation& relation)
   {
      int size = relation.getConnectionMatrixSize();
      if (mSize != size)
      {
         return false;
      }
      for (int i = 0; i < size; i++)
      {
         for (int j = 0; j < size; j++)
         {
            if (mMatrix[i][j] != relation[i][j])
            {
               return false;
            }
         }
      }
      return true;
   }

   /*******************************
    *Overloaded multiplication operator
    *takes two relations and multiplies them
    ******************************/
   Relation operator*(Relation& r2)
   {
      Relation r3(mSize);
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
             for(int k = 0; k < mSize; k++)
            {
               
               bool x = (mMatrix[i][k] && r2.mMatrix[k][j]);
               if (x)
               {
                   r3.mMatrix[i][j] = 1;
                  break;
               }
               else
                  r3.mMatrix[i][j] = 0;
            }
          }
      }
      return r3;
      
   }

   /*******************************
    *Overloaded less than or equals to
    *operator. Compares two different relations
    ******************************/
   bool operator <=(Relation& r2)
   {
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            if (mMatrix[i][j] != r2.mMatrix[i][j] && mMatrix[i][j] > r2.mMatrix[i][j])
               return false;
         }
      }
      return true;
   }

   
   /****************************************************************************
    *  TODO:                                                                   *
    *  In the next seven functions replace the "return false;" with your code. *
    *  NOTE: you may have to implement some of these functions outside of this *
    *  class definition (like is done with the describe function).             *
    *                       for (int i = 0; i < mSize; i++)                    *
    *                                                                          *
    ***************************************************************************/
   //determines if Reflexive
   bool isReflexive()
   {return reflexive(1);}

   //determines if Irreflexive
   bool isIrreflexive()
   { return reflexive(0);}

   //the loop for reflexive traits
   bool reflexive(int expected)
   {
      for (int i = 0; i < mSize; i++)
      {
         if (mMatrix[i][i] != expected)
            return false;
      }
      
      return true; 
   }

   //determines if Nonreflexive
   bool isNonreflexive()
   {
      if(isReflexive() || isIrreflexive())
         return false;
      return true;
   }

   //determines if Symmetric
   bool isSymmetric()
   {
      return symmetric(1);
   }

   //Determines if Antisymmetric
   bool isAntisymmetric()
   {
      return symmetric(0);
   }

   //determines if Asymmetric
   bool isAsymmetric()
   {
      if (isAntisymmetric() && isIrreflexive())
         return true;
      return false;
   }

   //symmetric loop for matrix traits
   bool symmetric(int expected)
   {
       for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            if (expected)
            {  
               if (!(mMatrix[i][j] == mMatrix[j][i]))
                  return false;
            }
            else
               if (i != j && !(mMatrix[i][j] == 0 || mMatrix[j][i]== 0))
                  return false;
         }
      }
      return true;
   }

   //determines if Transitive
   bool isTransitive() {return (((*this) * (*this)) <= *this);}

   void describe();
};

//overloaded insertion operator
ostream& operator<<(ostream& os, const Relation& relation)
{
   int n = relation.getConnectionMatrixSize();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         os << relation[i][j] << " ";
      }
      os << endl;
   }
   return os;
}

//overloaded extraction operator
istream& operator>>(istream& is, Relation& relation)
{
   int n = relation.getConnectionMatrixSize();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         is >> relation[i][j];
      }
   }
   return is;
}

//displays true or not for each trait
void Relation::describe()
{
   cout << "\nThe relation represented by the " << mSize << "x" << mSize << " matrix\n";
   cout << *this << "is\n";
   cout << (isReflexive() ? "" : "NOT ") << "Reflexive;\n";
   cout << (isIrreflexive() ? "" : "NOT ") << "Irreflexive;\n";
   cout << (isNonreflexive() ? "" : "NOT ") << "Nonreflexive;\n";
   cout << (isSymmetric() ? "" : "NOT ") << "Symmetric;\n";
   cout << (isAntisymmetric() ? "" : "NOT ") << "Antisymmetric;\n";
   cout << (isAsymmetric() ? "" : "NOT ") << "Asymmetric; and\n";
   cout << (isTransitive() ? "" : "NOT ") << "Transitive.\n";
}

//runs it once
void runOne(string file)
{
   ifstream inFile(file.c_str());

   if (inFile.is_open())
   {
      int size;
      inFile >> size;
      Relation relation(size);
      inFile >> relation;
      inFile.close();
      relation.describe();
   }
   else
   {
      cout << "Unable to open " << file << ".\n";
   }
}

void usage(const char * programName)
{
   cout  << endl << programName << " <filename>.\n"
         << "\tWill take the file, which should contain a matrix,\n"
         << "and load it into the Relation which holds the size and matrix.\n";
}

void learned()
{
   cout << "I learned a lot, and had a ton of fun.\n"
        << endl << "\tI learned that to work with matrices, it takes\n"
        << "alot of for loops. Trying to figure out if the matrix\n"
        << "given has these different traits was not too hard.\n"
        << "The hard part of this exploration was the overloading\n"
        << "of the operators. Trying to get it to work properly\n"
        << "to multiply the two matrices was not too straight forward.\n"
        << "\tWe learned that the same code we had running the isTransitive\n"
        << "worked in doing the multiplication. We then had to overload\n"
        << "the less than or equals to operator to make our isTransitive\n"
        << "into one line of code.\n";
}
