#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct demo {
	int x;
} Demo;

int compare_demo(void* a, void* b) {
	Demo* da = (Demo*) a;
	Demo* db = (Demo*) b;
	printf("Comparing values: %d and %d\n", da->x, db->x);
	return (da->x - db->x);
}

int main(int argc, char **argv) {
        LinkedList *ll = malloc(sizeof(LinkedList));
	int (*fun_ptr)(void*, void*) = &compare_demo;
	init(ll, fun_ptr);
        printf("Linked list size : %d\n", ll->size);

	for (int i = 1; i <= 10; i++) {
		Demo* d = malloc(sizeof(Demo));
		d->x = i;
		add(ll, d);
	}
        printf("Linked list size : %d\n", ll->size);
        
	// Now remove the node with payload = d
	for (int i = 6; i < 14; i++) {
		Demo* d = malloc(sizeof(Demo));
		d->x = i;
		remove_ll_cmp(ll, d);
	}
        printf("Linked list size : %d\n", ll->size);
	
	return 0;
}

