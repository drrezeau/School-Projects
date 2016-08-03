#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class MyString
{
	private:
		char *string;
		int mySize;

		int getNewSize(const char * newString)
		{
			int newSize = 0;
			for (int i = 0; newString[i] != '\0'; i++)
				newSize++;
			return newSize;
		}

	public:

		/*****************************************************
		* Default Constructor setting to \0
		* WORKING
		*****************************************************/
		MyString()
		{
			mySize = 1;
			string = new char[1]();
		}
		/*****************************************************
		* Non-Default Constructor for Size
		* WORKING
		*****************************************************/
		MyString( int size)
		{
			mySize = size;
			string = (char *) malloc(mySize);
		}

		/*****************************************************
		* Non-Default Constructor for a string
		* WORKING
		*****************************************************/
		MyString( char const* myString)
		{
			mySize = getNewSize(myString);
			string = (char *) malloc(mySize);
			for (int i = 0; i < mySize; i++)
			string[i] = myString[i];
		}

		/*****************************************************
		* Copy Constructor for a string
		* WORKING
		*****************************************************/
		MyString(const MyString& S)
		{
			mySize = S.mySize;
			string = new char[mySize];
			for(int i = 0; i < (mySize); i++)
			{
				string[i] = S.string[i];
			}
			if(string[mySize - 1] != '\0'){string[mySize] = '\0';}
		}

		/*****************************************************
		* Destructor
		* WORKING
		*****************************************************/
		~MyString()
		{
			free(string);
			delete [] string;
		}

		/*****************************************************
		* Sets the string
		* WORKING
		*****************************************************/
		void setString(char const* newString)
		{
			// cout << "SET_STRING\n";

			mySize = getNewSize(newString);
			// cout << mySize << endl;
			char* tmp = (char *) realloc(string, mySize);

			if(tmp != NULL) {
				string = tmp;
				for (int i = 0; i < mySize; i++)
					string[i] = newString[i];
			}
			else
				cout << "ERROR!\n";

		}

		/*****************************************************
		* returns the string
		* WORKING
		*****************************************************/
		int length()
		{
			return mySize;
		}

		/*****************************************************
		* Display the content of the string
		* WORKING
		*****************************************************/
		void display()
		{
			// cout << "DISPLAY\n";
			if (string[0] != '\0')
				cout << string << endl; 
			else
				cout << "Empty\n";
		}

		/*****************************************************
		* Allows for user to input the content of the string
		* WORKING
		*****************************************************/
		void input()
		{
			cout << "Enter your string:\n>";
			char* tmp = new char[256];
			cin.getline(tmp, 256);

			mySize = getNewSize(tmp);
			char* tmp2 = (char *) realloc(string, mySize);

			if(tmp2 != NULL)
			{
				string = tmp2;
				string = tmp;
			}
			else
				cout << "ERROR\n";



		}

		/*****************************************************
		* Clears the content of the string
		* WORKING
		*****************************************************/
		void clear()
		{
			// cout << "CLEAR\n";
			string = (char *) calloc(mySize, sizeof(char));
		}

		/*****************************************************
		* Appends a c-string to the end of the string
		* WORKING 
		*****************************************************/
		void append(char const* appendString)
		{
			// cout << "APPEND\n";
			int appendSize = getNewSize(appendString);
			int newSize =  mySize + appendSize;

			char *tmp = (char *) realloc(string, newSize);

			if(tmp != NULL) {
				string = tmp;
				for (int i = 0; i < appendSize; i++)
					string[i+mySize] = appendString[i];
				mySize = newSize;
			}
			else
				cout << "ERROR!\n";

		}



};

#endif