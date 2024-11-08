#ifndef PERSON_REGISTER
#define PERSON_REGISTER

#include "person.h"

#include <string>

class PersonRegister
{
    Person *persons;

    /// @brief How many slots are OCCUPIED in the register
    int size;

    /// @brief The maximum amount of slots in the register
    int capacity;

    public:

    PersonRegister(const int capacity);

    bool AddToRegisterByReference(const Person& person);
    bool AddToRegister(const std::string &name, const std::string &address);
    bool AddToRegister(const Person* const person);
    void RemoveFromRegister(Person *person);
    Person *SearchByName(const std::string &name) const;
    Person* SearchByAny(const std::string& searchTerm, Person* startOnNext) const;
    void Print();
    void PrintCapacity();

    void EmptyRegister();

    ~PersonRegister();

    //Assignment 4
    Person* begin();
    Person* end();
};
#endif