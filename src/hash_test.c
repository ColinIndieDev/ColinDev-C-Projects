#include "../cpstd/cphash.h"

// HM_CREATE_ENTRY(STRING_KEY, int, person)

typedef struct {
    HM_STRING_KEY key;
    char *real_key;
    int value;
} person;

int main(void) {
    person *persons = hm_init(persons, 10);

    size_t key = hm_string_to_key("Jeff");
    hm_put(persons, key, 67);
    hm_get_element(persons, key)->real_key = "Jeff";

    key = hm_string_to_key("Tom");
    hm_put(persons, key, 30);
    hm_get_element(persons, key)->real_key = "Tom";

    key = hm_string_to_key("Luca");
    hm_put(persons, key, 19);
    hm_get_element(persons, key)->real_key = "Luca";

    key = hm_string_to_key("Jerry");
    hm_put(persons, key, 80);
    hm_get_element(persons, key)->real_key = "Jerry";

    hm_remove(persons, hm_string_to_key("Jerry"));

    char *search = "Jeff";
    int *age = hm_get(persons, hm_string_to_key(search));

    if (age) {
        printf("Found %s with age of %d!\n", search, *age);
    }

    foreach_hm(person, it, persons) {
        if (hm_it_exist(persons, it)) {
            printf("Name: %s, Age: %d\n", it->real_key, it->value);
        }
    }

    hm_destroy(persons);
}
