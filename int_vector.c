#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"

intVector* int_vector_new (size_t initial_capacity)
{
	intVector *v = (intVector*)malloc(sizeof(intVector));
	if (!v) {
		
		return NULL;
	}
	v->data = (int*)malloc(initial_capacity * sizeof(int));
	if (!(v->data)) {
		free(v);
		
		return NULL;
	}
	v->size = 0;
	v->capacity = initial_capacity;
	
	return v;
}

size_t int_vector_get_capacity (const intVector *v)
{
	if (v) {
		
		return v->capacity;
	} else {
		printf("Fail\n");
		
		return 0;
	}
}

size_t int_vector_get_size (const intVector *v)
{
	if (v) {
	
		return v->size;
	} else {
		printf("Fail\n");
	
		return 0;
	}
}

intVector *int_vector_copy (const intVector *v)
{
	intVector *copy = int_vector_new (v->capacity);
	if (!copy) {

		return NULL;
	} else {
		memcpy(copy->data, v->data, v->size);
	
		return copy;
	}
}

int int_vector_push_back (intVector *v, int item)
{
	if (v->capacity == v->size) {
		v->data = realloc(v->data, (v->capacity * 2) * sizeof(int));
		if (!v) {
			return -1;
		}
		v->capacity *= 2;
	}
	v->data[v->size] = item;
	v->size++;
	
	return 0;
}

void int_vector_pop_back (intVector *v)
{
	if (v->size == 0) {
		printf("No effect\n");
	} else {
		v->data[v->size-1] = 0;
		v->size--;
	}
}

int int_vector_get_item (const intVector *v, size_t index)
{
	if (index > (v->size - 1)) {
		
		return NULL;
	} else {
		int i = index;
		int x = v->data[i];
		
		return x;
	}
}

void int_vector_set_item (intVector *v, size_t index, int item)
{
	if (!(index > (v->size - 1))) v->data[index] = item;
}

int int_vector_shrink_to_fit (intVector *v)
{
	v = realloc(v, v->size * sizeof(int));
	v->capacity = v->size;
	if (v->capacity == v->size) {
		return 0;
	}
	else return -1;
}

int int_vector_reserve (intVector *v, size_t new_capacity)
{
	if (new_capacity <= v->capacity) {
		
		return -1;
	} else {
		v = realloc(v, new_capacity * sizeof(int));
		v->capacity = new_capacity;
	
		return 0;
	}
}

int int_vector_resize (intVector *v, size_t new_size)
{
	int x, i;
	if (v->size > new_size) {
		v->size = new_size;
		x = int_vector_shrink_to_fit (v);
	} else {
		x = int_vector_reserve (v, new_size);
		for (i = v->size; i < new_size; i++) {
			x = int_vector_push_back(v, 0);
			v->data[i] = 0;
			v->size++;
		}
		v->size = new_size;
	}
	
	return x;
}

void int_vector_free (intVector *v)
{
	if (v) {
		free(v->data);
		free(v);
	}
}
