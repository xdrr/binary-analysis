# Heap Classes Windows C++

 * The traditional model for allocation of class data is 'circumstantial' however there are still some obvious cases
   * Creating an object with the `new` keyword almost always forces heap allocation for the class data.
   * The compilation pattern for VC++ v141 (SDK 10.0.17134) appears to create a subroutine for execution of the `new` keyword. This subroutine handles calls to `j_malloc` based on the required size of the object and `callnewh` (accessed through `j__callnew`)
 * The class constructor is call immediately following allocation
