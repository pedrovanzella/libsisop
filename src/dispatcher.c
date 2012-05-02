#include "../include/dispatcher.h"
#include "../include/lists.h"
#include "../include/pcb.h"

#include <stdlib.h>

struct pcb_t* find_next_of_equal_or_higher_priority(struct pcb_t* pcb)
{
}

int dispatcher_init()
{
	ready = new_list();
	blocked = new_list();
	running_proc = NULL;
	current_pid = 0;

	return 1;
}
