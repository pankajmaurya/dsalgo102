#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct demo {
	int x;
} Demo;

int simple_hasher(void* a) {
	Demo* da = (Demo*) a;
	return da->x;
}

int main(int argc, char **argv) {
	GenericHashMap *ghm = malloc(sizeof(GenericHashMap));
	int (*fun_ptr)(void*) = &simple_hasher;
    init_hash_map(ghm, fun_ptr, 3);
    
	for (int i = 1; i <= 10; i++) {
		Demo* d = malloc(sizeof(Demo));
		d->x = i;
		add_mapping(ghm, d, d);
	}
    return 0;
}

