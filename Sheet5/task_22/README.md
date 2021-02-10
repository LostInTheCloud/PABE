# Heap Visualization

Write a **GDB script** that visualizes parts of the heap.
No **pwntools** required for this task. Once again, edit the provided `solution` template and explain your approach with meaningful comments!
This solution file expect a **gdb_heap_vis.py** file which is your **GDB script**.
In more detail, in GDB you can use libc's debugging symbols to get information about the main_arena like this:

```
(gdb) p main_arena 
$1 = {
  mutex = 0, 
  flags = 0, 
  have_fastchunks = 0, 
  fastbinsY = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, 
  top = 0x0, 
  last_remainder = 0x0, 
  bins = {0x0 <repeats 254 times>}, 
  binmap = {0, 0, 0, 0}, 
  next = 0x7ffff7facc40 <main_arena>, 
  next_free = 0x0, 
  attached_threads = 1, 
  system_mem = 0, 
  max_system_mem = 0
}
```

There you can see the `fastbinsY`, `bins`, the `top` chunk and so on. Implement a `gdb.Command` (https://sourceware.org/gdb/onlinedocs/gdb/Commands-In-Python.html#Commands-In-Python) that can be used with `freeheapchunks` in GDB and shows all free chunks (fast bin, small bin, unsorted bin, large bin chunks) like this:

```
free fast bin chunks:

prev_size = ???, 
size = ???,
fd = ??? 
bk = ???
fd_nextsize = ??? 
bk_nextsize = ???
data = ??? 

...snip...more chunks here...

free small bin chunks:

prev_size = ???, 
size = ???,
fd = ??? 
bk = ???
fd_nextsize = ??? 
bk_nextsize = ???
data = ??? 

...snip...more chunks here...

free large bin chunks:

prev_size = ???, 
size = ???,
fd = ??? 
bk = ???
fd_nextsize = ??? 
bk_nextsize = ???
data = ??? 

...snip...more chunks here...

free unsorted bin chunks:

prev_size = ???, 
size = ???,
fd = ??? 
bk = ???
fd_nextsize = ??? 
bk_nextsize = ???
data = ??? 
...snip...more chunks here...
```

The `???` should contain the correct values preferably in hexadecimal notation. Also note: First, some of the values make no sense for specific chunk types (e.g., fastbins do not have a `bk` pointer) so set them to `n/a` for not available. Second, some bins hold linked lists with specific sizes (e.g., chunks of size 0x20, 0x30, ...), so print **all** the free chunks in **every** bin of **any** size. The `data` field (which is not part of a libc heap chunk) should give a "preview" of the data that is still inside the chunk's `malloc()`ed memory even if the chunk has been `free()`d by the user. If the data is printable print it if not render a dot (.) like in `xxd`.

Please use the code in `malloc_and_free.c` as a reference and invoke your custom command `freeheapchunks` at the lines where the comments tell you to do so (set the breakpoints accordingly). Also use the provided binary `malloc_and_free`. Here is a snippet of the code:

```c
// snip

int main(int argc, char **argv)
{
	srand(time(NULL));

	noise();

	// invoke your command here

	char *string_1 = (char *)safe_malloc(32);
	strcpy(string_1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	char *string_2 = (char *)safe_malloc(32);
	strcpy(string_2, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	char *string_3 = (char *)safe_malloc(128);
	strcpy(string_3, "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	char *string_4 = (char *)safe_malloc(256);
	strcpy(string_4, "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	char *string_5 = (char *)safe_malloc(512);
	strcpy(string_5, "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
	char *string_6 = (char *)safe_malloc(4096);
	strcpy(string_6, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
	
	// invoke your command here
	
	free(string_1);
	free(string_2);

	// invoke your command here
	
	free(string_3);
	free(string_4);
	free(string_5);
	
	// invoke your command here
	
	free(string_6);

	// invoke you command here
	
	return 0;
}
// snip
```

Use pure GDB **not pwndbg** to solve this task! You can **ignore** the **tcache** bins!
