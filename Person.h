#ifndef PERSON
#define PERSON

#include <string>

class Person
{
protected:
    std::string name;
    std::string address;

public:
    Person(std::string name, std::string address);
    Person();

    void Wipe();
    bool Matches(Person& other);

    virtual void Print();
    std::string getName();
    std::string getData();

    virtual ~Person();

    bool Person::operator==(const Person* other);
    // void Person::operator=(const Person* const other);

    // Assignment 4

    bool operator<(const Person& that);
};

class PersonWithPhoneNumber: public Person
{
    std::string phoneNumber;

public:
    PersonWithPhoneNumber(std::string name, std::string address, std::string phoneNumber);

    void Print() override;
};
#endif