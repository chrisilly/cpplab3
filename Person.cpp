#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "person.h"

using namespace std;

Person::Person(string name, string address) : name{name}, address{address} {}

Person::Person() {}

PersonWithPhoneNumber::PersonWithPhoneNumber(string name, string address, string phoneNumber) : Person{name, address}, phoneNumber{phoneNumber} {}

void Person::Print()
{
    cout << name << ", " << address << endl;
}

void PersonWithPhoneNumber::Print()
{
    cout << name << ", " << address << ", " << phoneNumber << endl;
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

/// @brief Tells you whether another Person object's memory address matches this one's.
/// @param other 
/// @return 
bool Person::operator==(const Person* other) { return this == other; }

// void Person::operator=(const Person* const other)
// {
        
// }

// Assignment 4

bool Person::operator<(const Person& that)
{
    return this->name < that.name;
}