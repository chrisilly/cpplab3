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
bool running = true;

int main()
{
    running = true;

    Person person(testName, testAddress);
    person.Print();

    PersonRegister magnusArchives(maxSize);
    Program::ReadRegister(magnusArchives, "PersonExempel.txt");
    magnusArchives.Print();

    while (running)
    {
        string input;
        getline(cin, input); // this should use `tolower()` or something

        if(input == "quit")
            running = false;
        else if(input == "search")
        {
            string name;
            cout << "Enter name: "; getline(cin, name);
            Person* searchResult = magnusArchives.SearchByName(name);

            // Don't print unless you find a person
            if(searchResult != nullptr) searchResult->Print();
        }
        else if(input == "freesearch")
        {
            string searchTerm;
            cout << "Enter search: "; getline(cin, searchTerm);
            
            #pragma region bad attempt at better code
            // Person* searchResult1 = magnusArchives.FreeSearch(searchTerm, nullptr);
            // Person* searchResult2 = nullptr;
            // Person* searchResult3 = nullptr;

            // Person* searchResults[3];
            // searchResults[0] = searchResult1;
            // searchResults[1] = searchResult2;
            // searchResults[2] = searchResult3;

            // for (Person** pointer = searchResults + 1; pointer < searchResults + 3; ++pointer)
            // {
            //     *pointer = magnusArchives.FreeSearch(searchTerm, *searchResults);
            // }
            
            // for (Person** pointer = searchResults; pointer < searchResults + 3; ++pointer)
            // {
            //     if(*pointer == nullptr)
            //         cout << "Empty search result." << endl;
            //     else
            //         (*pointer)->Print();
            // }
            #pragma endregion

            // Bad, defeated code below
            Person* searchResult1 = magnusArchives.FreeSearch(searchTerm, nullptr);
            Person* searchResult2 = magnusArchives.FreeSearch(searchTerm, searchResult1);
            Person* searchResult3 = magnusArchives.FreeSearch(searchTerm, searchResult2);
            
            if(searchResult1 != nullptr) searchResult1->Print();
            if(searchResult2 != nullptr) searchResult2->Print();
            if(searchResult3 != nullptr) searchResult3->Print();
        }
        else if(input == "add")
        {
            string name, address;
 
            cout << "Enter name: "; getline(cin, name);
            cout << "Enter address: "; getline(cin, address);
            Person newPerson(name, address);
            
            magnusArchives.AddToRegister(newPerson);
            newPerson.Print();
        }
        else if(input == "remove")
        {
            string name;
            cout << "Enter name of person to remove: "; getline(cin, name);
            Person* victim = magnusArchives.SearchByName(name);

            // Is there even a person with that name? (if not, skip procedure)
            if(victim == nullptr) continue;

            // Remove the specified person
            magnusArchives.RemoveEntry(victim);
        }
        else if(input == "printall")
            magnusArchives.Print();
        else if(input == "clear")
            magnusArchives.PlagueOfDeath();
        else if(input == "test")
            Test(magnusArchives);
    }
}

void Program::Test(PersonRegister personRegister)
{
    string name = "Willy";
    string address = "Willstreet";
    string victimName = "RemoveMe";
    string victimAddress = victimName;
    Person dummy(name, address);
    Person victim(victimName, victimAddress);

    // search for nonexistent person
    cout << "Searching for " << name << "..." << endl;
    personRegister.SearchByName(name);

    // add person
    cout << "Adding " << name << ", " << address << " to the register..." << endl;
    personRegister.AddToRegister(&dummy);
    cout << "Adding " << victimName << ", " << victimAddress << " to the register..." << endl;
    personRegister.AddToRegister(victim);
    personRegister.Print();

    // search for existent person
    cout << "Searching for " << name << "..." << endl;
    personRegister.SearchByName(name);

    // remove existing person
    cout << "Removing " << name << " from the register..." << endl;
    personRegister.RemoveEntry(&dummy);
    personRegister.Print();
    // remove existing person via SearchByName
    cout << "Removing " << victimName << " from the register...";
    personRegister.RemoveEntry(personRegister.SearchByName(victimName));
    personRegister.Print();

    // remove non-existent person // this doesn't work like this:
    // cout << "Removing " << name << " from the register... (again)" << endl;
    // personRegister.RemoveEntry(&dummy);
    // personRegister.Print();
    // remove non-existent person via SearchByName
    cout << "Removing " << victimName << " from the register... (again)";
    personRegister.RemoveEntry(personRegister.SearchByName(victimName));
    personRegister.Print();

    // clear register
    cout << "Clearing register..." << endl;
    personRegister.PlagueOfDeath();
    personRegister.Print();
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