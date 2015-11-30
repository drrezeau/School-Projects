/**************************************************************************
 * Example file to learn about structs via complex numbers
 **************************************************************************/

#include<iostream>
using namespace std;

/**************************************************************************
 * Structure: Complex
 *
 * Holds a complex number by saving the realPart and the imaginary parts
 * separately
 **************************************************************************/

struct Complex
{
   double realPart;
   double imaginaryPart;
};

// function protoypes
Complex readComplex();
void displayComplex(const Complex & complexNum);

/**************************************************************************
 * Function: Main
 * The driver function for the program. Calls functions to read and display
 * complex numbers
 **************************************************************************/
int main()
{
   Complex complexNum = readComplex();
   displayComplex(complexNum);
   cout << endl;

   return 0;
}

/**************************************************************************
 * Function: readComplex
 * Prompts the user for a complex number and returns it
 **************************************************************************/
Complex readComplex()
{
   Complex complexNum;
   cout << "Please enter the real part: ";
   cin >> complexNum.realPart;
   cout << "Please enter the imaginary part: ";
   cin >> complexNum.imaginaryPart;
   return complexNum;
}

/**************************************************************************
 * Function: displayComplex
 * Displays a complex number in the form x + yi.
 **************************************************************************/
void displayComplex(const Complex & complexNum)
{
   cout << complexNum.realPart << " + " << complexNum.imaginaryPart << "i";
   // TODO: Fill this in!
}


