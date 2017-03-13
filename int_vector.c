#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"

intVector* int_vector_new(size_t initial_capacity) { //sozdanie massiva
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

size_t int_vector_get_capacity(const intVector *v) { //emkost' vectora
	if (v) {
		return v->capacity;
	}
	else {
		printf("Fail\n");
		return 0;
	}
}

size_t int_vector_get_size(const intVector *v) { //razmer vectora
	if (v) {
		return v->size;
	}
	else {
		printf("Fail\n");
		return 0;
	}
}

intVector *int_vector_copy(const intVector *v) { //ukazatel' na kopiyu vektora ili NULL
	intVector *copy = int_vector_new(v->capacity);
	if (!copy) {
		return NULL;
	}
	else {
		memcpy(copy->data, v->data, v->size);
		return copy;
	}
}

int int_vector_push_back(intVector *v, int item) { //dobavlyaet element v konec
	int x;
	if (v->capacity == v->size) {
		v->data = realloc(v->data, (v->capacity*2)*sizeof(int));
		if (!v) {
			return -1;
		}
		v->capacity *= 2;
	}
	x = v->size;
	v->data[x] = item;
	v->size++;
	return 0;
}

void int_vector_pop_back(intVector *v) { //udalyaet posledniy element massiva
	int x;
	if (v->size == 0) {
		printf("No effect\n");
	}
	else {
		x = v->size - 1;
		v->data[x] = 0;
		v->size--;
	}
}

void int_vector_free(intVector *v) { //osvobojdaet pamyat' na vector
	if (v) {
		free(v->data);
		free(v);
	}
}

int int_vector_get_item(const intVector *v, size_t index) { //vozvrashaet index-element
	if (index > (v->size - 1))	return NULL;
	else {
		int i = index;
		int x = v->data[i];
		return x;
	}
}

void int_vector_set_item(intVector *v, size_t index, int item) { //prisvaivaet index-elementu zna4enie item
	if (!(index > (v->size - 1))) v->data[index] = item;
}

int int_vector_shrink_to_fit(intVector *v) { //umen'shaet emkost' do razmera
	v = realloc(v, v->size);
	if (v->capacity == v->size) return 0;
	else return -1;
}

int int_vector_reserve(intVector *v, size_t new_capacity) { //menyaet emkost'
	if (new_capacity <= v->capacity) return -1;
	else {
		v = realloc(v, new_capacity);
		v->capacity = new_capacity;
		return 0;
	}
}

int int_vector_resize(intVector *v, size_t new_size) { //menyaet razmer
	int x = 0;
	if (v->size > new_size) {
		v->size = new_size;
		x = int_vector_shrink_to_fit(v);
	}
	else {
		x = int_vector_reserve(v, new_size);
		for (int i = v->size; i < new_size; i++) {
			//x = int_vector_push_back(v, 0);
			v->data[i] = 0;
			v->size++;
		}
		v->size = new_size;
	}
	return x;
}