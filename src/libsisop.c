#include <stdlib.h>
#include <stdio.h>

#define _XOPEN_SOURCE /* To compile under OSX */
#include <ucontext.h>

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
	fprintf(stdout, "[+] libsisop_init():\n");
	return dispatcher_init();
}

int mproc_create(int prio, void*(*start_routine)(void*), void * arg)
{
	fprintf(stdout, "[+] mproc_create():\n");
	if (prio >= 3) {
		fprintf(stdout, "[-] Warning: trying to create process with priority higher than high. Defaulting to medium.\n");
		prio = prio_medium;
	}

	if (prio == 2) {
		fprintf(stdout, "[+] Creating a process with high priority. If this is not a system process, this might starve the dispatcher!\n");
	}

	fprintf(stdout, "\t[+] mproc_create(): Creating new PCB. [pid: %d] [prio: %d]\n", current_pid, prio);
	struct pcb_t* pcb = new_pcb();

	makecontext(pcb->context, (void *)(*start_routine), 1, arg);
	pcb->pid = current_pid;
	pcb->prio = prio;
	current_pid++;

	fprintf(stdout, "\t[+] mproc_create(): Adding pcb to end of ready list. [pid: %d]\n", pcb->pid);
	add_to_end(ready, pcb);

	return pcb->pid;
}

void mproc_yield(void)
{
	fprintf(stdout, "[+] mproc_yield():\n");
	struct pcb_t* next = find_next_of_equal_or_higher_priority(running_proc);
	
	fprintf(stdout, "\t[+] mproc_yield(): Adding running_proc to end of ready list. [pid: %d]\n", running_proc->pid);
	add_to_end(ready, running_proc); /* running process has yielded */

	running_proc = next; /* Run next process by priority */

	setcontext(running_proc->context);
}

int mproc_join(int pid)
{
	fprintf(stdout, "[+] mproc_join(%d):\n", pid);
	return 1;
}
