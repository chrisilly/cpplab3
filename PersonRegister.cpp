#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "personregister.h"

#include <iostream>
#include <cassert>

using namespace std;

const string divider = "----------------------------------\n";

PersonRegister::PersonRegister(const int capacity) : size{capacity}
{
    // Constructor code
    // this->size = max;
    personCount = 0;

    persons = new Person[capacity];
}

bool PersonRegister::AddToRegister(const Person* const person)
{
    // assert evaluates a bool
    // (A pointer can implicitly convert to a bool based on whether it's a nullptr or not)
    assert(person); // fail the program if person is nullptr (std::abort)

    // is person nullptr? (Error handling for production mode)
    // if(!person) return false;

    // Is the personRegister full?
    if(personCount >= size)
    {
        cout << "Failed to add new person: Person register is full." << endl;
        return false;
    }

    // Add new person
    persons[personCount++] = *person;

    return true;
}

bool PersonRegister::AddToRegisterByReference(const Person& person)
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
}

/// @brief 
/// @param person this should point to the object that's meant to be removed from the register
void PersonRegister::RemoveFromRegister(Person* person)
{
    assert(person);

    for (Person* pointer = persons; pointer < persons + size; ++pointer)
    {
        if(pointer == person)
        {
            cout << "Found and removed "; pointer->Print();
            // std::remove(pointer, pointer + size, *pointer);
        }
    }
}

Person* PersonRegister::SearchByName(const string &name) const
{
    for (Person *pointer = persons; pointer < persons + size; ++pointer)
    {
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
        assert(pointer);
        
        pointer->Print();
    }
    
    cout << divider;
}

/// @brief Removes all persons in the Person Register
void PersonRegister::EmptyRegister()
{
    for (Person *pointer = persons; pointer < persons+size; ++pointer)
    {
        // removal logic here...
    }
}

PersonRegister::~PersonRegister()
{
    // delete[] persons;
}

// Assignment 4

Person* PersonRegister::begin() { return persons; }
Person* PersonRegister::end() { return persons + personCount; }