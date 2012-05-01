#include <stdlib.h>
#include <stdio.h>

#include "../include/lists.h"
#include "../include/error.h"

struct list_t* new_list(enum priority_t prio)
{
	struct list_t* list = (struct list_t*)malloc(sizeof(struct list_t));
	list->prio = prio;
	list->next = NULL;
	list->pcb = NULL;

	return list;
}

int add_to_end(struct list_t* list, struct list_t* node)
{
	if (list->prio != node->prio)
	{
		fprintf(stderr, "[-] Failed to add node to list, priority mismatch. List priority: %d, Node priority: %d\n", list->prio, node->prio);
		return ERR_PRIO_MISMATCH;
	}

	while (list->next) { /* Find last element */
		list = list->next;
	}

	list->next = node;

	return 1;
}

int remove_node(struct list_t* list, struct list_t* node)
{
	if (list->prio != node->prio) { /* dirty way to check for membership */
		fprintf(stderr, "[-] Failed to remove node from list. Node shouldn't be here: priority mismatch (List: %d, Node: %d)\n", list->prio, node->prio);
		return ERR_PRIO_MISMATCH;
	}

	while (list->next != node) { /* Find previous node in list */
		if (list->next == node) break; // We want to stop one before
		list = list->next;
	}

	if (!list) { /* Couldn't find node */
		fprintf(stderr, "[-] Node not in list\n");
		return ERR_NODE_NOT_IN_LIST;
	}

	list->next = node->next;

	free(node); /* Release node */

	return 1;
}
