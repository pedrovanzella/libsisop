#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/pcb.h"
#include "../include/error.h"

struct list_t* ready[3]; /* index is priority */
struct list_t* blocked[3];

int libsisop_init()
{
	for (int i = 0; i <= 2; i++) {
		ready[i] = new_list(i);
		if (!ready[i]) {
			fprintf(stderr, "[-] Failed to init ready list for priority [%d]\n", i);
			return ERR_LIST_MALLOC;
		}
		blocked[i] = new_list(i);
		if (!blocked[i]) {
			fprintf(stderr, "[-] Failed to init blocked list for priority [%d]\n", i);
		}
	}
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
