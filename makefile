ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o linked_list.o library.o
	$(CC) -o test_functions main.o linked_list.o library.o

main.o: main.c linked_list.h library.h
	$(CC) -c main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c

library.o: library.c library.h
	$(CC) -c library.c

run:
	./test_functions

clean:
	rm *.o
	rm *~
