# Bad Characters And A Non-Executable Stack

## Task Description

Your task is to exploit a simple bug in `exploitme`. But there is a problem: not all characters of your shellcode can be used! Also the stack is not executable so you have to get around that as well. Your task is to:

1. write a file `shellcode.s` in assembler that uses the `open`, `read` and `write` system calls to print the content of `flag.txt` to stdout
2. create machine code of your `shellcode.s` file with
   1. `nasm` and copy out only the machine code (you cannot inject an ELF file) and `objcopy` magic **or**
   2. `asm` from pwntools
3. use the `mprotect` system call to make the input buffer executable again to run your shellcode
4. find out what the bad characters in your shellcode are (see next section)
5. to get rid of the bad characters you could use `msfvenom` [1] from Metasploit which is installed on your VMs **or** craft your shellcode by hand so that it does not contain any of those bad characters (please note: you can only use `msfvenom` on the shellcode... **not** the `mprotect` ROP chain!)
6. inject your bad-character-free payload into `exploitme` so that it will be executed and print the flag

Your input should look like this:

```
| open, read, write shellcode | .... | mprotect code that makes the input buffer executable again and jumps to the beginning of the input buffer |
```

## Finding Bad Characters

Use the `exploitme` binary and try to input data that contains all possible bytes:

```
\x00\x01\x02\x03\x04...\xfe\xff
```

Debug the program and see if the **complete** input ends up in the input buffer.

Spoiler alert: `\x00` terminates a string so nothing ends up in the input buffer.

So, remove that byte and try again with `\x01\x02\x03\x04...\xfe\xff`... maybe this time you see that all bytes up until `\x0a` (a newline character) end up in the buffer.
Again, remove that byte and continue with `\x01\x01\x02\x03\x04...\x09\x0b...\xfe\xff`. When you reach `\xff` you just collect all bytes that somehow destroyed your shellcode during the injection (e.g., `\x00, \x0a`).
Those bytes are your bad characters.

## Solution

Once again, edit the provided `solution` template and explain your approach with meaningful comments!
Your solution should look like this:

```shell
$ ./solution
FLAG{...}
```

As always, comment all of your code!
You don't have to automate the step of finding the bad characters... just describe what you did and upload your helper scripts if you created any.

[1] https://www.offensive-security.com/metasploit-unleashed/msfvenom/
