# C Projects & Libraries

## About
This is my collection of libraries / header files I made entirely in C.
Most of the stuff I wrote before is C++ so I also try to convert it as well into C (in that case CPL is left)

## Projects

### CPSTD

A library I made providing utilities like a random number generator with pcg, arena allocator or data structures
like vectors, chashmaps, queues etc.

```c
// Example code using a header of the library
#include <cpstd/vector.h>

int square_of(int *list, int i) {
    return list[i];
}

int main(void) {
    int *list = vec_init(list, 100);
    for (int i = 0; i < 1001; ++i) {
        vec_push(list, i * i);
    }
    printf(Square of %d is %d\n“, 48, square_of(list, 48));
}
```

See more details [here](cpstd/README.md)
