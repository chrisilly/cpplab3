#ifndef PERSON_REGISTER
#define PERSON_REGISTER

#include "person.h"

#include <string>

class PersonRegister
{
    Person *persons;
    bool *isDefined; // keeps track of which slots in the ´persons´ array are occupied
    int personCount;
    int size;

    public:

    PersonRegister(int max);

    bool AddToRegister(const Person* person);
    bool AddToRegister(const std::string &name, const std::string &address);
    void RemoveEntry(Person *person);
    Person *SearchByName(const std::string &name) const;
    void Print();

    /// @brief Empties and deletes all Person Registry content
    void PlagueOfDeath();

    ~PersonRegister();
};
#endif