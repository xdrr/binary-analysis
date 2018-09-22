#include <iostream>
#include "stdlib.h"

class Foo
{
    public:
        std::string name;
        int doStuff();
};

int Foo::doStuff()
{
    int i;
    i++;
    i+=1;
    i+=12;
    i -= 3;
    return i;
}

int main(int argc, char *argv[])
{
    // Allocate a `new' Foo object on the heap
    Foo *pFoo;
    int result;

    pFoo = new Foo();
    pFoo->name = "Testing";

    fprintf(stdout, "The value of the new foo object is: %s\n", pFoo->name.c_str());

    result = pFoo->doStuff();

    return 0;
}
