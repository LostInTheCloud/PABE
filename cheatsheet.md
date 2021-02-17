# PABE WS 2020/2021

## Practical Cheats
---
install stuff
```
sudo pacman -S gdb pwndbg python python-pwntools code git \
               ghidra nmap gcc lib32-gcc-libs lib32-glibc
```
---
use PWNDBG  
```
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

---

Websites:

- godbolt.org Online C to Assembly
- http://shell-storm.org/online/Online-Assembler-and-Disassembler/ Assembler and Disassembler
- https://www.rapidtables.com/convert/number/hex-dec-bin-converter.html Converter

---

Strip symbols and sections: `strip a.out`  
Tracing: `ltrace` or `strace`  
Fiding bugs: `valgrind` or `-fsanitize-address`

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
in `cat /proc/<id>/status`  
determines the syscalls the process can invoke

---
### ELF Files

<img src="docs/todo.png" alt="drawing" width="200"/>

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

#### Calling Conventions

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