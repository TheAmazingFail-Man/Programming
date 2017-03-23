#include <stdio.h>
#include "int_vector.h"

int main() {
	int x, item, i, j, new_size;
	printf("Input capacity: ");
	scanf("%d", &x);
	intVector *a;
	a = int_vector_new (x);
	printf("\nSize: %zd\n", int_vector_get_size (a));
	printf("Capacity: %zd\n", int_vector_get_capacity (a));

	intVector *b;
	b = int_vector_copy (a);
	
	printf("\nInput element: ");
	scanf("%d", &item);
	x = int_vector_push_back (a, item);
	printf("\nVector a (+ 1 element): ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item (a, i);
		printf("%d ", j);
	}
	printf("\nSize: %zd\n", int_vector_get_size (a));
	printf("Capacity: %zd\n", int_vector_get_capacity (a));
	int_vector_pop_back (a);
	printf("\nVector a (- 1 element): ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item (a, i);
		printf("%d ", j);
	}
	printf("\nSize: %zd\n", int_vector_get_size (a));
	printf("Capacity: %zd\n", int_vector_get_capacity (a));
	
	printf("\nInput new capacity: ");
	scanf("%d", &new_size);
	x = int_vector_reserve (a, new_size);
	printf("\nInput new size: ");
	scanf("%d", &new_size);
	x = int_vector_resize (a, new_size);
	printf("\nVector a: ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item (a, i);
		printf("%d ", j);
	}
	
	return 0;
}
