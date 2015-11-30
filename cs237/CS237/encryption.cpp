#include <iostream>
using namespace std;

int convertLetter(char message)
{
   int number;
   char option = message;
   
   switch(option)
   {
      case 'a':
         number = 0;
         return number;
      case 'A':
         number = 0;
         return number;
      case 'b':
         number = 1;
         return number;
      case 'B':
         number = 1;
         return number;
      case 'c':
         number = 2;
         return number;
      case 'C':
         number = 2;
         return number;
      case 'd':
         number = 3;
         return number;
      case 'D':
         number = 3;
         return number;
      case 'e':
         number = 4;
         return number;
      case 'E':
         number = 4;
         return number;
      case 'f':
         number = 5;
         return number;
      case 'F':
         number = 5;
         return number;
      case 'g':
         number = 6;
         return number;
      case 'G':
         number = 6;
         return number;
      case 'h':
         number = 7;
         return number;
      case 'H':
         number = 7;
         return number;
      case 'i':
         number = 8;
         return number;
      case 'I':
         number = 8;
         return number;
      case 'j':
         number = 9;
         return number;
      case 'J':
         number = 9;
         return number;
      case 'k':
         number = 10;
         return number;
      case 'K':
         number = 10;
         return number;
      case 'l':
         number = 11;
         return number;
      case 'L':
         number = 11;
         return number;
      case 'm':
         number = 12;
         return number;
      case 'M':
         number = 12;
         return number;
      case 'n':
         number = 13;
         return number;
      case 'N':
         number = 13;
         return number;
      case 'o':
         number = 14;
         return number;
      case 'O':
         number = 14;
         return number;
      case 'p':
         number = 15;
         return number;
      case 'P':
         number = 15;
         return number;
      case 'q':
         number = 16;
         return number;
      case 'Q':
         number = 16;
         return number;
      case 'r':
         number = 17;
         return number;
      case 'R':
         number = 17;
         return number;
      case 's':
         number = 18;
         return number;
      case 'S':
         number = 18;
         return number; 
     case 't':
         number = 19;
         return number;
     case 'T':
         number = 19;
         return number;
      case 'u':
         number = 20;
         return number;
      case 'U':
         number = 20;
         return number;
      case 'v':
         number = 21;
         return number;
      case 'V':
         number = 21;
         return number;
      case 'w':
         number = 22;
         return number;
      case 'W':
         number = 22;
         return number;
      case 'x':
         number = 23;
         return number;
      case 'X':
         number = 23;
         return number;
      case 'y':
         number = 24;
         return number;
      case 'Y':
         number = 24;
         return number;
      case 'z':
         number = 25;
         return number;
      case 'Z':
         number = 25;
         return number;
      case ' ':
         return -4;
      default:
         cout << "Error!\n";
         return -10;
   }
}

char convertNumberToLetter(int number)
{
      switch(number)
   {
      case 0:
         return 'a';
      case 1:
         return 'b';
      case 2:
         return 'c';
      case 3:
         return 'd';
      case 4:
         return 'e';
      case 5:
         return 'f';
      case 6:
         return 'g';
      case 7:
         return 'h';
      case 8:
         return 'i';
      case 9:
         return 'j';
      case 10:
         return 'k';
      case 11:
         return 'l';
      case 12:
         return 'm';
      case 13:
         return 'n';
      case 14:
         return 'o';
      case 15:
         return 'p';
      case 16:
         return 'q';
      case 17:
         return 'r';
      case 18:
         return 's';
      case 19:
         return 't';
      case 20:
         return 'u';
      case 21:
         return 'v';
      case 22:
         return 'w';
      case 23:
         return 'x';
      case 24:
         return 'y';
      case 25:
         return 'z';
      case -1:
         return ' ';
   }

}
   


int main()
{
   char  option;
   do
   {
      do
      {
         cout << "What would you like to do.\n"
              << "Encode(E) or Decode(D) or quit(q)?\n"
              << ">";
         cin >> option;

         if (option == 'q')
            break;
      }
      while ((option != 'E') && (option != 'D'));
      
      
      string message;
      int number;
      string encrypt;
      if (option == 'E')
      {
         cout << "What is your message to encrypt?\n";
         cin.ignore(256, '\n');
         getline(cin, message);
         
         for (int i = 0; i < message.size(); i++)
         {
            number = convertLetter(message[i]);
            number = (number + 3) % 26;
            encrypt[i] = convertNumberToLetter(number);
         }
         cout << endl;
         for (int i = 0; i < message.size(); i++)
            cout << encrypt[i];
         cout << endl;
      }
      else if (option == 'D')
      {
         cout << "What is your message to decode?\n";
         cin.ignore(256, '\n');
         getline(cin, message);
         
         for (int i = 0; i < message.size(); i++)
         {
            number = convertLetter(message[i]);
            number = (number - 3) % 26;
            
            if (number == -7)
               number = -1;
            else if (number == -1)
               number = 25;
            else if (number == -2)
               number = 24;
            else if (number == -3)
               number = 23;
            
            encrypt[i] = convertNumberToLetter(number);
         }
         cout << endl;
         for (int i = 0; i < message.size(); i++)
            cout << encrypt[i];
         cout << endl;
      }
   }
   while (option != 'q');
   return 0;
}
