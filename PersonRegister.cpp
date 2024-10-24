#include "personregister.h"

#include <iostream>

using namespace std;

const string divider = "----------------------------------\n";

PersonRegister::PersonRegister(const int max) : size{max}
{
    // Constructor code
    // this->size = max;
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

void PersonRegister::RemoveFromRegister(Person *person)
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

Person* PersonRegister::SearchByAny(const string& searchTerm, Person* startOnNext) const
{
    string personData;
    string startOnNextData;
    bool started = false;

    if(startOnNext == nullptr)
        started = true;
    else
        startOnNextData = startOnNext->getData();

    for (Person* pointer = persons; pointer < persons+size; ++pointer)
    {
        personData = pointer->getData();

        if(started)
            // Does the person data contain the search term? Is it a 'hit'?
            if(pointer->getData().find(searchTerm) != string::npos) 
                return pointer;

        // Start checking for more hits after we've passed the startOnNext Person in the array 
        if(startOnNextData == personData)
            started = true;
    }

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