#include "personregister.h"

#include <iostream>

using namespace std;

PersonRegister::PersonRegister(int max)
{
    // Constructor code
    this->size = max;
    personCount = 0;

    persons = new Person[max];

    // isDefined = new bool[max];
    // for (int i = 0; i < max; i++)
    //     isDefined[i] = false;
}

bool PersonRegister::AddToRegister(const Person* person)
{
    // Does person already exist?

    // Is the newly given person even a valid person?
    Person *newPerson = new Person(*person);
    if(newPerson == nullptr) return false;

    // Is the personRegister full?
    if(personCount >= size)
    {
        persons -= personCount;
        personCount = 0;
    }

    // Add new person
    *persons = *new Person(*person);
    personCount++;
    persons++;

    return true;
}

bool PersonRegister::AddToRegister(const string &name, const string &address)
{
    for (Person *pointer = persons; pointer != persons+size; ++pointer)
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
    for (Person *pointer = persons; pointer != persons+size; ++pointer)
        pointer->Print();
}

void PersonRegister::PlagueOfDeath()
{
    // code
}

PersonRegister::~PersonRegister()
{
    // Destructor code
}