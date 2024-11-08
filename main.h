#ifndef MAIN_H
#define MAIN_H

#include "PersonRegister.h"

void RemovePersonTest(PersonRegister personRegister);

namespace Program
{

bool ReadRegister(PersonRegister &personRegister, std::string fileName);
void Test(PersonRegister personRegister);

}

#endif