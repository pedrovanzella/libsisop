#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/error.h"

struct list_t* high_priority;
struct list_t* medium_priority;
struct list_t* low_priority;

int libsisop_init()
{
	high_priority = new_list(prio_high);
	if (!high_priority) {
		fprintf(stderr, "[-] Failed to init high priority queue\n");
		return ERR_LIST_MALLOC;
	}

	medium_priority = new_list(prio_medium);
	if (!medium_priority) {
		fprintf(stderr, "[-] Failed to init medium priority queue\n");
		return ERR_LIST_MALLOC;
	}
	
	low_priority = new_list(prio_low);
	if (!low_priority) {
		fprintf(stderr, "[-] Failed to init low priority queue\n");
		return ERR_LIST_MALLOC;
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
