#ifndef MAIN_H
#define MAIN_H

#include "PersonRegister.h"

void AddPersonTest(PersonRegister &personRegister);
void RemovePersonTest(PersonRegister &personRegister);

bool ReadRegister(PersonRegister &personRegister, std::string fileName);

#endif