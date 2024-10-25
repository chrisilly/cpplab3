#include "personregister.h"

#include <iostream>
#include <cassert>

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
        // Start from the beginning of the register
        personCount = 0;
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

    return false;
}

void PersonRegister::RemoveFromRegister(Person* person)
{
    assert(person);

    int removedCounter = 0;

    for (Person* pointer = persons; pointer < persons + size; ++pointer)
    {
        if((*pointer).Matches(*person))
        {
            pointer->Wipe();
            removedCounter++;
        }
    }
    
    cout << "Found and removed " << removedCounter << " person(s) matching: ";
    person->Print();
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
        assert(pointer);
        
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