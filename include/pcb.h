#ifndef _PCB_H_
#define _PCB_H_

#define _XOPEN_SOURCE /* To compile under OSX */
#include <ucontext.h>

enum priority_t {prio_high, prio_medium, prio_low};

struct pcb_t {
	int pid;
	enum priority_t prio; 
	ucontext_t* context; /* Processes' status */
};

struct pcb_t* new_pcb();

#endif /* _PCB_H_ */
