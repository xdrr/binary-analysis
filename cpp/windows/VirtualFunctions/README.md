# Virtual Functions C++ on Windows

 * The language-specific concepts remain the same between operating systems and compilers, however the implementation will differ.
 * Firstly Windows C++ binaries are immensely more complex and unobvious to trace.
 * Knowing how various C++ standard library operators, functions and automatic compiler inclusions will appear in the binary can help to better trace and identify subroutines containing programmer code, i.e. look for uses of `cout@std`.
 * Without the `virtual` keyword, overloaded functions from an inheriting class are split into thunks that contain a `jmp` to the class method.
 * However with the `virtual` keyword, a virtual function table is created in the binary's `.rdata` section with the name `const Foo::\`vftable'`.
 * It also appears that the RTTI information is stored below the constant class data. Above is the constant class data for each class, containing the `vftable` and other constant data like strings etc.
 * Finding the static class data in the `.rdata` section could be useful for identifying uses of class data in subroutines.
 * It would seem there's a strong relationship between the `virtual` keyword and msbuild/cl complilation with a virtual function table. Even in cases where the inheriting class does not specify the `virtual` keyword it will be compiled with a direct call.


## Use of vftables

 * When a function is called from a virtual function table it typically occurs like this:
   * A separate subroutine takes an argument and loads the virtual function table into that argument

   ```c
    void
    loadVftable(void *where)
    {
        void *vftable = 0x12345678;
        *where = vftable;
    }
    ```
    * The ptr to the vftable is then stored in a local function variable
    * Other code may be executed
    * To execute the call:
        * The ptr to the vftable is loaded into `rax`
        * The ptr is dereferenced
        * Arguments are setup such as placing the ptr to `this` in `rcx` per calling conv
        * A call is made to `rax`

    * In summary the pseudo-asm would be (and notably similar to Linux):
    
    ```asm
    call load_vftable
    mov [rbp+local_var_for_vftable]
    ...
    mov rax, [rbp+local_var_for_vftable]
    mov rax, [rax]                          ; an addition might occur here for offset funcs
    mov rcx, [rbp+ptr_to_object_this]
    call qword ptr [rax]
    ```

 * The obvious signature for usage of vftables would be `call qword ptr [rax]` (sizing specific).
 * Useful searches may therefore be:
  * `call qword ptr [rax]` = `ff10` (litte endian for Ida)


   

