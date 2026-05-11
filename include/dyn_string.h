typedef char* dyn_string;

dyn_string dyn_string_init(char* string);
dyn_string dyn_string_rewrite(dyn_string string, char* new_string);
void dyn_string_free(dyn_string string);