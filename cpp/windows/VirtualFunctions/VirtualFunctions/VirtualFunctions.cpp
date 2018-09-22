#include <iostream>
#include "stdlib.h"

using std::cout;
using std::endl;

class Foo
{
public:
	virtual int doStuff() const;
};

class Bar
{
public:
	virtual int doStuff() const;
};

int Foo::doStuff() const
{
	cout << "Foo's doStuff() does one thing" << endl;
	return 0;
}

int Bar::doStuff() const
{
	cout << "While Bar's doStuff() does another" << endl;
	return 0;
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