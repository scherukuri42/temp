CC=gcc
CFLAGS=-ggdb -Wall -Werror

# Target library
lib := libuthread.a

all: $(lib) queue.o context.o uthread.o
     
%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ $^
	rm *.o
		
%.o: %.c %.h queue.h
	$(CC) -c -o $@ $< $(CFLAGS) 
	
%.o: %.c %.h context.h queue.h
	$(CC) -c $< $(CFLAGS) 

clean:
	rm -r *.out
## TODO: Phase 1.1