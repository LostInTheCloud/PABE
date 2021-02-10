# Simple Buffer Overflow

Have a look at the `simple_bo` file. You have to find out how the binary works and how you can make it print the flag. Please do not just brute-force possible solutions. This might lead to a reduced number of points for the task (see General Information). 

Your concrete task is to:

- reverse the binary and understand how it may be exploited so that it prints the flag

- write a Python script that exploits the binary

- describe your approach using a docstring at the top of the file (below the Shebang line!); we want to know what is happening **exactly** and why the flag is printed... describe the mechanisms!

  - just an example:

    ```python
    #!/usr/bin/env python3
    
    """
    The binary does foo and bar. We have to check that x, y, and z are true.
    After we did ... we use ... to make the program print the flag.
    """
    
    def main():
        pass
    
    ...
    ```

Your solution should look like:

```
$ ./solution
FLAG{some letters and/or digits here}
```



