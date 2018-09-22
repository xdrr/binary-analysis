#include <iostream>
#include "stdlib.h"

using std::string;
using std::cout;
using std::endl;

class Foo
{
    public:
        string name;
        virtual void stats();
        int whatsHappening();
        virtual int doStuff() const;
};

class Bar : public Foo
{
    public:
        string status;
        void stats();
        int doStuff() const;
        void doNothing();
};

int Foo::doStuff() const
{
    cout << "Foo's doStuff() does some stuff" << endl;
    return 0;
}

int Bar::doStuff() const
{
    cout << "While Bar's doStuff() does other stuff" << endl;
    return 0;
}

void Foo::stats()
{
    cout << "Does nothing at all" << endl;
}

void Bar::stats()
{
    cout << "Well then..." << endl;
}

int Foo::whatsHappening()
{
    cout << "Nothing is happening" << endl;
    return 0;
}

void Bar::doNothing()
{
    cout << "OK then" << endl;
}

int main(int argc, char *argv[])
{
    Foo *pFoo;
    Bar *pBar;
    pFoo = new Foo;
    pBar = new Bar;

    pFoo->doStuff();
    pBar->doStuff();

    return 0;
}
