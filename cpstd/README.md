# CPSTD
## About
CPSTD is a standard library I made on my own including various data structures or features which C and its own std does not have.
## Contents
### arena.h
Very simple arena allocator

Example:
```c
#include <cpstd/arena.h>

int main() {
    mem_arena *arena = arena_create(KiB(1));

    int *a = arena_alloc(arena, sizeof(int));
    float *b = arena_alloc(arena, sizeof(float));
    char *str = arena_calloc(arena, 3);

    // Do sth with variables
    *a = 5;
    *b = 20;
    str[0] = 'H';
    str[1] = 'i';

    arena_destroy(arena);
}
```

### bitarr.h
Bit array data structure

Example:
```c
#include <cpstd/bitarr.h>

#include <stdbool.h>

#define SIZE 3

int main() {
    uint8_t *arr = bit_arr_init(SIZE);

    for (int i = 0; i < SIZE; i++) {
        bit_arr_clear(arr, i);
    }
    bit_arr_set(arr, 1);

    bool value = (bool)bit_arr_get(arr, 1);

    bit_arr_destroy(arr);
}
```

### hashmap.h
Hashmap data structure

Example:
```c
#include <cpstd/hashmap.h>

typedef struct {
    int key;
    char *value;
} entry;

int main() {
    entry *map = hm_init(map, 10);

    hm_put(map, 583, "Hello World");
    hm_put(map, 19, "Lorem ipsum");

    char **str = hm_get(map, 583);

    hm_remove(map, 19);

    hm_destroy(map);
}
```

### mathplus.h
Provides f.e. linear algebra calculations, useful for game development and graphics programming

Example:
```c
#include <cpstd/mathplus.h>

int main() {
    vec2f player = VEC2F(19.0f, 284.0f);
    vec2f target = VEC2F(0.0f, 81.0f);

    if (vec2f_dist(player, target) < 10.0f) {
        // Do something
    }
}
```

### queue.h
Queue data structure

Example:
```c
#include <cpstd/queue.h>

int main() {
    int *queue = queue_init(queue, 10);

    queue_push(queue, 10);
    queue_push(queue, 1083);
    queue_push(queue, 98);

    int val = queue_pop(queue);

    queue_destroy(queue);
}
```

### rand.h
Better random number generation with PCG

Example:
```c
#include <cpstd/rand.h>

#include <stdbool.h>

int main() {
    pcg_rand_seed();

    int random = pcg_rand() % 101;
    float value = pcg_randf_range(10.0f, 100.0f);
    float probability_percent = 18.5f;
    bool passed = (bool)pcg_rand_percent(PERCENT(probability_percent));
}
```

### strings.h
String data type with more possibilities 

Example:
```c
#include <cpstd/strings.h>

int main(void) {
    string *s1 = STRING_INITIALIZER;
    const char *msg = "World";
    string *s2 = string_create_fmt("%s, %s!", "Hello", msg);

    string_cpy(s1, s2);

    char value = string_cget(s1, 2);

    printf("String contains: " STRING_FMT "\n", STRING_ARG(s1));
}
```

### vector.h
Vector data structure 

Example:
```c
#include <cpstd/vector.h>

int main(void) {
    int *v = vec_init(v, 10);

    vec_push(v, 18);
    vec_push(v, 88);
    vec_push_front(v, 36);
    vec_pop(v);

    int value = v[0];

    vec_destroy(v);
}
```
