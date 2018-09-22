# Class objects allocated on heap

 * A guarenteed way to have a new object arrive in heap memory is to allocate
 such an object with the `new` operator in C++.
 * Context drives the 'automatic allocation' when an object is created in a function. Often this can be in stack memory.
 * When heap allocation occurs, a pointer to the heap memory is passed into the constructor rather than a pointer to stack memory where the object was created in a function.
 * Some types are automatically allocated and those allocation calls inserted by the compiler. An example of this being the `std::string` type (heap allocated string data).
 * However, even C++ objects with functions and allocated on the heap may not have anything to exploit. Functions for the class definition remain in the code section and are called with a pointer to `this`.
 * See `VIRTUALFUNCTIONS.md` for more on how virutal function construction by the compiler an expose an exploitable attack surface in memory.

