/*************************************************************
* Program: 
*    Assignment 00, Averages
*    Brother Burton, CS 165
* Author:
*    David Lambertson
* Summary:
*    This program will allow a user to input numbers and after each
*    input average the numbers.
**************************************************************/


#include <iostream>
using namespace std;



/******************************************
* this function will ask the user for a number.
* will ask user for number input
* user inputs number.
* function returns number to main.
********************************************/
float GetNumber(float number)
{
   cout << "Enter a number: ";
   cin >> number;
   return number;
}

/******************************************
* this function will display the information for the user.
* sets the rules for decimals.
* displays the average.
*****************************************/
void display(float average)
{
   cout.setf(ios::fixed); 
   cout.setf(ios::showpoint);
   cout.precision(2); // sets precision to 2 numbers
   
   cout << "Average: " << average << endl;
   cout << endl;
   return;
}


/*****************************************
* this function will calculate the average of the numbers inputted.
* uses the old number and the new number to calculate the average.
*****************************************/
float getAverage(float oldnumber, float average, int i, float newnumber)
{
   average = ((oldnumber + newnumber) / i);

   return average;
}


/********************************************
*this is the main function and will call upon the other functions above.
* creates the float for number and average.
* WHILE number != 0
*         newnumber = GetNumber(number)
*         IF cin reading fails
*               ignore cin, and display invalid input
*         ELSE
*               get the average, save the old number, display the average
* I++ to know how many numbers have been inputted.
* Ends.
********************************************/
main()
{
   float number = 1;
   float average = 0;
   float oldnumber = 0;
   float newnumber = 0;
   int i = 1;
   while (number >= 0)
   {
      
      newnumber = GetNumber(number);
      if (cin.fail()) //if cin reading fails, it will do this part
      {
         cin.clear();
         char ch;
         cin >> ch;
         if (ch == 'q')
         {
            return 0;
         }
         else
         {
            cin.ignore(256, '\n'); 
            cout << "Invalid input, please try again." << endl;
         }
         
      }

      else //else it will do this. 
      {
         average = getAverage(oldnumber, average, i, newnumber);
         oldnumber += newnumber;
         display(average);
         i++;
      }
      
   }
 
   return 0;
}
