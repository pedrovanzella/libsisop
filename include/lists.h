#ifndef _LISTS_H_
#define _LISTS_H_

#include "pcb.h"

struct list_t {
	struct pcb_t* pcb;
	struct list_t* next;
};

struct list_t* new_list();
int add_to_end(struct list_t* list, struct pcb_t* pcb);
int remove_node(struct list_t* list, struct pcb_t* pcb);

#endif /* _LISTS_H_ */
