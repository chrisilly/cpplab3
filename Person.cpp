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