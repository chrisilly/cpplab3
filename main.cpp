#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "personregister.h"
#include "person.h"
#include "main.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Program;

int maxSize = 10;
string testName = "Chell";
string testAddress = "Aperture";
string testPhoneNumber = "+108 176 314 914";
bool running = true;

int main()
{
    // _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    Person person(testName, testAddress);
    person.Print();

    PersonWithPhoneNumber* personWithPhoneNumber = new PersonWithPhoneNumber(testName, testAddress, testPhoneNumber);
    personWithPhoneNumber->Print();

    PersonRegister magnusArchives(maxSize);
    Program::ReadRegister(magnusArchives, "PersonExempel.txt");
    magnusArchives.Print();

    delete personWithPhoneNumber;
    // magnusArchives.~PersonRegister(); // You're not supposed to call destructors explicitly, says stackoverflow

    cout << "Exiting program..." << endl;

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    _CrtDumpMemoryLeaks();

    // return 0;
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
            personRegister.AddToRegister(&Person(name, address));
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