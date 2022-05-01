## libstr a string library for C

To install
---
``` bash
git clone https://github.com/zach-pike/libstr.git
cd libstr
make build
sudo make install
```

To use
---
Link with -lstr and set LD_LIBRARY_PATH=/usr/local/lib when running
``` c
#include <stdio.h>
#include <stdlib.h>
#include <libstr/libstr.h>

int main() {
    String s = string_init("Hello");
    string_append_cstr(&s, " World");

    printf("%s\n", string_get_char(&s, 0));

    string_free(&s);
}
```