# Encrypted header

Help! All of our executables seem broken!
We have attached one for you as `fixme`.
All we got is a ransom letter, claiming our files were _encrypted_ utilizing _xor_ with an _unbeatable 8 bit key_ on their _header_?
Can you write us a script decrypting the binaries?

In more detail:

Write a Python 3 script named `solution` (with a shebang line at the top so that it can be run as `./solution`) that:
- decrypts the `fixme` file
- runs the fixed file and captures its output (e.g., with a function from `subprocess` [(link)](https://docs.python.org/3/library/subprocess.html))
- prints the captured output of `fixme` to its `stdout` again

The final execution of your `solution` script should look like this:

```shell
$ ./solution
FLAG{some letters and digits here}
```
