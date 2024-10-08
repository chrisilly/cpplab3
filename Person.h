#ifndef PERSON
#define PERSON

#include <string>

class Person
{
    std::string name;
    std::string address;

    public:

    Person(std::string name, std::string address);
    Person();

    void Print();
};
#endif