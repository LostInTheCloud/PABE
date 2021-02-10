from pwn import *

conn = remote('pabe.seclab-bonn.de', 11337)
# x = conn.recvuntil('@')
x = conn.recvline()
a = x.decode("utf-8").strip()
print(a)
# x = conn.recvuntil('%')
x = conn.recvline()
b = x.decode("utf-8").strip()
print(b)
c = (a[:-1])+(b[:-1]) + '\n'
print(c.strip())
conn.send(c.encode("utf-8"))
x = conn.recv()
print(x.decode("utf-8").strip())