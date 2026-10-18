#include <string.h>
#include <tyrlib/strings.h>

bool tyr_str_has_suffix(const char *s, const char *suffix) {
  if (s == NULL || suffix == NULL)
    return false;

  if (suffix[0] == '\0')
    return true;

  size_t s_len = strlen(s);
  size_t suffix_len = strlen(suffix);

  if (suffix_len > s_len)
    return false;

  return strcmp(s + s_len - suffix_len, suffix) == 0;
}
