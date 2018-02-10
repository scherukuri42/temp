#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define MAX 512

struct queue {
        /* TODO Phase 1 */
	int length, front, back, size
	void** arr;
};

queue_t queue_create(void)
{       
        /* TODO Phase 1 */
	queue_t Queue1 = (queue_t) malloc(sizeof(struct queue));
	Queue1->length=0;
	Queue1->front=0;
	Queue1->back=0;
	Queue1->size=MAX;
	Queue1->arr=(void**)malloc(sizeof(void*)*MAX)
	return Queue1;

}

int queue_destroy(queue_t queue)
{       
        /* TODO Phase 1 */
	if(queue != NULL){
		if(queue->length==0){
			free(queue);
			return 0;
		}
	}
	else{
		return -1
	}
}

int queue_enqueue(queue_t queue, void *data)
{       
        /* TODO Phase 1 */
		queue->back++; //increment to position that needs to be added
		queue->arr[queue->back]=data; 
		queue->length++;
		return 0;
	
}

int queue_dequeue(queue_t queue, void **data)
{
        /* TODO Phase 1 */
	queue->length--; //readjust size of queue
	*data=queue->arr[queue->front];
	queue->arr[queue->front]=NULL;
	queue->front++;
	return 0;
}

int queue_delete(queue_t queue, void *data)
{
        /* TODO Phase 1 */
	front = queue->front;
	back = queue->back;
	for(int i=0; i<=back; i++){
		if(queue->arr[i]==data){
			queue->arr[i]=NULL;
			while(i>front){
				queue->arr[i]=queue->arr[i-1];
				i--;
			} //shift item up
			queue->length--; //decrement length
			queue->front++; 
			return 0;
		}
	}
	return -1;
}

int queue_iterate(queue_t queue, queue_func_t func, void *arg, void **data)
{
        /* TODO Phase 1 */
	
	
}

int queue_length(queue_t queue)
{
        /* TODO Phase 1 */
	return queue->length;
}
