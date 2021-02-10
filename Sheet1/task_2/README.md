# Parse ELF files

We have found a strange symbol in one of our files.
Could you write a small Python 3 script scanning the symbols of the given ELF file `parseme` for the name _flag_ and return its _value_ in hex?

The value should be the same as printed by `readelf`:

```shell
$ readelf --symbols parseme | grep flag
     6: 00000000deadbeef     8 OBJECT  GLOBAL DEFAULT   24 flag
```

There are two sub tasks:

1. Write your own little ELF parser that allows you to get the desired value:
   1. You _do not_ want to write a complete parser for ELF in Python!
   2. You can assume that the file is 64 bit (cf. `parseme`)
   3. You will need to find/parse the string table as referenced by `.shstrtab` that, for example, contains the strings of the section names `.dynsym`, `.dynstr`, ... [(link)](http://refspecs.linuxbase.org/elf/gabi4+/ch4.strtab.html), [(link)](http://refspecs.linuxbase.org/elf/gabi4+/ch4.eheader.html)
   4. You will need to iterate over all section headers to find `.dynstr` and `.dynsym` [(link)](http://refspecs.linuxbase.org/elf/gabi4+/ch4.sheader.html)
   5. You will need to parse the dynamic symbols string table referenced by the section `.dynstr` (contains, for example, the string `flag`).
   6. You will need to parse the dynamic symbols table referenced by the section `.dynsym` [(link)](http://refspecs.linuxbase.org/elf/gabi4+/ch4.symtab.html)
      1. In the dynamic symbols table you will find a reference to the symbol name (`st_name`) and to the symbol value (`st_value`).
      2. If `st_name` references "flag" print the value `st_value`.
   7. Use Pythons `open`, `seek`, `read` methods as well as `struct.unpack` to get the correct values.
   8. Might also be helpful: [ELF - Wikipedia](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)

2. Use [pyelftools](https://github.com/eliben/pyelftools) as an alternative approach to solve this exercise.

Your solution could, for example, look like this:

```shell
./solution
00000000deadbeef  # this is the result of your own parser
00000000deadbeef  # this is the result of the pyelftools library
```
