#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char * argc [] = {"./execute_me_with_rop","foo","bar",0};
    char * envp [] = {"PABE=FUN",0};
    execve(argc[0], argc, envp);
    return 0;
}