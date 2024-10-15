#include "personregister.h"
#include "person.h"
#include "main.h"
#include <iostream>
#include <fstream>

using namespace std;

int maxSize = 10;
string testName = "Chell";
string testAddress = "Aperture";

int main()
{
    Person person(testName, testAddress);
    person.Print();

    PersonRegister magnusArchives(maxSize);
    Program::ReadRegister(magnusArchives, "PersonExempel.txt");
    magnusArchives.Print();
}

bool Program::ReadRegister(PersonRegister &personRegister, string fileName)
{
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line))
                ; // what?
            string name(line);
            string address;
            getline(myfile, address);
            // Person entry(name, address);
            personRegister.AddToRegister(Person(name, address));
        }
        myfile.close();
        return true;
    }
    else 
    {
        cout << "Unable to open file";
        return false;
    }
}