#include <string.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} intVector;

intVector* int_vector_new (size_t initial_size);
size_t int_vector_get_capacity (const intVector *v);
size_t int_vector_get_size (const intVector *v);
intVector* int_vector_copy (const intVector *v)
void int_vector_free (intVector *v);