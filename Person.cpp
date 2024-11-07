#include <iostream>
#include "person.h"

using namespace std;

Person::Person(string name, string address) : name{name}, address{address}
{
    // this->name = name;
    // this->address = address;
}

Person::Person() {}

PersonWithPhoneNumber::PersonWithPhoneNumber(string name, string address, string phoneNumber) : Person{name, address}, phoneNumber{phoneNumber}
{
    // this->phoneNumber = phoneNumber;
}

void Person::Print()
{
    cout << name << ", " << address << endl;
}

void PersonWithPhoneNumber::Print()
{
    cout << name << ", " << address << ", " << phoneNumber << endl;
}

void Person::Wipe()
{
    name = address = "";
}

/// @brief Checks whether another Person object contains identical data
/// @param other The Person object with which to compare
/// @return 
bool Person::Matches(Person& other)
{
    if(this->getData() == other.getData())
        return true;

    return false;
}

Person::~Person()
{
    // destructor code here...
}

string Person::getName() { return name; }

/// @return name and address in a single string
string Person::getData() { return name + " " + address; }

// Assignment 4

bool Person::operator<(const Person& that)
{
    return this->name < that.name;
}