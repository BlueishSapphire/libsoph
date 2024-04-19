#include <soph/vec.h>

#include <stdlib.h>
#include <assert.h>
#include <string.h>

vec_t vec_new(size_t size) {
	if (size == 0) size = DEFAULT_VEC_SIZE;
	vec_t vec = (vec_t) {
		.arr = malloc(size * sizeof(void *)),
		.size = size,
		.len = 0,
	};
}

vec_t vec_copy_of(vec_t *vec) {
	vec_t copy = vec_new(vec->size);
	memcpy(copy.arr, vec->arr, vec->len);
	copy.len = vec->len;
	return copy;
}

int vec_resize(vec_t *vec, size_t size) {
	assert(size > 0);
	vec->arr = realloc(vec->arr, vec->size = size);
	return vec->arr == NULL ? -1 : 0;
}

int vec_push(vec_t *vec, void *val) {
	if (vec->len >= vec->size) {
		if (vec_resize(vec, vec->size * 2)) return -1;
	}
	vec->arr[vec->len++] = val;
	return 0;
}

void *vec_pop(vec_t *vec) {
	return vec->arr[vec->len--];
}

void vec_insert(vec_t *vec, size_t i, void *val) {
	assert(i < vec->len);
	size_t j = vec->len;
	while (j > i) vec->arr[j] = vec->arr[j - 1];
	vec->arr[i] = val;
	vec->len++;
}

void *vec_remove(vec_t *vec, size_t i) {
	assert(i < vec->len);
	void *res = vec->arr[i];
	while (i < vec->len) vec->arr[i] = vec->arr[i + 1];
	vec->len--;
	return res;
}

void *vec_get(vec_t *vec, size_t i) {
	assert(i < vec->len);
	return vec->arr[i];
}

void vec_set(vec_t *vec, size_t i, void *val) {
	assert(i < vec->len);
	vec->arr[i] = val;
}
