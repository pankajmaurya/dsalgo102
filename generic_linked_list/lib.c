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
