#include "personregister.h"

#include <iostream>

using namespace std;

PersonRegister::PersonRegister(int max)
{
    // Constructor code
    this->size = max;
    personCount = 0;

    persons = new Person[max];
    for (int i = 0; i < max; i++)
        persons[i] = Person("undefined", "undefined");
}

bool PersonRegister::AddToRegister(const Person person)
{
    // Is the personRegister full?
    if(personCount >= size)
    {
        // persons -= personCount;
        personCount = 0;
    }

    // Add new person
    // *persons = Person(*person);
    // personCount++;
    // persons++;

    // Add new person
    persons[personCount++] = person;

    // Lisa's code -- works because she made `name` and `address` public
    // persons[personCount].name = person->name;
    // persons[personCount].address = person->address;
    // personCount++;

    return true;
}

bool PersonRegister::AddToRegister(const string &name, const string &address)
{
    for (Person *pointer = persons; pointer < persons+size; ++pointer)
    {
        *pointer = Person(name, address); 
        return true;
    }
    
    return false;
}

void PersonRegister::RemoveEntry(Person *person)
{
    // code
}

// Person PersonRegister::*SearchByName(const string name)
// {
//     // code
// }

void PersonRegister::Print()
{
    for (Person *pointer = persons; pointer < persons+size; ++pointer)
        pointer->Print();
}

void PersonRegister::PlagueOfDeath()
{
    // code
}

PersonRegister::~PersonRegister()
{
    delete[] persons;
}