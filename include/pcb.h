#ifndef _PCB_H_
#define _PCB_H_

#define _XOPEN_SOURCE /* To compile under OSX */
#include <ucontext.h>

enum status_t {ready, blocked};

struct pcb_t {
	int pid;
	enum status_t status;
	ucontext_t* context; /* Processes' status */
};

#endif /* _PCB_H_ */
