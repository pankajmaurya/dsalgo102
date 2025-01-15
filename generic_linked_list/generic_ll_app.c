#include <string.h> // for strcmp()
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct appdata {
	int x;
	char* fruit;
} AppData;

int compare_demo(void* a, void* b) {
	AppData* da = (AppData*) a;
	AppData* db = (AppData*) b;
	printf("Comparing values: %d and %d\n", da->x, db->x);
	int fruitCmp = strcmp(da->fruit, db->fruit);
	if (fruitCmp == 0) {
		return (da->x - db->x);
	} else {
		return fruitCmp;
	}
}

int main(int argc, char **argv) {
    LinkedList *ll = malloc(sizeof(LinkedList));
	int (*fun_ptr)(void*, void*) = &compare_demo;
	init(ll, fun_ptr);
    printf("Linked list size : %d\n", ll->size);

	for (int i = 1; i <= 6; i++) {
		AppData* d = malloc(sizeof(AppData));
		d->x = i;
		d->fruit = "apple";
		add(ll, d);
	}
        printf("Linked list size : %d\n", ll->size);
        
	// Now remove the node with payload = d
	for (int i = 3; i <= 6; i++) {
		AppData* d = malloc(sizeof(AppData));
		d->x = i;
		d->fruit = "apple";
		remove_ll_cmp(ll, d);
	}
        printf("Linked list size : %d\n", ll->size);
	
	return 0;
}

