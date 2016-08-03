#include <iostream>
#include <string.h>
#include "myString.h"
using namespace std;

int main() 
{
	cout << "This is my test program\n";

	// Testing default constructor
	cout << "Testing default constructor\n";
	MyString *test = new MyString();
	test->setString("DEFAULT CONSTRUCTOR");
	test->display();

	//Testing of the non-default constructor
	cout << "\nTesting non-default constructor\n";
	MyString *text;
	text = new MyString("YEAH");
	text->display();

	//Testing clear and setstring
	cout << "\nTesting the clear and setstring funtions\n";
	text->clear();
	text->setString("NEWSTRING");
	text->display();

	//testing user input
	cout << "\nTesting the user input function\n";
	text->clear();
	text->input();
	text->display();

	//testing copy constructor
	cout << "\nTesting the copy constructor\n";
	MyString *text2 = new MyString(*text);
	text2->display();

	// Testing append function
	cout << "\nTesting the append function\n";
	text->append("-APPEND");

	text->display();
	cout << text->length() << endl;
}