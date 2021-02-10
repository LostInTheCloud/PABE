#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// do not compile this binary by yourself, use the provided one!

void *safe_malloc(size_t size)
{
	void *p = (void *)calloc(size, 1u);

	if (!p)
	{
		exit(1);
	}

	return p;
}

void noise()
{
	// make some noise to fill up the tcache
	size_t number_of_noise_chunks = 60; 
	void *tcache_chunks[number_of_noise_chunks];

	for (unsigned int i = 0; i < number_of_noise_chunks; i++)
	{
		tcache_chunks[i] = safe_malloc(10 + rand() % 20);		
		strcpy((char *)tcache_chunks[i], "FOOO");
	}

	for (unsigned int i = 0; i < number_of_noise_chunks; i++)
	{
		free(tcache_chunks[i]);
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	noise();

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
