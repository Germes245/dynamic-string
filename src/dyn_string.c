#include <string.h>
#include <stdlib.h>
#include "dyn_string.h"

dyn_string dyn_string_init(char* string){
    dyn_string result;
    result.size = strlen(string) + 1;
    result.string = malloc(result.size);
    memcpy(result.string, string, result.size);
    return result;
}

void dyn_string_rewrite(dyn_string *string, char* new_string){
    string->size = strlen(new_string) + 1;
    string->string = realloc(string->string, string->size);
    memcpy(string->string, new_string, string->size);
}

void dyn_string_free(dyn_string *string){
    if(string->size){
        free(string->string);
        string->size = 0;
    }
}