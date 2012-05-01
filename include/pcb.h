#ifndef _PCB_H_
#define _PCB_H_
#include <ucontext.h>

typedef status_t enum {ready, running, blocked};

typedef pcb_t struct {
	int pid;
	status_t status;
	ucontext_t* context; /* Processes' status */
};

#endif /* _PCB_H_ */
