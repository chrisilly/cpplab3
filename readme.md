# Purpose

The purpose of this assignment is to design a person register, with a limited size and capacity, that keeps track of person objects.

# Person

`Person`s all contain a `name` and an `address`. They can be printed.

They also overload the `<` operator so that we can sort them alphabetically by name, but this functionality belongs to [assignment 4](https://github.com/chrisilly/cpplab4).

# PersonRegister

`PersonRegister` is a register which contains and manages persons (`Person* persons`). 

As per assignment requirements, persons are added and removed from the register by passing pointers of the persons as parameters to `AddToRegister` and `RemoveFromRegister`; We add and remove persons by passing them *by address* to the `PersonRegister` functions.

Other features include:
- Search for person by name
- Search for person by any data (freesearch)
- Print `persons`
- Empty register