#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* dyn_string;

dyn_string dyn_string_init(char* string){
    size_t size = strlen(string) + 1;
    dyn_string result = malloc(size);
    memcpy(result, string, size);
    return result;
}

dyn_string dyn_string_rewrite(dyn_string string, char* new_string){
    size_t size = strlen(new_string) + 1;
    string = realloc(string, size);
    memcpy(string, new_string, size);
    return string;
}

void dyn_string_free(dyn_string string){
    if(string){
        free(string);
        string = 0;
    }
}

int main(){

    return 0;
}