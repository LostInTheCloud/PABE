# Broken C Code

Have a look at the C code in `broken.c`!
We know that there are some programming mistakes: *semantically* **and** *syntactically.*
Fix all the bugs so that the `gcc` compiler on your VM has nothing more to complain about (address warnings **and** errors)
and you know that the program is working semantically correct (e.g., the wrong input should not tell you the secret).

`gcc` must be called with no parameters except the input file and the output file.

Your `solution` script must be a Python 3 script.

It has to:
- compile the fixed source code
- execute the compiled program with the correct input so that the check is passed and you receive the secret
- print the secret

Use the `subprocess` module [(link)](https://docs.python.org/3/library/subprocess.html) and interact via `stdin` and `stdout` with the program if necessary.

Your solution could look like:

```shell
./solution
<THE SECRET>  # i.e. just print the secret that is surrounded by single quotes
```
