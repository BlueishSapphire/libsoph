#ifndef SOPH_LINKED_LIST_H
#define SOPH_LINKED_LIST_H

#include <stddef.h>

struct _sll_node {
	struct _sll_node *next;
	void *val;
};

typedef struct _sll_node sll_node_t;

typedef struct {
	sll_node_t *head;
	size_t len;
} sll_t;

sll_t sll_new();
void sll_push_tail(sll_t *sll, void *val);
void sll_push_head(sll_t *sll, void *val);
void *sll_pop_tail(sll_t *sll);
void *sll_pop_head(sll_t *sll);
void sll_insert(sll_t *sll, void *val, size_t i);
void *sll_get(sll_t *sll, size_t i);
void *sll_get_head(sll_t *sll);
void *sll_get_tail(sll_t *sll);
void *sll_remove(sll_t *sll, size_t i);



struct _dll_node {
	struct _dll_node *prev;
	struct _dll_node *next;
	void *val;
};

typedef struct _dll_node dll_node_t;

typedef struct {
	dll_node_t *tail;
	dll_node_t *head;
	size_t len;
} dll_t;

dll_t dll_new();
void dll_push_tail(dll_t *dll, void *val);
void dll_push_head(dll_t *dll, void *val);
void *dll_pop_tail(dll_t *dll);
void *dll_pop_head(dll_t *dll);
void dll_insert(dll_t *dll, void *val, size_t i);
void *dll_get(dll_t *dll, size_t i);
void *dll_get_head(dll_t *dll);
void *dll_get_head(dll_t *dll);
void *dll_remove(dll_t *dll, size_t i);


#endif // SOPH_LINKED_LIST_H
