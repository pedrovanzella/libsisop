#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/pcb.h"
#include "../include/error.h"

struct list_t* ready;
struct list_t* blocked;

int current_pid;

struct pcb_t* running_proc; /* If NULL, we must find another process to run */

int libsisop_init()
{
	ready = new_list();

	blocked = new_list();

	running_proc = NULL;

	current_pid = 0;
	return 1;
}

int mproc_create(int prio, void*(*start_routine)(void*), void * arg)
{
	if (prio >= 3) {
		fprintf(stdout, "[-] Warning: trying to create process with priority higher than high. Defaulting to medium.\n");
		prio = prio_medium;
	}
	struct pcb_t* pcb = new_pcb();

	makecontext(pcb->context, (void *)(*start_routine), 1, arg);
	pcb->pid = current_pid;
	pcb->prio = prio;
	current_pid++;

	add_to_end(ready, pcb);

	return pcb->pid;
}

void mproc_yield(void)
{

}

int mproc_join(int pid)
{
	return 1;
}
