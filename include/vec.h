#ifndef SOPH_VEC_H
#define SOPH_VEC_H

#include <stddef.h>


#define DEFAULT_VEC_SIZE 1024

typedef struct {
	void **arr;  // data buffer
	size_t len;  // length of currently occupied data
	size_t size; // total capacity of buffer
} vec_t;


// return a stack-allocated vec_t containing a heap-allocated array of size `size`
vec_t vec_new(size_t size);

// free the internal array of a vector
vec_t vec_free(vec_t *vec);

// make and return a copy of a given vector
vec_t vec_copy_of(vec_t *vec);

// reallocate the vector to a new size
// returns nonzero if realloc(3) gave an error
int vec_resize(vec_t *vec, size_t size);

// push a new value onto the vec, reallocating if needed
// returns nonzero if realloc(3) gave an error
int vec_push(vec_t *vec, void *val);

// pop the last value off the end of the stack
void *vec_pop(vec_t *vec);

// insert a new value at the given index, shifting all following elements to the right
void vec_insert(vec_t *vec, size_t i, void *val);

// remove a value from the given index, shifting all following elements to the left
void *vec_remove(vec_t *vec, size_t i);

// return the element at the given index
void *vec_get(vec_t *vec, size_t i);

// set the element at the given index
void vec_set(vec_t *vec, size_t i, void *val);

#endif // SOPH_VEC_H
