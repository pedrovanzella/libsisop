#include <stdlib.h>
#include <stdio.h>

#include "../include/lists.h"
#include "../include/pcb.h"
#include "../include/error.h"

struct list_t* new_list()
{
	fprintf(stdout, "\t\t[+] new_list():\n");
	struct list_t* list = (struct list_t*)malloc(sizeof(struct list_t));
	list->next = NULL;
	list->pcb = NULL;

	return list;
}

int add_to_end(struct list_t* list, struct pcb_t* pcb)
{
	fprintf(stdout, "\t\t[+] add_to_end(): [pid: %d]\n", pcb->pid);
	while (list->next) { /* Find last element */
		list = list->next;
	}

	struct list_t* node = new_list();
	node->pcb = pcb;

	list->next = node;

	return 1;
}

int remove_node(struct list_t* list, struct pcb_t* pcb)
{
	fprintf(stdout, "\t\t[+] remove_node(): [pid: %d]\n", pcb->pid);
	while (list->next->pcb->pid != pcb->pid) { /* Find previous node in list */
		if (list->next->pcb->pid == pcb->pid) break; // We want to stop one before
		list = list->next;
	}

	if (!list) { /* Couldn't find node */
		fprintf(stderr, "[-] Node not in list\n");
		return ERR_NODE_NOT_IN_LIST;
	}

	list->next = list->next->next;

	return 1;
}
