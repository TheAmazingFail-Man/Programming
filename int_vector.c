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

intVector *int_vector_copy (const intVector *v)
{
	intVector *copy = int_vector_new (v->capacity);
	if (!copy) {
	
		return NULL;
	} else {
		memcpy (copy->data, v->data, v->size);
		
		return copy;
	}
}

int int_vector_push_back (intVector *v, int item)
{
	if (v->capacity == v->size) {
		v = realloc(v, v->capacity * 2);
		if (!v) {
		
			return -1;
		}
		v->capacity *= 2;
	}
	v->data[v->size++] = item;
	
	return 0;
}

void int_vector_pop_back (intVector *v)
{
	if (v->size == 0) {
		printf ("No effect\n");
	} else {
		v->data[v->size--] = 0;
	}
}

void int_vector_free (intVector *v)
{
	if (v) {
		free(v->data);
		free(v);
	}
}