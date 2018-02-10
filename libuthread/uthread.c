#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#include "context.h"
#include "preempt.h"
#include "queue.h"
#include "uthread.h"

/* TODO Phase 2 */

struct tcb{
	void *tcb_stack;
	uthread_ctx_t *tcb_pointer;
	int state;
	//thread_id* t_pointer
};

struct tcb *block = malloc(sizeof(struct tcb *));
block->state = 0;
struct tcb *zomb = malloc(sizeof(struct tcb *));
zomb->state = 1;
struct tcb *ready = malloc(sizeof(struct tcb *));
ready->state = 2;
struct tcb *runn = malloc(sizeof(struct tcb *));
runn->state = 3;

struct tcb *thread_id thread;
struct tcb *thread_id current_thread;
queue_t ready_thread;
queue_t finished_thread;

void uthread_yield(void)
{       
        /* TODO Phase 2 */
	struct tcb *newThread = current_thread;
	queue_dequeue(ready_thread, (void **) &current_thread);
	if(newThread->state != 0 && newThread->state != 1){
		newThread->state=2;
		queue_enqueue(ready_thread, newThread);
	}
}

uthread_t uthread_self(void)
{
        /* TODO Phase 2 */
}

int uthread_create(uthread_func_t func, void *arg)
{
        /* TODO Phase 2 */
	newQueue=queue_create();
}

void uthread_exit(int retval)
{
        /* TODO Phase 2 */
	current_thread->state=1;
	uthread_ctx_destroy_stack(current_thread->tcb_stack);
	queue_enqueue(newQueue, current_thread);
	uthread_yield();
}

int uthread_join(uthread_t tid, int *retval)
{
        /* TODO Phase 2 */
        /* TODO Phase 3 */
}

