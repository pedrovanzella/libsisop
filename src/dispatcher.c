#include "../include/dispatcher.h"
#include "../include/lists.h"
#include "../include/pcb.h"

#include <stdlib.h>
#include <stdio.h>

#define _XOPEN_SOURCE /* To compile under OSX */
#include <ucontext.h>

struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb)
{
	fprintf(stdout, "[+] find_next_of_equal_or_higher_priority(): [priority: %d] [pid: %d]\n", pcb->prio, pcb->pid);
	struct pcb_t* next = ready->pcb;
	while (next->prio < pcb->prio) {
		next = ready->next->pcb;
	}

	return next;
}

struct pcb_t* find_next_of_priority(int prio)
{
	fprintf(stdout, "[+] find_next_of_priority(%d):\n", prio);
	struct pcb_t* next = ready->pcb;
	while (next->prio != prio) {
		next = ready->next->pcb;
	}

	return next;
}

int dispatcher_init()
{
	fprintf(stdout, "\t[+] dispatcher_init():\n");
	fprintf(stdout, "\t[+] dispatcher_init(): Creating ready list.\n");
	ready = new_list();
	fprintf(stdout, "\t[+] dispatcher_init(): Creating blocked list.\n");
	blocked = new_list();

	fprintf(stdout, "\t[+] dispatcher_init(): Creating dispatcher_context pcb.\n");
	dispatcher_context = new_pcb();

	makecontext(dispatcher_context->context, (void *)(dispatcher), 0);
	dispatcher_context->pid = 0;
	dispatcher_context->prio = 2;

	fprintf(stdout, "\t[+] dispatcher_init(): setting the current running process as the dispatcher.\n");
	running_proc = dispatcher_context;

	current_pid = 1;

	return 1;
}

void dispatcher()
{
	fprintf(stdout, "[+] dispatcher():\n");
	while(1) { /* Dispatcher never finishes running */
		fprintf(stdout, "\t[+] Dispatcher running\n");

		fprintf(stdout, "\t[+] dispatcher(): Finding next of priority 1.\n");
		struct pcb_t* next = find_next_of_priority(1);
		if (!next) { /* There is no process of medium priority */
			fprintf(stdout, "\t[+] dispatcher(): Finding next of priority 0.\n");
			next = find_next_of_priority(0); /* Find someone with a low priority */
		}

		if (next) { /* There is someone to be ran */
			fprintf(stdout, "\t[+] dispatcher(): setting the current running process. [pid: %d]\n", next->pid);
			running_proc = next;
		}

		fprintf(stdout, "\t[+] dispatcher(): Swapping context.\n");
		swapcontext(running_proc->context, dispatcher_context->context);
	}
}
