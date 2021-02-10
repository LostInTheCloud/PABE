# C++ and vtables

In this task you have to exploit a vulnerability that leads to a vtable pointer overwrite. Although it is also possible to overwrite the return address of `main()` you **must not** use this approach.

What you should do:
1. find the bug(s)
2. understand how vtables work in C++ (e.g., https://en.wikipedia.org/wiki/Virtual_method_table, https://godbolt.org/z/les9Bx)
3. exploit the bug to get the flag from `flag.txt` by manipulating the vtable (pointer)

Once againe, edit the provided `solution` template and explain your approach with meaningful comments!

The output should look like:

```shell
$ ./solution
FLAG{...}
```

Hints:
- are there any useful functions in the binary?
- how can you manipulate the control flow without overwriting the return address?
