#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void init(llptr ll, CallbackCompare compare_callback) {
	ll->head = NULL;
	ll->tail = NULL;
	ll->size = 0;
	ll->callback_compare = compare_callback;
}

int add(llptr ll, void *item) {
	if (ll->head == NULL) {
		ll->head = malloc(sizeof(Node));
		ll->head->val = item;
		ll->head->next = NULL;
		ll->head->prev = NULL;
		ll->tail = ll->head;
		ll->size = 1;
		return ll->size;
	}

	// case of head being present
	Nodeptr n = malloc(sizeof(Node));
	n->val = item;
	n->next = NULL;
	n->prev = ll->tail;
	ll->tail->next = n;
	ll->tail = n;
	ll->size += 1;
	return ll->size;
}

// a return value of 0 indicates false and means to end the iteration.
Nodeptr scan_ll(llptr ll, CallbackIterate callback_iterate) {
	if (ll->head == NULL) {
		return NULL;
	}
	// head must be there
	Nodeptr cur = ll->head;
	if (callback_iterate(cur->val) == 0) {
		return cur;
	}

	while (cur->next != NULL) {
		cur = cur->next;
		if (callback_iterate(cur->val) == 0) {
			return cur;
		}
	}

	return NULL;
}


Nodeptr remove_ll_cmp(llptr ll, void *item) {
	if (ll->head == NULL) {
		return NULL;
	}

	Nodeptr cur = ll->head;
	if (ll->callback_compare(cur->val, item) == 0) {
		if (ll->tail == ll->head) {
			ll->tail = NULL;
		}
		ll->head = ll->head->next;
		ll->size -= 1;
		return cur;
	}

	Nodeptr prev = cur;
	while (cur->next != NULL) {
		cur = cur->next;
		if (ll->callback_compare(cur->val, item) == 0) {
			prev->next = cur->next;
			if (cur->next != NULL) {
				cur->next->prev = prev;
			}
			if (cur == ll->tail) {
				ll->tail = prev;
			}
			ll->size -= 1;
			return cur;
		}
		prev = cur;
	}

	return NULL;
}

Nodeptr remove_ll_ref(llptr ll, void *item) {
	if (ll->head == NULL) {
		return NULL;
	}

	Nodeptr cur = ll->head;
	if (cur->val == item) {
		if (ll->tail == ll->head) {
			ll->tail = NULL;
		}
		ll->head = ll->head->next;
		ll->size -= 1;
		return cur;
	}

	Nodeptr prev = cur;
	while (cur->next != NULL) {
		cur = cur->next;
		if (cur->val == item) {
			prev->next = cur->next;
			cur->next->prev = prev;
			if (cur == ll->tail) {
				ll->tail = prev;
			}
			ll->size -= 1;
			return cur;
		}
		prev = cur;
	}

	return NULL;
}


void init_hash_map(ghmptr ghm, Hasher hasher, int num_buckets) {
	ghm->hasher = hasher;
	ghm->num_buckets = num_buckets;

	// In the very basic implementation, lets put every mapping in the same bucket!!!
	ghm->buckets = malloc(sizeof(GenericHashMapBucket));
	ghm->buckets->bucket_num = 0;
	ghm->buckets->members_list = malloc(sizeof(LinkedList));
}

void add_mapping(ghmptr ghm, void* key, void* value) {
	int bucket_num = ghm->hasher(key);
	printf("add_mapping gives bucket_num %d\n", bucket_num);
	printf("For now, we put everything in bucket number 0\n");
	GenericMapping *mapping = malloc(sizeof(GenericMapping));
	mapping->key = key;
	mapping->value = value;
	add(ghm->buckets->members_list, mapping);
}

// TODO: Check the program in scratch and implement a function returning a function
// which will scan for the given key
int scanner(void* a) {
	GenericMapping* da = (GenericMapping*) a;
	return 0;
}

void* get_value(ghmptr ghm, void *key) {
	int bucket_num = ghm->hasher(key);
	printf("add_mapping gives bucket_num %d\n", bucket_num);
	printf("For now, we put everything in bucket number 0");
	return scan_ll(ghm->buckets->members_list, scanner);
}
