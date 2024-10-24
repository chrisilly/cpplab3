# Feedback

First of all, when you hand these assignments out next year, please for the love of god do not hand out files or example code with `åäö` because it doesn't load right—and even if it does, it is absolutely horrendous. This pisses me off 😩 (In my case, I had to replace every instance of `åäö` in the `PersonExempel.txt` because they all showed up as the `�` replacement character. I'm just glad the example data wasn't hundreds of lines long 🙂 *Might* have to do with my using **VS Code** as opposed to **VS22**.)

Also—considering the nature of `c++`—it would make so much sense if we were always given header files to accompany the list of requirements. This is a practical way of outlining the requirements and expected structure and implementation of the programs.

# Assignment 1

I don't know why my header files don't recognize `string` even though I have `using namespace std` :( Update: `#include <iostream>` (or `#include <string>`) fixed it—which is a bit weird though because I hadn't needed it in my other assignment.

Apparently you need the `public:` line in the `.cpp` file also. It's strange because no problems are detected within the `.cpp` file if you don't put the methods defined in the header under `public:` in the `.cpp` file, but it *does* complain when you try to use the methods in a different class or `.cpp` file.

Okay so apparently naming my `int` variable `max` *also* makes it ambiguous? Note to self, don't name your variables `size` or `max`. Ugh.

Ran into fat problems: `'class' type redefinition`. (Time to learn about include guards.) Update: I feel more strongly by the minute that we have not had proper lecturing about code structure when it comes specifically to working in many different files. Obviously we have guards such as `#ifndef` and more, but good lord am I desperate for some examples of multi-file programs right about now and I really cannot find any on Canvas.

Okay. **The problem:** I used `#include Person.h` in `PersonRegister.h` file, and then used both `#include Person.h` *and* `#include PersonRegister.h` in my `PersonRegister.cpp` file. I learned that this leads to duplicate declaration, and the compiler doesn't know what to do with that. **The Solution:** wrap the *header* file contents with `#ifndef ... #define ... #endif`. Nothing else. Done. That way, when you `#include` something that a header file has already included, the compiler will chill about it. This shit is not obvious when you don't understand how the compiler is working in the background. We *were* taught about how the compiler works, but with a *severe* lack of example code, so I don't think it's strange at all that I now do not know how to apply the knowledge gained from that lecture. I also learned that it's totally possible to `#include` `.cpp` files but that you absolutely shouldn't!

https://www.learncpp.com/cpp-tutorial/header-files/
https://www.learncpp.com/cpp-tutorial/header-guards/

New problem: My header files are complaining about the use of `string`, but in my quest to understand headers and guards, I've learned that using `using namespace ...` in a header is really bad and dumb and illegal. I have used `#include <string>` in my header files, but they still complain!

Unless my research betray me, the best way to address this is to prefix the `string`s with `std::`. It is also possible to `using std::string`, but the former is supposedly better practice[^1].

No more errors! But my code doesn't compile! 🤠 End me!

```obj
main.obj : error LNK2019: unresolved external symbol "public: __thiscall Person::Person(void)" (??0Person@@QAE@XZ) referenced in function _main
main.obj : error LNK2019: unresolved external symbol "public: void __thiscall Person::Print(void)" (?Print@Person@@QAEXXZ) referenced in function _main
```

Does it not recognize the `Person` class? It *does* have `#include person.h`... I *have* defined the constructor and `Print` method in my `person.cpp` file...

... I think. My launch settings in VSC do not account for the existence of several `.cpp` files. I am so hungry. And so upset. Trying to make a CMAKE build now. But it's also not compiling and I don't know why.

Okay I even tried compiling via command line `cl /EHsc main.cpp person.cpp personregister.cpp` and it gives me the same shit. What the fuck?
```
F:\repos\cpplab3>cl /EHsc main.cpp person.cpp personregister.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.38.33130 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

main.cpp
person.cpp
personregister.cpp
Generating Code...
Microsoft (R) Incremental Linker Version 14.38.33130.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj
person.obj
personregister.obj
main.obj : error LNK2019: unresolved external symbol "public: __thiscall Person::Person(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (??0Person@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z) referenced in function _main
main.obj : error LNK2019: unresolved external symbol "public: void __thiscall Person::Print(void)" (?Print@Person@@QAEXXZ) referenced in function _main
main.exe : fatal error LNK1120: 2 unresolved externals
```

Only when I put the `Person` class code above the `main` function in `main.cpp` did the program run as expected. I tried compiling and linking separately, but I get the same error when I try the linking. I just don't get why it can't find the implementations defined in the `person.cpp` file???

I am literally fucking browsing random ass c++ repositories on github because I am so fucking lost and googling gives me like nothing. I need to see what a fucking c++ project looks like in the real fucking world thanks for nothing y'all.

Defining `Person` class methods in `main.cpp` using the `Person::` prefix works just fine. When I remove the constructors from the `person.h` file, I can make `Person` objects just fine in main. I'm concluding that my project is just not seeing or is ignoring all implementations in `person.cpp` even though I'm explicitly adding it as an argument when compiling (using `cl.exe`).

It seems I have gravely misunderstood how to implement class content. You apparently do not put `class Person {...}` in a `.cpp` file. You just make sure to
1. `#include header.h`
2. implement each method and constructor by just doing it, except with the `MyClass::` prefix.

So simple. And yet I spent so, so many hours trying to fix this. Fuck this. Actually had me tearing my head off.

https://stackoverflow.com/questions/10589355/error-c2061-syntax-error-identifier-string
https://stackoverflow.com/questions/6995572/using-multiple-cpp-files-in-c-program

[naming and other conventions by google](https://google.github.io/styleguide/cppguide.html)

more naming conventions: https://www.geeksforgeeks.org/naming-convention-in-c/

### 14 October

The following syntax (given in the handout) was confusing: `bool LäggTill(const Person* const)`

A teacher not affiliated with the course explained that an argument name should follow, and ideally should always be detailed in the `.h` file. I.e. it should have looked like this when you handed it out to us: `bool AddToRegister(const Person* const person)`

[CJ's image](https://discord.com/channels/1053434127979909151/1053457479733882972/1293265408517869671) explained very clearly that the argument in this method is a `const pointer` pointing to `const Person`[^2]. Thank you CJ 🙏

CJ also writes:
> Detta är rörigt även för mig, och jag tycker uppgiften borde ha haft bara const Person*. Pekaren i sig själv behöver inte vara const.[^3]

So I'm going to just modify this method to my liking.

In any case, I can't set `persons[personCount++] = person;` because the operand `persons[personCount]` is a `Person` whereas `person` is a `const Person*`. I don't know wtf y'all expect from me.

I have had too much friction and trouble just trying to use basic operators that do not work because I do not understand the structure of c++ and the nature of pointers and how y'all want me to work with them. This assignment can suck my ass.

How come `new Person(*person)`, where `person` is a `const Person *`, is a pointer and not a `Person` when I'm literally calling the `Person` constructor? Hm?? Please explain.

This assignment is gonna make me cry.

I rapid-fired some attempts to solve the "operands are different" error. Changing the syntax from `persons[i]` to `*persons` (Again, using dereferencing) allowed me to assign it to a dereferenced version of the input argument. At first I got an access violation error though, which some stackoverflow nerd said was because the array content was uninitialized so I changed the line to `*new Person(*person)`—a dereferenced copy of the dereferenced method argument. It worked, so I'm keeping it 🙂

### 15 October

Actually, it didn't work. Still getting access violation error. End me.

Okay, I tried making a `Person *persons` array with a pre-determined list of `Person`s, and I still get the access violation. Not sure why.

Aha. I changed the following:
```cpp
for (Person *pointer = persons; pointer != persons+size; ++pointer)
        pointer->Print();
```
to this:
```cpp
for (Person *pointer = persons; pointer < persons+size; ++pointer)
        pointer->Print();
```

The former block was code handed out from the teacher via the assignment's Canvas page. Whereas it did not work before, now it does 🙂 Do you understand how frustrating it is when code and examples provided to us—whether they are literal *requirements* or exampes meant to *aid* us—do not work? **Please forgive me for assuming that they would in fact work and stand as decent examples of best practice and solid code.** 

Whoever wrote this assignment, never write another assignment in your life again please.

Making the `AddToRegister` method take a `const Person` as opposed to a `const Person* const` makes `persons[++personCount] = person;` work *just* fine. Am I allowed to do this? Why the fuck is it made the other way to begin with, it seems dumb as hell Jesus Christ.

### 17 October

In what way is the `RemoveEntry()` method supposed to remove an entry? Wipe the name and address? That's what I'm going to assume.

Today I learned that you can access a class's private variables if it looks like `Person PersonRegister::SearchByName(const string name)` but *not* if it looks like `Person PersonRegister::*SearchByName(const string name)`. I think the only difference is that the latter method returns a pointer instead of a `Person` object? I don't get why suddenly it loses access though. Either it's a syntax mistake or it's some wonky ass c++ stuff.

Nevermind, it's supposed to be `Person* PersonRegister::SearchByName(const string &name)`. I tried this but while missing the `&` operator in the parameter, which is why it didn't work at first.

So, in order to search by name, I need to compare a string to the `Person` object name. The `SearchByName()` method is in the `PersonRegister` class, though, so in order to compare them I introduced a `std::string GetName() {return name}` getter method in the `Person` class. However, in my pointer for-loop, `pointer->GetName()` doesn't seem to return a defined value?

When adding the line `cout << "current pointer->getName(): " << pointer->getName() << endl;`, nothing is printed at all, even though the break point stops on the line—so it *is* being run. Weird! And when using `watch` in VS Code, it at least seems like `pointer` does iterate through and its `name` *does* change.

I asked for help on [Discord](https://discord.com/channels/1053434127979909151/1053457479733882972/1296434723027157063) (correct decision—I have adapted) and got some insight as to what tests I can run to find the problem. The problem seems to be due to the way `cin` works—or the way I handle it—when getting the parameter (string) values from the user.

When testing the method using hard-coded strings, it worked just fine. Replacing my `cin >> input`s with `getline(cin, input)`s solved my problem. `getline` removes the newline character from the input before saving it to your variable I've now learned, which I assume must have been the issue.

### 20 October
When searching for a name that doesn't exist (using `SearchByName()`), I get a read access violation error. `nullptr` is being returned. I added safeguard code, but I *sometimes* get `read access violation` when I do `PersonRegister::PlagueOfDeath()` (which is my function that clears the register)? It seems to throw the exception on the *second* clear. Nope. It's always at the end of running the `Test()` method a second time.

> The (major) advantage of using references is that you don't have to worry about pointer safety, i.e. whether or not your pointer is pointing to valid memory.[^4]

In reference to using pointers as input parameters instead of references. Why are you making us do this. Continuation:

> The (slight) advantage of using pointers is that within the body of your function, it's immediately obvious that you're using a pointer and that any changes you make to the value of the memory it points to will be present in the calling code. With references, you can only tell whether you're using a reference or a local copy by looking at the function declaration to see if there's an & symbol.
>
> I won't go into a full tutorial on references; if you're learning C++, then you presumably already have access to reference material.
>
> Regarding your second question, I've usually seen it used in situations where your function has to conform to a particular interface, but a specific implementation doesn't actually use the argument that the interface required to be passed in. If you don't specify a name for the argument in your function implementation, then it makes it clear to anybody else reading the code that it won't be used in your function.
>
> It will also stop the compiler warning you about unused arguments. Getting rid of compiler warnings is a good thing, because it makes it easier to spot any new warnings you introduce that indicate a genuine problem with your code.

I'm reading all this because when I pass a `Person dummy` object into my `PersonRegister::RemoveEntry(Person* person)` with the syntax `RemoveEntry(&dummy)`, it doesn't actually change the `dummy` object. This is the same issue I had with the `AddToRegister(Person* person)` method before I changed it to `AddToRegister(const Person person)`. 

Reading up on the C++ core guidelines, though, it probably should look like: `AddToRegister(const Person& person)`, because passing `Person` objects by value might get expensive compared to passing them by reference to const[^5]. I can find *nothing* on passing pointers as parameters.

It also says in general that instead of using `char*` or `const char*` to represent strings, you should use `zstring` or `czstring` in order to clarify intent[^6].

I'm so tired. I don't know what is expected of me. This assignment has me so defeated.

### 21 October

Small stuff like needing to put `Person** pointers` in parentheses when dereferencing like so:
```cpp
(*pointers)->Print()
```
How am I supposed to know that? Nobody ever showed examples for this.

### 24 October

I think the whole `size` variable name being ambiguous might have to do with it already being a variable in the `std` namespace and that I'm `using namespace std`. The realization came after reading through c++ tutorial pages[^7].
> Avoid using-directives (such as using namespace std;) at the top of your program or in header files. They violate the reason why namespaces were added in the first place.

I just learned that I've been doing constructors wrong when I tried implementing inheritance!

Instead of the following implementation in my `.cpp` file:

```cpp
Person::Person(string name, string address)
{
        this->name = name;
        this->address = address;
}
```
I should be implementing it like this:

```cpp
Person::Person(string name, string address) : name{name}, address{address} 
{
        // additional code can go here
}
```

All the while the header file remains unchanged:

```cpp
class Person
{
        // stuff goes here...
public:
        Person(std::string name, std::string address);

        // etc...
}
```

And when you want to make a child class that builds on the Base constructor, you just call the Base constructor similarly, like so[^8]:

```cpp
PersonWithPhoneNumber::PersonWithPhoneNumber(string name, string address, string phoneNumber) : Person{name, address}, phoneNumber{phoneNumber}
{
    // additional code can go here
}
```
This is different from how I did things in c#!
```cs
class Person
{
        Person(string name, string address)
        {
                this.name = name;
                this.address = address;
        }
}
```

<!--  -->

[^1]: https://stackoverflow.com/questions/10589355/error-c2061-syntax-error-identifier-string
[^2]: https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const/31331389#31331389
[^3]: https://discord.com/channels/1053434127979909151/1053457479733882972/1293266692285136988
[^4]: https://cplusplus.com/forum/general/89373/#msg480130
[^5]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f15-prefer-simple-and-conventional-ways-of-passing-information
[^6]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slstr3-use-zstring-or-czstring-to-refer-to-a-c-style-zero-terminated-sequence-of-characters
[^7]: https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/
[^8]: https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/