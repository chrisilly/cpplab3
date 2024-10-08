#include "personregister.h"
#include "person.h"
#include <iostream>

using namespace std;

int maxSize = 10;
string testName = "Chell";
string testAddress = "Aperture";

int main()
{
    Person person(testName, testAddress);
    person.Print();

    PersonRegister magnusArchives(maxSize);
    magnusArchives.Print();
}