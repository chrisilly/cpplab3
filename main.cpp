#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "personregister.h"
#include "person.h"
#include "main.h"
#include <iostream>
#include <fstream>

using namespace std;

int maxSize = 10;
string testName = "Chell";
string testAddress = "Aperture";
string testPhoneNumber = "+108 176 314 914";
bool running = true;

int main()
{
    // _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    PersonRegister magnusArchives(maxSize);
    ReadRegister(magnusArchives, "PersonExempel.txt");
    magnusArchives.Print();

    RemovePersonTest(magnusArchives);

    cout << "Exiting program..." << endl;

    // magnusArchives.~PersonRegister(); // You're not supposed to call destructors explicitly, says stackoverflow

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    _CrtDumpMemoryLeaks();

    // return 0;
}

void RemovePersonTest(PersonRegister &personRegister)
{
    // Add dummy person
    Person dummy("Remove Me", "Deletemelane 12, 000 00 KILLME");
    personRegister.AddToRegister(&dummy);
    // Print
    personRegister.Print();

    // Remove person
    personRegister.RemoveFromRegister(&dummy);
    // Print
    personRegister.Print();

    cout << "Removed person "; dummy.Print();
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
            string address;
            getline(myfile, address);
            Person entry(name, address);
            personRegister.AddToRegister(&entry);
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