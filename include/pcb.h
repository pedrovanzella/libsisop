#ifndef _PCB_H_
#define _PCB_H_

#define _XOPEN_SOURCE /* To compile under OSX */
#include <ucontext.h>

struct pcb_t {
	int pid;
	ucontext_t* context; /* Processes' status */
};

#endif /* _PCB_H_ */
