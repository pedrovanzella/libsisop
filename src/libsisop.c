#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/pcb.h"
#include "../include/error.h"

struct list_t* ready[3]; /* index is priority */
struct list_t* blocked[3];

int current_pid;

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

	current_pid = 0;
	return 1;
}

int mproc_create(int prio, void*(*start_routine)(void*), void * arg)
{
	if (prio >= 3) {
		fprintf(stdout, "[-] Warning: trying to create process with priority higher than high. Defaulting to medium.\n");
		prio = prio_medium;
	}
	struct pcb_t* pcb = (struct pcb_t*)malloc(sizeof(struct pcb_t));
	if (!pcb) {
		fprintf(stderr, "[-] Failed to malloc() new pcb.\n");
		return ERR_PCB_MALLOC;
	}
	makecontext(pcb->context, (void *)(*start_routine), 1, arg);
	pcb->pid = current_pid;
	current_pid++;

	struct list_t* node = new_list(prio);
	node->pcb = pcb;

	add_to_end(ready[prio], node);

	return pcb->pid;
}

void mproc_yield(void)
{

}

int mproc_join(int pid)
{
	return 1;
}
