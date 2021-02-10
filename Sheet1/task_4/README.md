# Parse process information

There are some processes on your virtual machine utilizing the _seccomp_ feature [(link)](http://man7.org/linux/man-pages/man2/seccomp.2.html). Use the _proc filesystem_ to identify processes utilizing seccomp and count them. Write a Python 3 script that prints the final count to `stdout`. 

Your solution could, for example, look like:

```shell
$ ./solution
5
```

