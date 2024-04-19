#ifndef SOPH_MEM_H
#define SOPH_MEM_H

#include <stdlib.h>


// heap allocation of type T
#define new(T) ( \
	(typeof(T) *) \
	malloc(sizeof(typeof(T))) \
)

// heap allocated copy of X
#define heap(X) ( \
	(typeof(X) *) \
	memcpy(malloc(sizeof(typeof(X))), &(X), sizeof(typeof(X))) \
)

#endif // SOPH_MEM_H
