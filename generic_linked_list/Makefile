CC = gcc
CFLAGS = -pedantic -Wall -g

generic_ll_app: generic_ll_app.o lib.o
	$(CC) $(CFLAGS) -o generic_ll_app generic_ll_app.o lib.o

generic_ll_app.o: generic_ll_app.c lib.h lib.o
	$(CC) $(CFLAGS) -c generic_ll_app.c 

lib_hashmap_demo: lib_hashmap_demo.o lib.o
	$(CC) $(CFLAGS) -o lib_hashmap_demo lib_hashmap_demo.o lib.o

lib_hashmap_demo.o: lib_hashmap_demo.c lib.h lib.o
	$(CC) $(CFLAGS) -c lib_hashmap_demo.c 

lib_demo: lib_demo.o lib.o
	$(CC) $(CFLAGS) -o lib_demo lib_demo.o lib.o

lib_demo.o: lib_demo.c lib.h lib.o
	$(CC) $(CFLAGS) -c lib_demo.c 

lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c

clean:	
	rm -rf *.o lib_demo generic_ll_app lib_hashmap_demo

