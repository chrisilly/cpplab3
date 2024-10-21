#include <iostream>
#include "person.h"

using namespace std;

Person::Person(string name, string address)
{
    this->name = name;
    this->address = address;
}

Person::Person() {}

void Person::Print()
{
    cout << name << ", " << address << endl;
}

void Person::Wipe()
{
    name = address = "";
}

string Person::getName() { return name; }

/// @return name and address in a single string
string Person::getData() { return name + " " + address; }