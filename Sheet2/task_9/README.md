# Broken Code

Oh no again! Another binary also called `broken` is not printing the flag. I think the evil wizard of three-mistakes has corrupted it. Can you help us? Before this incident the binary printed a flag and exited with return code 42!

Your task is to write a Python script that patches the binary `broken` so that it runs as expected.

Your solution could, for example, look like:

```shell
$ ./solution
FLAG{some letters and digits here}
```

Hints:
- The broken code can be found in the function `_start`.
- You can use the `pwntools` command line tool `asm` to get the opcodes for a specific assembler instruction:
	```shell
	$ asm "mov eax, 0x1"
	b801000000
	```
