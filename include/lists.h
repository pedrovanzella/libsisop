#ifndef _LISTS_H_
#define _LISTS_H_

#include "pcb.h"

typedef list_t struct {
	pcb_t* pcb;
	list_t* next;
}

#endif /* _LISTS_H_ */
