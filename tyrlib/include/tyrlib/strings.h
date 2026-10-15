#ifndef _TYRLIB_STRINGS_H
#define _TYRLIB_STRINGS_H

#include <stdbool.h>

bool tyr_str_contains(const char *s, const char *substr);
bool tyr_str_contains_rune(const char *s, int c);
bool tyr_str_has_prefix(const char *s, const char *prefix);
bool tyr_str_has_suffix(const char *s, const char *suffix);

bool tyr_str_cut(const char *input, const char *del, char **before,
                 char **after);

#endif
