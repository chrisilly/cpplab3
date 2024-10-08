using namespace std;
#include <string>
#include "Person.h"

class PersonRegistry
{
    Person *persons;

    public:

    PersonRegistry(int max);

    bool AddToRegister(const Person* const);
    bool AddToRegister(const string &name, const string &adress);
    void RemoveEntry(Person *person);
    Person *SearchByName(const string &name) const;
    void Print();

    /// @brief Empties and deletes all Person Registry content
    void PlagueOfDeath();

    ~PersonRegistry();
};