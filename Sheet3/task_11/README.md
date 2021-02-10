# Key Checker II

The program `check_key` needs a valid key as an input. Find out how to provide the key to the program and how the key checking algorithm works (use a disassembler such as IDA Pro 7, radare2, binary ninja or use a debugger, such as gdb).
The final task is to write a Python script as `solution` that is able to generate *one* valid key and print it to `stdout`. This time you **must** use the `z3` Python module [(link)](https://github.com/Z3Prover/z3) [(link)](https://ericpony.github.io/z3py-tutorial/guide-examples.htm) to solve the constraints on the key.

Your solution could, for example, look like this:

```shell
./solution
thisisavalidkey
```

