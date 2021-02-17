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
get maps with `vmmap`  
seach function with `p system`  
search string with `find <start_addr>, <end_addr>, "/bin/sh"`

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

### Static Analysis