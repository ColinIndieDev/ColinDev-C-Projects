#pragma once

#include <stddef.h>

typedef struct {
    char *cstr;
    size_t size;
} string;

#define STR_FMT "%.*s"
#define STR_ARG(str) (int)(str)->size, (str)->cstr

#define STRING_INITIALIZER str_create("")

#define str_cstr(str) ((str)->cstr)
#define str_size(str) ((str)->size)

string *str_create(const char *cstr);
string *str_create_fmt(const char *fmt, ...);
void str_destroy(string *str);
void str_cpy(string *dest, string *src);
void str_cset(string *str, size_t i, char c);
char str_cget(string *str, size_t i);
int str_cmp(string *a, string *b);
void str_fmt(string *str, const char *fmt, ...);
