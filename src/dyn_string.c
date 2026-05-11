#include <string.h>
#include <stdlib.h>

char* dyn_string_init(char string[]){
    size_t size = strlen(string) + 1;
    char* result = malloc(size);
    memcpy(result, string, size);
    return result;
}

char* dyn_string_rewrite(char* string, char* new_string){
    size_t size = strlen(new_string) + 1;
    string = realloc(string, size);
    memcpy(string, new_string, size);
    return string;
}

void dyn_string_free(char *string[]){
    //printf("dyn_string_free\n");
    if(*string){
        free(*string);
        *string = 0;
    }
}