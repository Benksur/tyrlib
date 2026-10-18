#include <string.h>
#include <tyrlib/strings.h>

bool tyr_str_has_prefix(const char *s, const char *prefix) {
  if (s == NULL || prefix == NULL)
    return false;

  if (prefix[0] == '\0')
    return true;

  return strncmp(s, prefix, strlen(prefix)) == 0;
}
