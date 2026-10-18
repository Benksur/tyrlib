#ifndef _TYRLIB_STRINGS_H
#define _TYRLIB_STRINGS_H

#include <stdbool.h>
#include <stddef.h>

bool tyr_str_contains(const char *s, const char *substr);
bool tyr_str_contains_any(const char *s, const char *chars);

bool tyr_str_has_prefix(const char *s, const char *prefix);
bool tyr_str_has_suffix(const char *s, const char *suffix);

int tyr_str_count(const char *s, const char *substr);

bool tyr_str_equal(const char *s, const char *t);
bool tyr_str_equal_fold(const char *s, const char *t);

int tyr_str_index(const char *s, const char *substr);
int tyr_str_last_index(const char *s, const char *substr);

bool tyr_str_cut(const char *s, const char *sep, char **before, char **after);
bool tyr_str_cut_prefix(const char *s, const char *prefix, char **after);
bool tyr_str_cut_suffix(const char *s, const char *suffix, char **before);

char *tyr_str_trim(const char *s, const char *cutset);
char *tyr_str_trim_prefix(const char *s, const char *prefix);
char *tyr_str_trim_suffix(const char *s, const char *suffix);
char *tyr_str_trim_space(const char *s);

char *tyr_str_replace(const char *s, const char *old, const char *repl,
                      size_t n);
char *tyr_str_replace_all(const char *s, const char *old, const char *repl);

char *tyr_str_join(const char **strs, size_t count, const char *sep);

char *tyr_str_to_lower(const char *s);
char *tyr_str_to_upper(const char *s);

char *tyr_str_repeat(const char *s, size_t count);
char *tyr_str_clone(const char *s);

char **tyr_str_split(const char *s, const char *sep, size_t *count);
#endif
