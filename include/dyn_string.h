#include <stddef.h>

typedef struct{
    char* string;
    size_t size;
} dyn_string;

dyn_string dyn_string_init(char* string);
void dyn_string_rewrite(dyn_string *string, char* new_string);
void dyn_string_free(dyn_string *string);