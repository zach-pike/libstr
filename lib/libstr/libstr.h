#ifndef __STRLIB_H
#define __STRLIB_H

#include <stdint.h>
#include <stdlib.h>


struct String {
  char* str;

  // Number of chars in string
  size_t str_size;

  // Size of the buffer
  size_t buf_size;
};
typedef struct String String;

// Initialize a string
struct String string_init(const char* initialStr);

// Free a string
void string_free(const struct String* str);

// Get a pointer to a char in the string
char* string_get_char(struct String* s, size_t index);

// Get a pointer to the last char of the string
char* string_get_last_char(struct String* s);

// Get a pointer to the first char of the string
char* string_get_first_char(struct String* s);


// Returns the size of the string
size_t string_get_size(struct String* s);


// Append functions

// Append a char to the end of the string
size_t string_append(struct String* str, char c);

// Append a string a C string to the end of the string
size_t string_append_cstr(struct String* str, const char* st);

// Append a string to the end of the string
size_t string_append_string(struct String* str, const struct String* st);


// Erase functions

// Erase a char from the string
void string_erase(String* s, size_t pos);

// Erase a range of chars from the string
void string_erase_range(String* s, size_t pos, size_t length);

#endif