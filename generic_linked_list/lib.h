#ifndef __LIB_H__
#define __LIB_H__

#define MAX_LL_LEN 1000
// Function pointers to support comparison of value
typedef int(*CallbackCompare)(void *a, void *b);
//typedef bool(*CallbackIterate)(int index, Node *node);

// A doubly linked list
typedef struct node *Nodeptr;
typedef struct node {
        void *val;
        Nodeptr next;
        Nodeptr prev;
} Node;

typedef struct linkedlist {
	Nodeptr head;
	Nodeptr tail;
	int size;
	CallbackCompare callback_compare;
} LinkedList;

typedef struct linkedlist *llptr;

void init(llptr ll, CallbackCompare compare_callback);
int add(llptr ll, void *item);
Nodeptr remove_ll_ref(llptr ll, void *item);
Nodeptr remove_ll_cmp(llptr ll, void *item);
//void iterate_ll(llptr ll, CallbackIterate iterate_callback);


#endif

