#include <stdio.h>
#include "int_vector.h"

int main()
{
	int x;
	printf ("Input capacity: ");
	scanf ("%d", &x);		
	intVector *a;
	a = int_vector_new (x);
	printf ("Size: %zd\n", a->size);
	if (a->size == 0) {
		printf ("Size_t size - FAIL\n");
	} else {
		printf ("Size_t size: %zd\n", int_vector_get_size (a));
	}
	printf ("Capacity: %zd\n", a->capacity);
	if (a->capacity == 0) {
		printf ("Size_t capacity - FAIL\n");
	} else {
		printf ("Size_t capacity: %zd\n", int_vector_get_capacity (a));
	}
	
	return 0;
}