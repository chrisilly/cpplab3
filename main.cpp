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

    AddPersonTest(magnusArchives);

    RemovePersonTest(magnusArchives);

    SearchByNameTest(magnusArchives);

    cout << "Exiting program..." << endl;

    // magnusArchives.~PersonRegister(); // You're not supposed to call destructors explicitly, says stackoverflow

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    _CrtDumpMemoryLeaks();

    // return 0;
}

void AddPersonTest(PersonRegister &personRegister)
{
    // Add dummy person
    Person dummy("YOUR NEW ROOMMATE", "Your apartment");
    cout << "Attempting to add new person to register: "; dummy.Print();
    personRegister.AddToRegister(&dummy);
    // Print
    personRegister.Print();
}

void RemovePersonTest(PersonRegister &personRegister)
{
    // Remove person
    personRegister.RemoveFromRegister(personRegister.begin());
    // Print
    personRegister.Print();
}

void SearchByNameTest(PersonRegister &personRegister)
{
    // Search for non-existing
    personRegister.SearchByName("Chell");

    // Add new person
    personRegister.AddToRegister("Chell", "Aperture");
    personRegister.Print();

    // Search for existing person
    personRegister.SearchByName("Chell");
}

void SearchByAnyTest(PersonRegister &personRegister)
{

}

void EmptyRegisterTest(PersonRegister &personRegister)
{

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