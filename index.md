# PABE WS 2020/2021

## Practical Cheats

---

### Vulnerability Types

- Buffer Overflow (on stack and heap)
- Format String
- Use After Free
- ...

---
install stuff
```bash
sudo pacman -S gdb pwndbg python python-pwntools code git \
               ghidra nmap gcc lib32-gcc-libs lib32-glibc ropgadget
```
---
use **PWNDBG**
```bash
echo 'source /usr/share/pwndbg/gdbinit.py' >> ~/.gdbinit
```
run with args `run foo bar`  
cond. breakpoints `break *<addr> if $rax == 0x3`  
watchpoints `watch/rwatch/awatch *<addr>` (write/read/access)  
step over and step into `ni / si`  
examine memory `x /<n><size><fmt> <addr>` (n=number; size=h,w,d,g; fmt=**S**tring, he**X**, **I**nstruction)  
altering registers `set $rip = <addr>`  
get maps with `vmmap`  
seach function with `p system`  
search string with `find <start_addr>, <end_addr>, "/bin/sh"`  
time traveling:
 - enable recording `target record-full` 
 - reverse continue `rc`
 - reverse step over `rni`
 - backwards execution `set exec-direction reverse`  

fastbins: `fastbins`  
getting the GOT entries: `gotplt`  

---

use **PWNTOOLS**

Format String Exploit:
```python
from pwn import *

def exec_fmt(payload: str)->str:
    # wrapper that handles the io to the format string function

autofmt = FmtStr(exec_fmt)
offset = autofmt.offset
payload = fmtstr_payload(offset, {target_addr: target_data})
```

---

Websites:

- godbolt.org Online C to Assembly
- http://shell-storm.org/online/Online-Assembler-and-Disassembler/ Assembler and Disassembler
- https://www.rapidtables.com/convert/number/hex-dec-bin-converter.html Converter

---

See security measures of binary: `checksec ./a.out`  
See info about the ELF Header: `readelf -h a.out`  
Strip symbols and sections: `strip a.out`  
Tracing: `ltrace` or `strace`  
Fiding bugs: `valgrind` or compilation with `-fsanitize-address`  
Finding strings in binary: `strings a.out`
ROPGadgets: `ROPgadget --binary /usr/lib/libc-2.33.so | grep ": pop rax ; ret"`

---

Further Tools: 

- CVE-Checker FKIE
- Frida
- guyinatuxedo/remenissions
- tsunami
- Binary Ninja (to use API in Python)
---

## Theoretical Cheats
---
### Linux and System
---
| | | | |
:---:|:---:|:---:|:---:
Half Word | Word | Double Word | Quad Word
8bit | 16bit | 32bit | 64bit
char | short | int | long 

---
Stack alignment: 

<img src="docs/stackalignment.png" alt="drawing" width="200"/>

---
Seccomp:  
- in `cat /proc/<id>/status`  
- determines the syscalls the process can invoke

---
### ELF Files

ELF (Executable and Linkable Format) under UNIX
- ELF header:  magic byte 0x7f454c46 (0x7f, ELF)
- program headers
- section headers
- .text segment:  code
- .(ro)data segment:  (read only) data
- .dynstr / .dynsym segment
- .bss segment
- .got:  global offset table
- .plt:  (lazy) procedure linkage table
 
 ---

Segments vs Sections:
- Segment: info for the OS about permissions and where segment should be stored in memory
- Section: info for the linker

> **Sections** are **IN Segments**

 --- 
### Static Analysis (whiteboxing)

- parse the binary directly
- semantic gap
- we need dataflow analysis to track variables

Symbolic execution:

<img src="docs/symbolic_executionpng.png" alt="drawing" width="500"/>

---

Dissassembly:

- **Linear Sweep:** disassemble a stream of bytes into successive instructions
- **Recursive Traversal:** follow the control flow to disassemble

---

Calling Conventions

| name | arch | parametres | return | cleanup | perserves |
|:---: |:---: |:---:       |:---:   |:---:    |:---:      |
| **cdecl** | x86 gcc | push p_n ... push p_1 | eax | caller |all but eax, ecx, edx|
| **AMD64 ABI** | x64 gcc | rdi, rsi, rdx, rcx, r8, r9| rax | caller | all but eax, ecx, edx|
| **fastcall** | x86 Win | who | the | fuck | cares | 
| **MS x64 CC** | x64 Win | who | the | fuck | cares |

---

### Dynamic Analysis (blackboxing)

- fuzzing
- sandbox
- emulation
- debugging

---

### Vuln Research

> Bug != Vulnerability != Exploit

Target CIA: 
- Confidentiallity
- Integrity
- Availability

Scoping: choosing elements to analyse instead of the whole thing

Attack Surfaces:
- Arguments
- stdin
- env vars
- files
- network sockets
- signals / exceptions

C Language Issues:
- Unerflows/Overflows
- Truncations
- Stack Overflows
- Heap Overflows
- Out of Scope
- Out of Bounds
- Double Free
- Memory Leaks
- Type Promotion

---

### CVE vs CWE

- Common Vulnerabilities and Exposures: a weakness in a program

- Common Weakness Enumeration: an abstract list of types of weaknesses

### Dataflow analysis

Backwardslice: Trace a value to its origin.

### Intermediate Representation

- vex:

- reil: 

- llvm:

- esil: stack based represenation (used in radare)

- bil: 

- bnil: binary ninja intermediate language

- SSA: every variable only gets defined and assigned ONCE. When overwritten, SSA creates a new variable.

- SSA+PHI: if a variable depends on multiple others dependent on flow | `var_8#2 := PHI(var_8#0, var_8#1)`

- Taint Analysis: check where the variables 'come from', i.e. if `var_8#3` maybe was already checked as `var_8#2`

- Dominance Tree: A dominates B if every path to B stems from A

- Z3 to see if logic checks out

- value set analysis: not all input params produce the same flow. We can check if different possible paths are feasible or break logic, to reduce the amount of paths.

- can only have **two**

    - Termination
    - Soundness (all facts)
    - Completeness (only facts)

---

### Buffer overflows: 

- return to a function in the binary
- return to shellcode injected by pwner
    - shellcode needs to fit into buffer (?)
    - must be PIC
    - environment vars must be set if needed
    - NOP Sled
    - denullify: remove bad characters
        - mov eax, 0 -> xor eax, eax
        - mov eax, 5 -> movl al, 5
        - mov -> push/pop
    - obfuscating

> BEWARE bad characters, especially in shellcode

Beating stack canaries:

- bruteforce
- info leak
- overwrite master canary
- with static canaries or a fork:  
overwrite canary byte by byte and this way find out the whole canary

Beating NX:

- ret2libc

Beating NX on 64Bit:

- can't put params onto stack, instead, have to put them into registers
- ROP Chain to execute setup
    > intel code can be interpreted and executed from any offset!
    - careful with side effects
    - can use libc to increase the available ropgadgets
- use ROP to either ret2lib
- or to disable NX with `mprotect`

Beating ASLR:

- information leak
- bruteforce (32bit only)  
since last 12 bits are static we don't have to guess everything!  
partial rewrite: overwrite the LS 2 bytes (of which 12 out of 16 bits are static) -> 2^4 possible solutions

---

### Heap Overflow

- Dangling Pointer -> UAF

Arena: 
- has bins inside
- can be shared among threads, or just be for one exclusive

Bins:
- Only Free Chunks are in the bin 
- store linked lists of free chunks
- fastbins are single, others double
- fastbins are LIFO, others are FIFO

Chunks:
- minimum of 4* ptrsize
- always a multiple of 8 bytes
- ls bits of sizefields are used to store data: AMP

Chunks (used):
- prev and next pointer in the bin
- prev_size
- mchunk_size
- some info on big blocks (not relevant)

> AMP: Info about the chunks

- P 0x1: PREV_INUSE
- M 0x2: IS_MAPPED
- A 0x4: NON_MAIN_ARENA

Consolidation:
- only smallbin and largebin
- when a free borders an already free chunk will be consumed
- consumed chunk will be removed from list

The Unlink Exploit

- Metadata Heap Overflow
- Write What Where

So what do we do?

- add shellcode and/or padding into C1  
overflow metadata of C2:
- set `C2->prev_size` and `C2->size` to `-4`  
- set `C2->fwd` to the GOT entry we want to overwrite
- set `C2->bck` to the shellcode addr

What happens?

- to see if the next chunk (C2) is free, it checks the nextnext chunks `prev_inuse` bit
- this next chunk is `C2_ptr+C2->size` which equals `C2_ptr-4`
- the `prev_inuse` flag is in the `size` byte, which is `chunk_ptr+4`, so here `C2_ptr-4+4:=C2`, or `C2->prev_size`, which equals `-4`, i.e. the `prev_inuse` is NOT set.
- now the allocator will consolitate C1 and C2.
- C2 will now be unlinked from the free list, i.e.:  
```
FWD := C2->fwd # GOT_entry
BCK := C2->bck # shellcode_addr
*(FWD->bck) = BCK # writes shellcode to GOT_entry
*(BCK->fwd) = FWD # writes C1->fwd into Shellcode
```

> To prevent broken shellcode, have an indirect jump before the bytes that are being overwritten

> There used to be no checks, now it checks e.g. if `fwd->bck == self` and `bck->fwd == self`

### TCache Poisoning

- per thread cache
- 64 LIFO bins
- single linked
- very fast

> TCache doesn't use the checks modern glibc uses for the other bins!

- overwrite next_ptr
- pop off tcache entries again
- pointer to overwritten next_ptr gets returned

> Safe-Linking: fwd pointer is protected with mask of heap address

### Use After Free

Dangling pointers can cause unexpected behaviour or code execution, also leakage of data.

### VTables

- C++ objects have a virtual function table (vtable)
- vtables contains pointer to the functions of the class of the object
- overwrite vtable pointer to have great control over the control flow

### Heap Feng Shui

Prepare heap so we create new object at specific location.

### Fmt Str Exploits

- `printf` determines the amount of params by reading the fmtstr, NOT from the number of params passed.

- `"%p.%p.%p.%p"` to map out the stack

- `%s` to read until the next `\0`

- `%5$p` is the 5th param as a pointer -> arbitrary read

> READ WHAT WHERE with `%n`

- `%n` stores the number of written bytes into passed argument

1) find parametre offset of the target address:  
    ```bash
    for i in {1..200}; 
        do echo -n "$i: ";
        ./a.out $(echo -e "AAAABBBB...%1\$00008x%$i\$p%1\$00008x%$i\$p");
        echo;
    done | grep 41
    > 127: AAAABBBB...080482600x41414141080482600x4141414141
    ```
2) find GOT entry for `exit()` using pwndbg

3) overwrite GOT entry using `%n`  
    - split the addr into parts: `%hhn` writes a single byte only

Other targets to overwrite: function pointers, library hooks, ...

> RELRO (relocation read-only): partial is fine, full relro makes GOT read-only.

---

### ASAN

- out of bounds (heap, stack, globals)
- use after free
- use after return
- use after scope
- double free
- memory leaks (experimental)

> ASAN doesn't protect during runtime, it's only helping to find bugs!

Compiler adds new instructions: checks for poison on memory access

> ASAN is a heavy hit on performance

Shadow Memory:

- shows if memory is poisoned
- mapping from memory to shadow memory
- seperate region in memory

Memory is aligned to 8 Bytes.

Shadow memory byte is:
- 0                 -> all 8 bytes unpoisoned
- \<0               -> all 8 bytes are poisoned
- \>= 1 and <=7     -> first k bytes are unpoisoned, the rest is poisoned

Mapping: `shadow_addr = (addr >> 3) + offset`

Offset: static, `0x7fff8000` for 64-Bit GNU/Linux

`free()` -> poison whole block  
put block into quarantine -> UAF detected

> ASAN won't protect from overwriting other allocated objects

Generally, FN are possible to happen.

---

### Fuzzing

1) generate input
2) give it to binary
3) binary misbehaves?
4) analyze crash, find a bug

- Dumbfuzzing: just random input
- Coverage Guided Fuzzing:
    - input with initial input
    - grab next input
    - mutate it
    - observe: if more branches are hit, add iput to queue

Fuzzers:

- radamsa (dumb)
- AFL, libfuzzer, and hongfuzz (coverage guided)
- AFL `-Q` or hongfuzz (black-box) 

Whitebox: full knowledge of the target source  
Blackbox: need to use output or tracing like `strace` or emulation

Checklist:  
- Compile with `afl-gcc`  
- Also remember to compile libraries with `afl-gcc`

Corpus:
- high coverage wanted
- not too big
- no dupes
- `afl-tmin` -> minimize corpus
- `afl-cmin` -> remove cases that have the same coverage

AFL uses execution path of crashes:
- different paths can trigger the same bug
- same execution paths can trigger different bugs
- could add stack trace

### Exim RCE

- base encoding: 3n+1 required usually  
- BUT: 3n+2 required if illegal encoding
- then using feng shui to overwrite some metadata in the custom memory management
- only works without ASLR
