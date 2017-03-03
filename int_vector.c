#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"

intVector* int_vector_new (size_t initial_size)
{
	intVector *v = (intVector*)malloc(sizeof(intVector));
	if (!v)
	{
		return NULL;
	}
	v->data = (int*)malloc(initial_size * sizeof(int));
	if (!(v->data)){
		free(v);
		return NULL;
	}
	v->size = initial_size;
	v->capacity = initial_size;
	return v;
}

size_t int_vector_get_capacity (const intVector *v)
{
	if (v) {
		return v->capacity;
	} else {
		printf ("Fail\n");
		
		return 0;
	}
}

size_t int_vector_get_size (const intVector *v)
{
	if (v) {
		return v->size;
	} else {
		printf ("Fail\n");
		
		return 0;
	}
}

void int_vector_free (intVector *v)
{
	if (v) {
		free(v->data);
		free(v);
	}
}