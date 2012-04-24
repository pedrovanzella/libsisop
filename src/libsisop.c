#include "../include/libsisop.h"

int libsisop_init()
{
	return 1;
}

int mproc_create(int prio, void*(*start_routine)(void*), void * arg)
{
	return 1;
}

void mproc_yield(void)
{

}

int mproc_join(int pid)
{
	return 1;
}
