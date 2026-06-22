#include "../cpstd/rand.h"
#include "../cpstd/vector.h"
#include "../cpstd/strings.h"

#include <stdint.h>
#include <stdio.h>

int main(void) {
    string *s1 = STRING_INITIALIZER;
    const char *msg = "World";
    string *s2 = str_create_fmt("%s, %s!", "Hello", msg);

    str_cpy(s1, s2);

    printf("%c\n", str_cget(s1, 12));
    printf(STR_FMT"\n", STR_ARG(s1));
}
