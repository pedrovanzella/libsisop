#include "../include/dispatcher.h"
#include "../include/lists.h"
#include "../include/pcb.h"

#include <stdlib.h>

struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb)
{
	struct pcb_t* next = ready->pcb;
	while (next->prio < pcb->prio) {
		next = ready->next->pcb;
	}

	return next;
}

int dispatcher_init()
{
	ready = new_list();
	blocked = new_list();

	running_proc = new_pcb();

	makecontext(running_proc->context, (void *)(dispatcher), 0);
	running_proc->pid = 0;
	running_proc->prio = 2;

	current_pid = 1;

	return 1;
}

void dispatcher()
{
}
