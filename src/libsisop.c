#include <stdlib.h>
#include <stdio.h>

#include "../include/unucleo.h"
#include "../include/lists.h"
#include "../include/pcb.h"
#include "../include/error.h"
#include "../include/dispatcher.h"

/* External symbols from pcb.h */

extern struct list_t* ready;
extern struct list_t* blocked;
extern struct pcb_t* running_proc;
extern int current_pid;

int libsisop_init()
{
	return dispatcher_init();
}

int mproc_create(int prio, void*(*start_routine)(void*), void * arg)
{
	if (prio >= 3) {
		fprintf(stdout, "[-] Warning: trying to create process with priority higher than high. Defaulting to medium.\n");
		prio = prio_medium;
	}

	if (prio == 2) {
		fprintf(stdout, "[+] Creating a process with high priority. If this is not a system process, this might starve the dispatcher!\n");
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
	struct pcb_t* next = find_next_of_equal_or_higher_priority(running_proc);
	
	add_to_end(ready, running_proc); /* running process has yielded */

	running_proc = next; /* Run next process by priority */

	setcontext(running_proc->context);
}

int mproc_join(int pid)
{
	return 1;
}
