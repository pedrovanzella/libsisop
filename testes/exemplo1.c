#include "../include/unucleo.h"
#include <stdio.h>

void say_hello()
{
	printf("Hello, World!\n");
}

int main(int argc, char* argv[])
{
	mproc_create(1, (void *)say_hello, (void *)NULL);
	return 0;
}
