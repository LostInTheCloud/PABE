# In-memory decryption

Have a look at the binary `xor`. When you run the binary it seems that nothing happens... If you have a look at the disassembly (e.g. with `objdump` or any other disassembler) you can see that there is a string within the binary that gets decrypted during runtime. The decrypted string only exists during the execution but will not be printed to `stdout`.

Your task is to write a gdb script in Python [(link)](https://sourceware.org/gdb/current/onlinedocs/gdb/Python-API.html#Python-API) that sets a breakpoint at the correct address (when the string is finally decrypted), runs the program and outputs the string to `stdout`. This time your `solution` can be a Bash script that calls gdb with the Python script as an argument (`gdb --command=<your Python script>`) . Make sure that only the decrypted string is printed to the final `stdout` (e.g., Bash's `stdout`).

Your solution could, for example, look like:

```shell
$ ./solution
abcdefg
```

