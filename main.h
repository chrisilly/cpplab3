#ifndef MAIN_H
#define MAIN_H

#include "PersonRegister.h"

void AddPersonTest(PersonRegister &personRegister);
void RemovePersonTest(PersonRegister &personRegister);
void SearchByNameTest(PersonRegister &personRegister);
void SearchByAnyTest(PersonRegister &personRegister);
void EmptyRegisterTest(PersonRegister &personRegister);

bool ReadRegister(PersonRegister &personRegister, std::string fileName);

#endif