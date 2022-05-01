#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct String {
  // Holds the string data with nullterm
  char* str;

  // Private

  // Number of chars in string (do not modify)
  size_t str_size;

  // Size of the buffer (do not modify)
  size_t buf_size;
};

typedef struct String String;

void _string_set_nullterm(String* s) {
  s->str[s->buf_size - 1] = '\0';
}

void _string_resize(String* s) {
  s->str = (char*)realloc((void*)s->str, s->buf_size);
}

void _string_alloc(String* s) {
  s->str = (char*)malloc(s->buf_size);
}

String string_init(const char* initial_str) {
  size_t initial_size = strlen(initial_str);
  
  String os;
  
  os.str_size = initial_size;
  os.buf_size = initial_size + 1;
  
  _string_alloc(&os);

  memcpy(os.str, initial_str, initial_size);
  _string_set_nullterm(&os);

  return os;
}

void string_free(const String* str) {
  free(str->str);
}

// Returns a pointer to that part of the string
char* string_get_char(String* s, size_t index) {
  return &(s->str[index]);
}

// Get a pointer to the last char of the string
char* string_get_last_char(String* s) {
  return &(s->str[s->str_size - 1]);
}

// Get a pointer to the first char of the string
char* string_get_first_char(String* s) {
  return &(s->str[0]);
}

size_t string_get_length(String* s) {
  return s->str_size;
}

// Append a char to the string
size_t string_append(String* s, char c) {
  // Add one to both sizes
  s->str_size += 1;
  s->buf_size += 1;

  // Resize the string
  _string_resize(s);

  // Set the last char of the str && set the new nullterm
  *string_get_last_char(s) = c;
  _string_set_nullterm(s);

  return string_get_length(s);
}

size_t string_append_cstr(String* s, const char* st) {
  size_t old_size = string_get_length(s);
  
  size_t st_size = strlen(st);
  s->str_size += st_size;
  s->buf_size += st_size;

  _string_resize(s);

  memcpy(string_get_char(s, old_size), st, st_size);
  _string_set_nullterm(s);

  return string_get_length(s);
}

size_t string_append_string(String* s, const String* st) {
  return string_append_cstr(s, st->str);
}

// Erases a char at the specified position
void string_erase(String* s, size_t pos) {
  memcpy(s->str + pos, s->str + pos + 1, s->str_size - pos);
  
  s->str_size -= 1;
  s->buf_size -= 1;
  
  _string_resize(s);
  _string_set_nullterm(s);
}

void string_erase_range(String* s, size_t pos, size_t length) {
    memcpy(s->str + pos, s->str + pos + length, s->str_size - pos - length);
    
    s->str_size -= length;
    s->buf_size -= length;
    
    _string_resize(s);
    _string_set_nullterm(s);
}