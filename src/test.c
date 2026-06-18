#include "../cpstd/cpbitarr.h"

#include <stdio.h>

#define LEN 10

int main(void) {
    uint8_t *arr = bit_arr_init(LEN);

    for (int i = 1; i < 3 + 1; i++) {
        bit_arr_set(arr, i);
    }

    for (int i = 0; i < LEN; i++) {
        printf("%d ", bit_arr_get(arr, i));
    }

    printf("\n");
    for (int i = 0; i < (LEN + 7) / 8; i++) {
        printf("%d ", arr[i]);
    }

    bit_arr_destroy(arr);
}
