#include <iostream>
#include "stdlib.h";

using std::string;
using std::cout;
using std::endl;

class Foo
{
public:
	string name;
	Foo() {
		cout << "Initializing..." << endl;
	}
};

int main(int argc, char *argv[])
{
	Foo *pFoo = new Foo;
	pFoo->name = "Testing";

	fprintf(stdout, "The value of the foo object name is: %s\n", pFoo->name.c_str());

	return 0;
}
