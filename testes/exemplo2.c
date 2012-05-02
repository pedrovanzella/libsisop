#include <stdio.h>
#include <stdlib.h>
#include "../include/unucleo.h"

void conta_um_cinco()
{
	for(int i = 1; i <= 5; i++)
		printf("[%d]\n", i);
}

void conta_seis_nove()
{
	for(int i = 6; i <= 9; i++)
		printf("[%d]\n", i);
}

int main(int argc, char* argv[])
{
	libsisop_init();

	mproc_create(2, (void*)conta_um_cinco, (void*)NULL);
	mproc_create(2, (void*)conta_seis_nove, (void*)NULL);

	return 1;
}
