#include <iostream>
#include "stdlib.h"

class Foo
{
    public:
        int doStuff(void);
        std::string name;
        // Constructor has same name
        Foo()
        {
            std::cout << "Calling the constructor!" << std::endl;
        }
        ~Foo()
        {
            std::cout << "Calling the destructor!" << std::endl;
        }
};

int Foo::doStuff(void)
{
    int i;
    i = 1;
    i++;
    i += 10;
    return i;
}

int main(int argc, char *argv[])
{
    Foo foo;
    int result;
    foo.name = "Testing";

    fprintf(stdout, "The value of the name element in the foo object is: %s\n", foo.name.c_str());

    std::cout << "Calling the doStuff() function!" << std::endl;

    result = foo.doStuff();

    fprintf(stdout, "The result was: %d\n", result);

    return 0;
}
