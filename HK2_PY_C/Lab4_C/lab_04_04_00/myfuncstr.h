#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

char *my_fgets(shortstring_t str, FILE *f);
size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims);
void strimb(shortstring_t str);
void strime(shortstring_t str);
int isnumber(shortstring_t str);
int isaddress(shortstring_t str);
#endif