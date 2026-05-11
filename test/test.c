#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dyn_string_init(char string[]){
    size_t size = strlen(string) + 1;
    char* result = malloc(size);
    memcpy(result, string, size);
    return result;
}

void dyn_string_rewrite(char *string[], char new_string[]){
    printf("dyn_string_rewrite\n");
    size_t size = strlen(new_string) + 1;
    *string = realloc(*string, size);
    memcpy(string, new_string, size);
    //return string;
}

void dyn_string_free(char *string[]){
    printf("dyn_string_free\n");
    if(*string){
        free(*string);
        *string = 0;
    }
}

int main(){
    char* string = dyn_string_init("shya");
    printf("%d\n", string);
    printf("%s\n", string);
    dyn_string_rewrite(&string, "sha");
    printf("%d\n", string);
    printf("%s\n", string);
    dyn_string_free(&string);
    printf("%s\n%d\n", string, string);
    return 0;
}