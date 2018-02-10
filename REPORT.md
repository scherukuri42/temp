# Phase 1
For phase 1 we implemented our queue using a double pointer array because we felt this would have 
been able to handle queue_destroy(), queue_enqueue(), and queue_dequeue() in O(1) time
complexity. We created a struct where we declared integers such as length, front, back, and
size to keep track of important elements within our queue that we would need to call later in my
function implementations. Since we used an array to implement our queue, we have to account for 
memory reallocation so used malloc() twice in the queue_create() function. From there we
basically incremented and decremented for enqueue() and dequeue() respectively. The main
implementation feature of queue_delete() was decrementing the length of the array we were
were using anytime we delete and element. I wasn’t exactly able to figure out how to complete
queue_iterate(). For queue_length, I simply returned the length of the queue.
# Phase 2
We started Phase 2 by declaring a struct that holds our stack pointer, our TCB pointer, and our 
state integer that we will use to establish the thread condition of either ready, running, 
blocked, or zombie. To identify which state the thread is in, I established each state an 
integer value, and I used malloc() to create space with the TCB pointer. I also declared the 
availability of the threads, i.e. current, ready, finished. I was unable to figure out how to do
uthread_self() and uthread_create(). For uthread_yield(), I established a placeholder 
thread by creating an instance of my TCB struct, and set this equal to the current thread. From 
there I replace, the primary ready thread, and replace it with the new thread, which I then put 
in the queue by calling queue_enqueue(). For uthread_exit(), I destroy the stack, and call 
uthread_yield(). 
# Phase 3
We were unable to implement the uthread_join() function.
# Phase 4
We started by using sigset_t to create an instance called newSet. For preempt_disable() and 
preempt_enable(), I basically followed the same procedure by using the functions, 
sigemptyset(), sigaddset(), and sigprocmask() to implement the functionality described by
the homework instructions. I was unable to successfully implement preempt_start(). 













