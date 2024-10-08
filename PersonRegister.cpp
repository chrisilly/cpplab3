#include "PersonRegister.h"
#include <fstream>

class PersonRegister
{
    PersonRegister(int max)
    {
        // implement constructor
    }

    bool ReadRegister(PersonRegister &personRegister, string fileName) 
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
                string adress;
                getline(myfile, adress);
                personRegister.AddToRegister(&Person(name, adress));
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

    bool AddToRegister(const Person* const)
    {
        // code 
    }
};