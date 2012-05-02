#include <stdlib.h>
#include <stdio.h>
#include "../include/pcb.h"
#include "../include/error.h"

struct pcb_t* new_pcb()
{
	fprintf(stdout, "[+] new_pcb():\n");
	struct pcb_t* pcb = (struct pcb_t*)malloc(sizeof(struct pcb_t));
	return pcb;
}
