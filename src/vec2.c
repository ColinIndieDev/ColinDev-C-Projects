#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    size_t capacity;
} header_t;

#define vec_init(arr, capacity) vec_init_impl(sizeof(*(arr)), capacity)
void *vec_init_impl(size_t element_size, size_t capacity) {
    assert(capacity > 0);
    header_t *header = malloc(sizeof(header_t) + (element_size * capacity));
    header->size = 0;
    header->capacity = capacity;
    return (void *)(header + 1);
}

void vec_destroy(void *arr) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    free(header);
}

#define vec_push(arr, x)                                                       \
    do {                                                                       \
        __auto_type tmp = (x);                                                 \
        (arr) = vec_push_impl((arr), &tmp, sizeof(*(arr)));                    \
    } while (0)
void *vec_push_impl(void *arr, void *val, size_t element_size) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    if (header->size >= header->capacity) {
        size_t new_capacity = header->capacity * 2;
        header_t *tmp =
            realloc(header, sizeof(header_t) + (element_size * new_capacity));
        assert(tmp);
        header = tmp;
        header->capacity = new_capacity;
    }
    arr = (void *)(header + 1);
    memcpy((char *)arr + (header->size * element_size), val, element_size);
    header->size++;
    return arr;
}

#define vec_push_front(arr, x)                                                 \
    do {                                                                       \
        __auto_type tmp = (x);                                                 \
        (arr) = vec_push_front_impl((arr), &tmp, sizeof(*(arr)));              \
    } while (0)
void *vec_push_front_impl(void *arr, void *val, size_t element_size) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    if (header->size >= header->capacity) {
        size_t new_capacity = header->capacity * 2;
        header_t *tmp =
            realloc(header, sizeof(header_t) + (element_size * new_capacity));
        assert(tmp);
        header = tmp;
        header->capacity = new_capacity;
    }
    arr = (void *)(header + 1);
    memmove(arr + element_size, arr, (header->size * element_size));
    memcpy(arr, val, element_size);
    header->size++;
    return arr;
}

void vec_pop(void *arr) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    assert(header->size > 0);
    header->size--;
}

#define vec_pop_front(arr) vec_pop_front_impl((arr), sizeof(*(arr)))
void vec_pop_front_impl(void *arr, size_t element_size) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    assert(header->size > 0);
    memmove(arr, arr + element_size, (header->size - 1) * element_size);
    header->size--;
}

#define vec_delete(arr, i) vec_delete_impl((arr), (i), sizeof(*(arr)))
void vec_delete_impl(void *arr, size_t i, size_t element_size) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    assert(0 <= i && i < header->size && header->size > 0);
    memmove(arr + (i * element_size), arr + ((i + 1) * element_size),
            (header->size - i - 1) * element_size);
    header->size--;
}

size_t vec_size(void *arr) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    return header->size;
}

void *vec_begin(void *arr) {
    assert(arr);
    return arr;
}

#define vec_end(arr) vec_end_impl((void *)(arr), sizeof(*(arr)))
void *vec_end_impl(void *arr, size_t element_size) {
    assert(arr);
    header_t *header = (header_t *)arr - 1;
    return arr + (header->size * element_size);
}

#define foreach_vec(type, it, arr)                                             \
    for (type * (it) = arr; (it) != vec_end(arr); ++(it))

typedef struct {
    int age;
    char *name;
} person;

int main(void) {
    person *arr = vec_init(arr, 1);
    vec_push(arr, ((person){.age = 67, .name = "John"}));
    vec_push(arr, ((person){.age = 24, .name = "Marie"}));
    vec_push(arr, ((person){.age = 30, .name = "Tom"}));
    vec_pop(arr);
    vec_push_front(arr, ((person){.age = 19, .name = "Timmy"}));
    vec_push_front(arr, ((person){.age = 42, .name = "Alex"}));
    vec_pop_front(arr);
    vec_delete(arr, 1);

    printf("Array size: %lu\n", vec_size(arr));

    foreach_vec(person, p, arr) { printf("%s | %d\n", p->name, p->age); }

    vec_destroy(arr);
}
