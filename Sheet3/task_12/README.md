# Function Tracer

To make you even more familiar with GDB (you'll need it for the upcoming exploitation exercises a lot!) here is another task to be solved with a GDB Python script [(link)](https://sourceware.org/gdb/onlinedocs/gdb/Python-API.html#Python-API).

Your task is to program a **function call tracer** for the `traceme` binary that outputs the name of all functions visited during the execution of the program. Start the tracing at `_start` and let the program run until it finishes.

Write the trace to a file first and then print the content of the file to `stdout`, thus you avoid having all the verbose output of GDB in your output.

Your solution could look like:

```shell
$ ./solution
_start
__libc_start_main
get_common_indeces.constprop.1
generic_start_main
_dl_aux_init
_dl_discover_osversion
uname
__pthread_initialize_minimal
sbrk
brk
brk
memcpy
__libc_init_first
__libc_init_secure
_dl_non_dynamic_init
_dl_get_origin
malloc
ptmalloc_init.part.5
_int_malloc
malloc_consolidate
sysmalloc
...
```

Hints:

- If a function has a name in GDB it is displayed in an angle brackets `call   0x40fa90 <puts>`.
- How can you make GDB stop at every `call` instruction?
- Also: make sure you respect the execution timeout (see General Information above)
