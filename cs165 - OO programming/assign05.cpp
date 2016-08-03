/************************************************
* Program:
*    Assignment 05, Address Book
*    Brother Burton, CS 165
* Author:
*    David Lambertson
* Summary:
*    This program is meant to create a class called Address,
*    and use it to read information into a custom variable.
*    This saves the address allowing the user to see it and save
*    the data. 
*****************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


const int NUMBER_OF_ADDRESS = 5; //creates the constant number for the array.
const string FILENAME = "/home/cs165sb/contacts.txt";
                  //create a constant file name


/*********************
* this class holds all the information for the custom variable along with
* all the methods. It contains six member variables, 7 mutuator methods,
* and 7 accessor methods.
**********************/
class Address 
{
   private:
      string name;
      string address;
      string city;
      string state;
      string zip;
      string phone;

   public:
      Address();
      Address(Address address[]);
      string getName() const { return name; }
      string getAddress() const { return address; }
      string getCity() const { return city; }
      string getState() const { return state; }
      string getZip() const { return zip; }
      string getPhone() const { return phone; }
      void display();
      void setName(string name) { this->name = name; }
      void setAddress(string address) { this->address = address; }
      void setCity(string city) { this->city = city; }
      void setState(string state) { this->state = state; }
      void setZip(string zip) { this->zip = zip; }
      void setPhone(string phone) { this->phone = phone; }
      Address setContact();
   
};

/********************
* this method from Address is the default
* setting everthing equal to a blank string already.
******************/
Address :: Address()
{
   name = "";
   address = "";
   city = "";
   state = "";
   zip = "";
   phone = "";

}

/***************************
* this method calls the other setter methods 
* to set all the variables equal the the input
* from the user.
*************************/
Address Address :: setContact()
{
   Address user;

   string name;
   cout << "Name: ";
   getline(cin, name);
   user.setName(name);

   string address;
   cout << "Address: ";
   getline(cin, address);
   user.setAddress(address);

   string city;
   cout << "City: ";
   getline(cin, city);
   user.setCity(city);

   string state;
   cout << "State: ";
   getline(cin, state);
   user.setState(state);

   string zip;
   cout << "Zip: ";
   getline(cin, zip);
   user.setZip(zip);

   string phone;
   cout << "Phone: ";
   getline(cin, phone);
   user.setPhone(phone);


   return user;
}

/**************************
* this method just takes the value for each variable within the named class
* and displays it as an address.
************************/
void Address :: display()
{
   cout << endl;
   cout << getName() << endl;
   cout << getAddress() << endl;
   cout << getCity() << ", " << getState() << "  " << getZip() << endl;
   cout << getPhone() << endl;
}

/***************************
* this function takes the file name and opens it and
* reads it into the custom array, giving us the last 5
* addresses.
***************************/
void readFile(Address address[])
{
   ifstream fin("/home/cs165sb/contacts.txt");

   string name;
   string pAddress;
   string city;
   string state;
   string zip;
   string phone;
   if (fin.fail()) // if opening file fails, display Error.
      cout << "Error!!";

   for (int i = 0; i < NUMBER_OF_ADDRESS; i++) //keeps looping until file is done.
   {
      getline(fin, name);
      getline(fin, pAddress);
      getline(fin, city);
      getline(fin, state);
      getline(fin, zip);
      getline(fin, phone);
      address[i].setName(name);
      address[i].setAddress(pAddress);
      address[i].setCity(city);
      address[i].setState(state);
      address[i].setZip(zip);
      address[i].setPhone(phone);     
   }
}

/****************
* this function just sets the instructor
* to the right variables.
***************/
void inputInstructor(Address &instructor)
{
   string name = "Brother Burton";
   string address = "AUS 216F";
   string city = "Rexburg";
   string state = "ID";
   string zip = "83460";
   string phone = "208-496-7614";

   
   instructor.setName(name);
   instructor.setAddress(address);
   instructor.setCity(city);
   instructor.setState(state);
   instructor.setZip(zip);
   instructor.setPhone(phone);
}

/**********************
* main creates each custom variable and then calls the other
* methods of the class to get the desired readings for each custom variable.
* then it displays each one onto the screen for the user to see. 
**********************/
int main()
{

   Address instructor;
   Address user;
   Address address[NUMBER_OF_ADDRESS];
   
   inputInstructor(instructor); // sets the instructor variable
   user = user.setContact(); // sets user input into variable
   
   readFile(address); // saves file information into an array

   //goes into displaying
   instructor.display();
   user.display();
   for (int i = 0; i < NUMBER_OF_ADDRESS; i++)
      address[i].display();

   return 0;

}
