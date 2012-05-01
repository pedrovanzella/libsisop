#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/error.h"

struct list_t* high_priority_ready;
struct list_t* high_priority_blocked;

struct list_t* medium_priority_ready;
struct list_t* medium_priority_blocked;

struct list_t* low_priority_ready;
struct list_t* low_priority_blocked;

int libsisop_init()
{
	high_priority_ready = new_list(prio_high);
	if (!high_priority_ready) {
		fprintf(stderr, "[-] Failed to init high priority ready queue\n");
		return ERR_LIST_MALLOC;
	}

	high_priority_blocked = new_list(prio_high);
	if (!high_priority_blocked) {
		fprintf(stderr, "[-] Failed to init high priority blocked queue\n");
		return ERR_LIST_MALLOC;
	}

	medium_priority_ready = new_list(prio_medium);
	if (!medium_priority_ready) {
		fprintf(stderr, "[-] Failed to init medium priority ready queue\n");
		return ERR_LIST_MALLOC;
	}

	medium_priority_blocked = new_list(prio_medium);
	if (!medium_priority_blocked) {
		fprintf(stderr, "[-] Failed to init medium priority blocked queue\n");
		return ERR_LIST_MALLOC;
	}

	low_priority_ready = new_list(prio_low);
	if (!low_priority_ready) {
		fprintf(stderr, "[-] Failed to init low priority ready queue\n");
		return ERR_LIST_MALLOC;
	}

	low_priority_blocked = new_list(prio_low);
	if (!low_priority_blocked) {
		fprintf(stderr, "[-] Failed to init low priority blocked queue\n");
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
