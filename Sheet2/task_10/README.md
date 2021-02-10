# Unicorn Engine

Unicorn Engine is a CPU emulator that supports many different architectures [(link)](http://www.unicorn-engine.org/docs/tutorial.html) CPU emulator means that you won't have any support from the operating system and have to work very low level. This is especially true for memory mapping.

We provided you a `solution` file with some Python code. When you run the code (i.e. `./solution`) you will notice that you get an error `ERROR: Invalid memory read (UC_ERR_READ_UNMAPPED)`.

Your task is to:

- understand the Python and assembly code
- find out why the error messages occur
- fix the Python code so that the emulation runs correctly

If I remember correctly the value `0x1337` was stored at the address `0x31337` (`mov eax, [0x31337]`)

With the code tracing hook in place `engine.hook_add(UC_HOOK_CODE, hook_code)`  you will also see the currently executed instruction via `stdout`.

Your final solution could, for example, look like:

```shell
$ ./solution
...
eax = 0x1234
ebx = 0x1234
ecx = 0x1234
edx = 0x1234
```

We will check the last 4 lines to see if the results are correct. **Do not modify the `simple_asm` code.**

Hints:

- How can you catch illegal memory accesses?
- Must the memory you map be aligned somehow?
