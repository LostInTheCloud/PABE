# The semantic gap

We found raw data and know its structure, but our programmer is ill and we need you to parse it. You can find the raw binary data in `data.bin`.

- First, there is an unsigned 2 byte integer in Big Endian format
- Then, there are two 1 byte integers in Little Endian format
- Then, there is a big 8 byte integer in Big Endian format
- At the end, there is an ASCII representation of a hexadecimal integer

Write a Python 3 script, which parses these integers and writes their sum (arithmetic addition) to stdout!

Your solution could, for example, look like this:

```shell
$ ./solution
12983728982379
```
