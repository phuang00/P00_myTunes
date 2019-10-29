all: main.o linked_list.o library.o
	gcc -o test_functions main.o linked_list.o library.o

main.o: main.c linked_list.h library.h
	gcc -c main.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

library.o: library.c library.h
	gcc -c library.c

run:
	./test_functions
