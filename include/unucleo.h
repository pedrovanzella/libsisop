#ifndef _UNUCLEO_H_
#define _UNUCLEO_H_

int libsisop_init();
int mproc_create(int prio, void*(*start_routine)(void*), void * arg);
void mproc_yield(void);
int mproc_join(int pid);

#endif /* _UNUCLEO_H_ */
