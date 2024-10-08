using namespace std;

#include "person.h"
#include <iostream>

class Person
{
    string name;
    string address;

public:

    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }
    
    Person()
    {
        // implement constructor
    }

    void Print()
    {
        cout << name << ", " << address << endl;
    }
};