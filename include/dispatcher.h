#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_
#include "pcb.h"

struct list_t* ready;
struct list_t* blocked;
struct pcb_t* running_proc;
int current_pid;

/* Returns null if no suitable process is found! */
struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb);
int dispatcher_init();

#endif /* _DISPATCHER_H_ */
