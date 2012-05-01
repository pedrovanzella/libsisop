#ifndef _LISTS_H_
#define _LISTS_H_

#include "pcb.h"

enum priority_t {high, medium, low};

struct list_t {
	enum priority_t prio; /* make sure to move to right list if prio != next->prio */
	struct pcb_t* pcb;
	struct list_t* next;
};

struct list_t* new_list(enum priority_t prio);
int add_to_end(struct list_t* list, struct list_t* node);
int remove_node(struct list_t* list, struct list_t* node);

#endif /* _LISTS_H_ */
