CC = gcc
CFLAGS = -pedantic -Wall -g

lib_demo: lib_demo.o lib.o
	$(CC) $(CFLAGS) -o lib_demo lib_demo.o lib.o

lib_demo.o: lib_demo.c lib.h lib.o
	$(CC) $(CFLAGS) -c lib_demo.c 

lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c

clean:	
	rm -rf *.o lib_demo

