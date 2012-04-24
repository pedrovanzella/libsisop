#ifndef _LIBSISOP_H_
#define _LIBSISOP_H_

int libsisop_init();
int mproc_create(int prio, void*(*start_routine)(void*), void * arg);
void mproc_yield(void);
int mproc_join(int pid);

#endif /* _LIBSISOP_H_ */
