#ifndef PERSON_REGISTER
#define PERSON_REGISTER

#include "person.h"

#include <string>

class PersonRegister
{
    Person *persons;

    public:

    PersonRegister(int max);

    bool ReadRegister(PersonRegister &personRegister, std::string fileName);

    bool AddToRegister(const Person* const);
    bool AddToRegister(const std::string &name, const std::string &adress);
    void RemoveEntry(Person *person);
    Person *SearchByName(const std::string &name) const;
    void Print();

    /// @brief Empties and deletes all Person Registry content
    void PlagueOfDeath();

    ~PersonRegister();
};
#endif