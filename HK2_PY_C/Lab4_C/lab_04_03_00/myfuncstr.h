#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims);
void change_word(shortstring_t st);
size_t revers_word(shortstrings_t words_arr, shortstring_t new_str, size_t n);
#endif