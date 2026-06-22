#include "../cpstd/rand.h"
#include "../cpstd/vector.h"
#include "../cpstd/strings.h"

#include <stdint.h>
#include <stdio.h>

int main(void) {
    string *s1 = STRING_INITIALIZER;
    const char *msg = "World";
    string *s2 = string_create_fmt("%s, %s!", "Hello", msg);

    string_cpy(s1, s2);
    string_destroy(s2);
    s2 = string_create("Hallo, World!");

    if (string_cmp(s1, s2)) {
        printf("Equal\n");
    }

    printf("%c\n", string_cget(s1, 12));
    printf(STRING_FMT"\n", STRING_ARG(s1));
}
