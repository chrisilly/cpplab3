#ifndef PERSON_REGISTER
#define PERSON_REGISTER

#include "person.h"

#include <string>

class PersonRegister
{
    Person *persons;
    int personCount;
    int size;

    public:

    PersonRegister(const int max);

    bool AddToRegisterByReference(const Person& person);
    bool AddToRegister(const std::string &name, const std::string &address);
    bool AddToRegister(const Person* const person);
    void RemoveFromRegister(Person *person);
    Person *SearchByName(const std::string &name) const;
    Person* SearchByAny(const std::string& searchTerm, Person* startOnNext) const;
    void Print();

    /// @brief Empties and deletes all Person Registry content
    void PlagueOfDeath();

    ~PersonRegister();
};
#endif