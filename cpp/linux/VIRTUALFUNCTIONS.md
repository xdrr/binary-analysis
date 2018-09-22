# Virtual functions

 * By definition a virtual function is one a member function overloaded in a derrived class.
 * The manner in which polymorphism is achieved seems to be situation and compiler specific.
    * For example, a class Bar derrived from class Foo with the same function and different implementations might be compiled as two functions in the code section. While forcing the `virtual` keyword forces them to be accessed using a virtual function table. Other compilers may have a different outcome in the same situation.
  * A key characteristic of the virtual function calling convention is:

  ```asm
  mov rax, [pointer_to_object]          ; get pointer to object
  mov rax, [rax]                        ; dereference pointer
  mov rax, [rax]                        ; dereference first vfptr in table (first method)
  mov rdx, [pointer to object]          ; setup ptr to object in args per calling conv
  mov rdi, rdx                          ; get that ptr into rdi (first arg)
  call rax                              ; call obtained virtual function addr
  ```

  * When the virtual function is not the first in the table, an offset is used like this:

  ```asm
  mov rax, [pointer_to_object]  ; get pointer to object
  mov rax, [rax]                ; dereference pointer to get first element (vf table)
  add rax, 8                    ; get nth element in table in units of sizeof(void *)
  mov rax, [rax]                ; dereference that element to get addr of function
  mov rdx, [pointer_to_object]  ; setup ptr to object into args
  mov rdi, rdx
  call rax                      ; call obtained virtual function function addr
  ```

   * It can be seen that the virtual function table is always placed as the first element in the object when initialised.
