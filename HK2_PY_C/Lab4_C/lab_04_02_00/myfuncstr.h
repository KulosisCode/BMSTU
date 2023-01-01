#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

size_t blank_words_remove(shortstrings_t a, size_t n);
size_t dup_words_remove(shortstrings_t a, size_t n);
size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims);
int count(shortstring_t str, shortstring_t word, shortstring_t delims);
#endif