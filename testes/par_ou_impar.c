#include <stdio.h>
#include <stdlib.h>
#include "../include/unucleo.h"

void conta_par()
{
	int i;
	for(i = 2; i <= 20; i += 2) {
		printf("Par:\t[%d]\n", i);
		mproc_yield();
	}
}

void conta_impar()
{
	int i;
	for(i = 1; i <= 19; i += 2) {
		printf("Impar:\t[%d]\n", i);
		mproc_yield();
	}
}

int main(int argc, char* argv[])
{
	libsisop_init();

	mproc_create(1, (void*)conta_impar, (void*)NULL);
	mproc_create(1, (void*)conta_par, (void*)NULL);

	return 0;
}
