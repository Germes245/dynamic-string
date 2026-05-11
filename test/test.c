#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char* string = dyn_string_init("shya");
    printf("%d\n", string);
    printf("%s\n", string);
    string = dyn_string_rewrite(string, "sha");
    printf("%d\n", string);
    printf("%s\n", string);
    dyn_string_free(&string);
    printf("%s\n%d\n", string, string);
    return 0;
}