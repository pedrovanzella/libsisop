#include "../include/dispatcher.h"
#include "../include/lists.h"
#include "../include/pcb.h"

#include <stdlib.h>
#include <stdio.h>

struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb)
{
	struct pcb_t* next = ready->pcb;
	while (next->prio < pcb->prio) {
		next = ready->next->pcb;
	}

	return next;
}

struct pcb_t* find_next_of_priority(int prio)
{
	struct pcb_t* next = ready->pcb;
	while (next->prio != prio) {
		next = ready->next->pcb;
	}

	return next;
}

int dispatcher_init()
{
	ready = new_list();
	blocked = new_list();

	dispatcher_context = new_pcb();

	makecontext(dispatcher_context->context, (void *)(dispatcher), 0);
	dispatcher_context->pid = 0;
	dispatcher_context->prio = 2;

	running_proc = dispatcher_context;

	current_pid = 1;

	return 1;
}

void dispatcher()
{
	while(1) { /* Dispatcher never finishes running */
		fprintf(stdout, "[+] Dispatcher running\n");

		struct pcb_t* next = find_next_of_priority(1);
		if (!next) /* There is no process of medium priority */
			next = find_next_of_priority(0); /* Find someone with a low priority */

		if (next) /* There is someone to be ran */
			running_proc = next;

		swapcontext(running_proc->context, dispatcher_context->context);
	}
}
