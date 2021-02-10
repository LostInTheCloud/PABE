# define BUFFER_SIZE 64
#include <stdio.h>
#include <string.h>

void check_passed()
{
	puts("check passed!");
	puts("the secret is 'PABE is fun' ;)");
}

void check_failed()
{
	puts("check failed!");
	puts("try again ;)");
}

void (*check_functions[2]) (void) = {check_passed, check_failed};

int check_input(char *input)
{
	if (!strncmp(input, "PABE", strlen("PABE")))
	{
		check_functions[0]();
		return 0;
	}
	else
	{
		check_functions[1]();
		return 1;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		puts("Please provide an argument!");
		return 1;
	}

	char buffer[BUFFER_SIZE] = {0};

	strncpy(buffer, argv[1], BUFFER_SIZE - 1);

	printf("your input: %s\n", buffer);

	if (check_input(buffer))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
