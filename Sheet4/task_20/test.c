#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h> 
#include <sys/wait.h> 

void func();

int main()
{
    for(int i=0; i<5; i++)
    {
        int pid = fork();
        if(!pid) //child
        {
            func();
        exit(EXIT_SUCCESS);
        }
        else //parent
        {
            wait(NULL);
        }
    }
}

void func()
{
    uint64_t var[1];
    printf("%llx\n", *(var+1));
}