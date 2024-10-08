#include "personregister.h"

#include <fstream>
#include <iostream>

using namespace std;

PersonRegister::PersonRegister(int max)
{
    // Constructor code
    persons = new Person[max];
}

// bool PersonRegister::ReadRegister(PersonRegister &personRegister, string fileName)
// {
//     string line;
//     ifstream myfile(fileName);
//     if (myfile.is_open())
//     {
//         while (getline(myfile, line))
//         {
//             while (line.length() == 0 && getline(myfile, line))
//                 ; // what?
//             string name(line);
//             string adress;
//             getline(myfile, adress);
//             personRegister.AddToRegister(&Person(name, adress));
//         }
//         myfile.close();
//         return true;
//     }
//     else 
//     {
//         cout << "Unable to open file";
//         return false;
//     }
// }

// bool PersonRegister::AddToRegister(const Person* const)
// {
//     // code
// }

// bool PersonRegister::AddToRegister(const string &name, const string &address)
// {
//     // code
// }

void PersonRegister::RemoveEntry(Person *person)
{
    // code
}

// Person PersonRegister::*SearchByName(const string name)
// {
//     // code
// }

void PersonRegister::Print()
{
    for (int i = 0; i < 9; i++)
        persons[i].Print();
}

void PersonRegister::PlagueOfDeath()
{
    // code
}

PersonRegister::~PersonRegister()
{
    // Destructor code
}