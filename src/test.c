#include "../cpstd/cpvec.h"

#include <stdio.h>

#define LEN 10

int main(void) {
    int *arr = vec_init(arr, 10);

    for (int i = 0; i < 6; i++) {
        vec_push(arr, i * i);
    }

    foreach_vec(it, arr) {
       printf("%d ", *it);
    }

    vec_destroy(arr);
}
