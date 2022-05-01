#include "strlib.h"
#include <stdio.h>

int main() {
    String s = string_init("Hello world!");
    string_erase_range(&s, 1, 1);


    printf("%s\n", string_get_first_char(&s));


    string_free(&s);
    return 0;
}