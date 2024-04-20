#include <soph/ll.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


sll_t sll_new() {
	return (sll_t) { .head = NULL, .len = 0 };
}
void sll_free(sll_t *sll) {
	sll_node_t *node = sll->head;
	while (--sll->len) {
		sll_node_t *tmp = node->next;
		free(node);
		node = tmp;
	}
}
void sll_push_tail(sll_t *sll, void *val) {
	assert(sll);

	size_t i = sll->len++;
	sll_node_t *node = sll->head;
	while (--i) node = node->next;
	node->next = malloc(sizeof(sll_node_t));
	*node->next = (sll_node_t) { .next = NULL, .val = val };
}
void sll_push_head(sll_t *sll, void *val) {
	assert(sll);

	sll->len++;
	sll_node_t *oldhead = sll->head;
	sll->head = malloc(sizeof(sll_node_t));
	*sll->head = (sll_node_t) { .next = oldhead, .val = val };
}
void *sll_pop_tail(sll_t *sll) {
	assert(sll && sll->head);

	size_t i = sll->len--;
	sll_node_t *node = sll->head;
	while (--i) node = node->next;
	void *ret = node->next->val;
	free(node->next);
	node->next = NULL;
	return ret;
}
void *sll_pop_head(sll_t *sll) {
	assert(sll && sll->head);

	sll->len--;
	void *newhead = sll->head->next;
	void *ret = sll->head->val;
	free(sll->head);
	sll->head = newhead;
	return ret;
}
void sll_insert(sll_t *sll, void *val, size_t i) {
	assert(sll && sll->head);
	if (i == 0) return sll_push_head(sll, val);
	if (i == sll->len) return sll_push_tail(sll, val);
	assert(i < sll->len);

	sll->len++;
	sll_node_t *node = sll->head;
	while (--i) node = node->next;

	sll_node_t *next = node->next;
	sll_node_t *new_node = malloc(sizeof(sll_node_t));
	*new_node = (sll_node_t) { .val = val, .next = next->next };
	node->next = new_node;
}
void *sll_get(sll_t *sll, size_t i) {
	assert(sll && sll->head);
	assert(i < sll->len);

	sll_node_t *node = sll->head;
	while (i--) node = node->next;
	return node->val;
}
void *sll_get_head(sll_t *sll) {
	assert(sll && sll->head);
	return sll->head->val;
}
void *sll_get_tail(sll_t *sll) {
	assert(sll && sll->head);

	size_t i = sll->len;
	sll_node_t *node = sll->head;
	while (--i) node = node->next;
	return node->val;
}
void *sll_remove(sll_t *sll, size_t i) {
	assert(sll && sll->head);
	if (i == 0) return sll_pop_head(sll);
	if (i == sll->len) return sll_pop_tail(sll);
	assert(i < sll->len);

	sll->len--;
	sll_node_t *node = sll->head;
	while (--i) node = node->next;
	sll_node_t *target = node->next;
	void *newnext = target->next;
	void *ret = target->val;
	free(target);
	node->next = newnext;
	return ret;
}



dll_t dll_new() {
	return (dll_t) { .head = NULL, .tail = NULL, .len = 0 };
}
void dll_free(dll_t *dll) {
	dll_node_t *node = dll->head;
	while (--dll->len) {
		dll_node_t *tmp = node->next;
		free(node);
		node = tmp;
	}
}
void dll_push_tail(dll_t *dll, void *val) {
	assert(dll);

	dll->len++;
	dll_node_t *oldtail = dll->tail;
	dll->tail = malloc(sizeof(dll_node_t));
	*dll->tail = (dll_node_t) { .prev = oldtail, .next = NULL, .val = val };
	if (oldtail) oldtail->next = dll->tail;
	if (!dll->head) dll->head = dll->tail;
}
void dll_push_head(dll_t *dll, void *val) {
	assert(dll);

	dll->len++;
	dll_node_t *oldhead = dll->head;
	dll->head = malloc(sizeof(dll_node_t));
	*dll->head = (dll_node_t) { .prev = NULL, .next = oldhead, .val = val };
	if (oldhead) oldhead->prev = dll->head;
	if (!dll->tail) dll->tail = dll->head;
}
void *dll_pop_tail(dll_t *dll) {
	assert(dll && dll->tail);

	if (dll->tail == dll->head) dll->head = NULL;
	dll->len--;
	dll_node_t *newtail = dll->tail->prev;
	void *ret = dll->tail->val;
	free(dll->tail);
	dll->tail = newtail;
	newtail->next = NULL;
	if (!dll->head) dll->head = dll->tail;
	return ret;
}
void *dll_pop_head(dll_t *dll) {
	assert(dll && dll->head);

	if (dll->tail == dll->head) dll->tail = NULL;
	dll->len--;
	dll_node_t *newhead = dll->head->next;
	void *ret = dll->head->val;
	free(dll->head);
	dll->head = newhead;
	newhead->prev = NULL;
	if (!dll->tail) dll->tail = dll->head;
	return ret;
}
void dll_insert(dll_t *dll, void *val, size_t i) {
	assert(dll);
	if (i == 0) return dll_push_head(dll, val);
	if (i == dll->len) return dll_push_tail(dll, val);
	assert(dll->head && dll->tail);
	assert(i < dll->len);

	dll->len++;
	dll_node_t *prev, *next, *node;
	dll_node_t *new_node = malloc(sizeof(dll_node_t));
	if (i * 2 <= dll->len) {
		for (node = dll->head; --i; node = node->next);
		prev = node;
		next = node->next;
	} else {
		i = dll->len - i;
		for (node = dll->tail; --i; node = node->prev);
		prev = node->prev;
		next = node;
	}

	*new_node = (dll_node_t) { .prev = prev, .val = val, .next = next };
	prev->next = new_node;
	next->prev = new_node;
}
void *dll_get(dll_t *dll, size_t i) {
	assert(dll && dll->head && dll->tail);
	assert(i < dll->len);
	dll_node_t *node;
	if (i * 2 <= dll->len) {
		for (node = dll->head; --i; node = node->next);
	} else {
		i = dll->len - i;
		for (node = dll->tail; --i; node = node->prev);
	}
	return node->val;
}
void *dll_get_head(dll_t *dll) {
	assert(dll && dll->head);
	return dll->head->val;
}
void *dll_get_tail(dll_t *dll) {
	assert(dll && dll->tail);
	return dll->tail->val;
}
void *dll_remove(dll_t *dll, size_t i) {
	assert(dll);
	if (i == 0) return dll_pop_head(dll);
	if (i == dll->len) return dll_pop_tail(dll);
	assert(dll->head && dll->tail);
	assert(i < dll->len);

	dll->len--;
	dll_node_t *target;
	if (i * 2 <= dll->len) {
		for (target = dll->head; --i; target = target->next);
	} else {
		i = dll->len - i;
		for (target = dll->tail; --i; target = target->prev);
	}

	void *ret = target->val;
	dll_node_t *prev = target->prev;
	dll_node_t *next = target->next;
	free(target);
	prev->next = next;
	next->prev = prev;
	return ret;
}

