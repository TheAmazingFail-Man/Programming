#include <string.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} intVector;

intVector* int_vector_new (size_t initial_capacity);
size_t int_vector_get_capacity (const intVector *v);
size_t int_vector_get_size (const intVector *v);
intVector* int_vector_copy (const intVector *v);
int int_vector_push_back (intVector *v, int item);
void int_vector_pop_back (intVector *v);
int int_vector_get_item(const intVector *v, size_t index);
void int_vector_set_item(intVector *v, size_t index, int item);
int int_vector_shrink_to_fit(intVector *v);
int int_vector_reserve(intVector *v, size_t new_capacity);
int int_vector_resize(intVector *v, size_t new_size);
void int_vector_free (intVector *v);