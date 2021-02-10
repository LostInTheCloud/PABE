# In-memory decryption II 

Have a look at the `extractme` executable. It decrypts a flag during runtime. Please try to extract it again.

The flag is in the format `FLAG{some characters here}`. Write a (vanilla not pwndbg) GDB Python script that extracts the flag.

Your solution should look like:

```shell
$ ./solution
FLAG{some characters here}
```

Hints:
- Try to find the flag with *pwndbg* first an then write the script.
- At *no* point in time, the flag is completely decrypted.
