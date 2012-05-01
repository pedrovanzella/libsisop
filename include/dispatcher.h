#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_
#include "pcb.h"

struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb);

#endif /* _DISPATCHER_H_ */
