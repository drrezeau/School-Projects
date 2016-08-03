/***********************************************************************
 * Module:
 *    Lesson 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson and Derek Calkins
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

string getWord(const string & infix, int & i);
int check(const string & infix, const int & spot);
void orderOfOps(const string & infix, int & spot, Stack<int> & operators1,
                  Stack<char> & operators, int & operation, string & postfix);

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postfix "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   string postfix;

   Stack<char> operators; //stack to store the  
   Stack<int> operators1; //stack to store the 

   int spot = 0;
   int operation = -1; 
   bool para = false; 

   postfix += ' ';
   //loop until we are at the end of the string
   do                                        
   {
      //if we have a paraenthesis, do the order of operations first.
      if (infix[spot] == '(')                
      {
         para = true;
      }
      else
         para = false;

      if (infix[spot] == ' ' || infix[spot+1] == ' ')     
      {
         while (infix[spot] ==  ' ')
            spot++;
      }

      
      if (para)
      {
         //what operation are we trying to do
         operation = check(infix, spot);
         // use order of operations to place them properly
         orderOfOps(infix, spot, operators1, operators,  
                    operation, postfix);
      }
    
      //gets the words from the string
      postfix += getWord(infix, spot);                    

      //add space to string
      if (postfix[spot] != ' ')
         postfix += ' ';
      
      if (!para)
      {
         operation = check(infix, spot);
         orderOfOps(infix, spot, operators1, operators,
                    operation, postfix);
      }
      
   }
   while(spot < infix.size());

   //gets rid of any extra space at the end of the string
   while (postfix[postfix.size()-1] == ' ')         
   {
      if ( postfix[postfix.size() - 1] == ' ')
         postfix.erase(postfix.size()-1);
   }

   string tmp;
   
   //gets rid of any double spaces in the string
   for ( int i = 0; i < postfix.size(); i++)       
   {
      
      tmp += postfix[i];
      if (postfix[i] == ' ' && postfix[i + 1] == ' ')
      {
         i++;
      }
   }
   postfix = tmp;
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}

/*************
 * pulls the word out of the 
 *string given to us by the user.
 ******************/
string getWord(const string & infix, int & spot)
{
   string tmp2;
   for (spot; spot < infix.size(); spot++)
   {
      //break out of the loop if we encounter any of these characters
      if (infix[spot] == '(' || infix[spot] == ')' || infix[spot] == '*'||
          infix[spot] == '+' || infix[spot] == '-' ||infix[spot] == '/' ||
          infix[spot] == '^' || spot == infix.size() || infix[spot] == ' ') 
      {
         break;
      }
      else
         tmp2 += infix[spot];
   }

   // returns the word which we have gotten out of the string. just one word 
   return tmp2; 
}

/*********************
 * uses the order of operations to 
 * determine where to place the
 * operators given to us in the string.
 *******************/
void orderOfOps(const string & infix, int & spot, Stack<int> & operators1,
                Stack<char> & operators, int & operation,
                  string & postfix)
{
   if (operators.empty())                  //if the string is empty
   {
      operators.push(infix[spot]);
      operators1.push(operation);
      spot += 1;                          //move to next item in input
      if (infix[spot] == ' ')             //skip reading spaces
         spot += 1;
   }
   else if (spot < infix.size())  //while we still have data in the string
   {
      if (operators1.top() < operation)    //if the order is higher
      {
         operators.push(infix[spot]);
         operators1.push(operation);
         spot++;
         if (infix[spot] == ' ')
            spot++;
         if (operators1.top() == 9)        //if we run into a ')'
         {
            operators.pop();
            operators1.pop();
            while (operators.top() != '(') // pull all out until '('
            {
               postfix += operators.top();
               operators.pop();
               operators1.pop();
            }
            operators.pop();              //pop off '('
            operators1.pop();
            
         }
      }
      else if (operators1.top() >= operation)  // if the order is lower
      {
         if (operation == 0)              // if the operation is '('
         {
            operators.push(infix[spot]);
            operators1.push(operation);
            spot++;
            if (infix[spot] == ' ')
               spot++;
            return;
         }
         postfix += operators.top();      //top, pop, then push.
         if (infix[spot+1] != ' ')        //we add our own spaces
            postfix += ' '; 
         operators.pop();
         operators1.pop();
         operators.push(infix[spot]);
         operators1.push(operation);
          
         
         spot++;
         if (infix[spot] == ' ')         //skip reading in spaces in input
            spot++;
      }
   }
   
   if (spot == infix.size()) // if we have reach the end of the given string
   {
      int i = 0;
      while (!operators.empty())    //get the rest of the operators left over
      {
         
         postfix += ' ';                 //add our own spaces
         postfix += operators.top();
         operators.pop();
         operators1.pop();
         i++;
      }
   }
}
/***************
 * Checks to see what symbol we have ran into
 ******************/
int check(const string & infix, const int & spot)
{
   char tmp = infix[spot];

   //checks what operator we are at and returns a number likewise
   switch (tmp)  
   {
      case '(':
         return 0;
         break;
      case ')':
         return 9;
         break;
      case '+':
         return 1;
         break;
      case '-':
         return 1;
         break;
      case '*':
         return 2;
         break;
      case '/':
         return 2;
         break;
      case '%':
         return 2;
         break;
      case '^':
         return 3;
         break;
      default:
         return -1;
         break;
   }
   return -1;
}
