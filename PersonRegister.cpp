#include "personregister.h"

#include <iostream>

using namespace std;

const string divider = "----------------------------------\n";

PersonRegister::PersonRegister(const int max)
{
    // Constructor code
    this->size = max;
    personCount = 0;

    persons = new Person[max];
    for (int i = 0; i < max; i++)
        persons[i] = Person("undefined", "undefined");
}

bool PersonRegister::AddToRegister(const Person* person)
{
    if(person == nullptr) return false;

    // Is the personRegister full?
    if(personCount >= size)
    {
        // persons -= personCount;
        personCount = 0;
    }

    // Add new person
    persons[personCount++] = *person;

    return true;
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
    persons[personCount++] = person;

    return true;
}

bool PersonRegister::AddToRegister(const string &name, const string &address)
{
    if(personCount >= size)
    {
        // persons -= personCount;
        personCount = 0;
    }

    persons[personCount++] = Person(name, address);
    return true;

    return false;
}

void PersonRegister::RemoveEntry(Person *person)
{
    if(person != nullptr)
        person->Wipe();
    else
        cout << "Cannot remove nullptr" << endl;
}

Person* PersonRegister::SearchByName(const string &name) const
{
    Person* target;

    for (Person *pointer = persons; pointer < persons + size; ++pointer)
    {
        // string currentName = pointer->getName();
        // cout << "currentName: " << currentName << endl;
        // cout << "current pointer->getName(): " << pointer->getName() << endl;

        if(pointer->getName() == name) 
        {
            cout << "Person " << name << " found." << endl;
            return pointer;
        }
    }

    cout << "Person " << name << " not found." << endl;
    return nullptr;
}

void PersonRegister::Print()
{
    cout << divider;

    for (Person *pointer = persons; pointer < persons+size; ++pointer)
    {
        if(pointer == nullptr)
            throw new exception("Tried printing nullptr.");
        
        pointer->Print();
    }
    
    cout << divider;
}

/// @brief Clears the register; empties it.
void PersonRegister::PlagueOfDeath()
{
    for (Person *pointer = persons; pointer < persons+size; ++pointer)
        pointer->Wipe();
}

PersonRegister::~PersonRegister()
{
    delete[] persons;
}