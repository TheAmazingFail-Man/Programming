#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "int_vector.h"

int main() {
	int x, item, i, j, new_size;
	printf("Vvedite razmer: ");
	scanf("%d", &x);
	intVector *a;
	a = int_vector_new(x);
	printf("\n Emkost': %zd", int_vector_get_capacity(a));

	intVector *b;
	b = int_vector_copy(a);

	printf("\n Vvedite element: ");
	scanf("%d", &item);
	x = int_vector_push_back(a, item);
	printf("\n Vector a (posle dobavleniya elementa): ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item(a, i);
		printf("%d  ", j);
	}
	printf("\n Razmer: %zd\n", int_vector_get_size(a));

	int_vector_pop_back(a);
	printf("\n Vector a (posle udaleniya elementa): ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item(a, i);
		printf("%d  ", j);
	}
	printf("\n Razmer: %zd\n", int_vector_get_size(a));

	printf("\n Vvedite noviy razmer: ");
	scanf("%d", &new_size);
	x = int_vector_resize(a, new_size);
	printf("\n Vector a: ");
	for (i = 0; i < a->size; i++) {
		j = int_vector_get_item(a, i);
		printf("%d  ", j);
	}
	printf("\n Razmer: %zd\n", int_vector_get_size(a));
	printf("\n Emkost': %zd\n", int_vector_get_capacity(a));
	//return 0;
	_getch();
}