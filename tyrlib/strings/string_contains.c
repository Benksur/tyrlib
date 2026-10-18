#include <string.h>
#include <tyrlib/strings.h>

bool tyr_str_contains(const char *s, const char *substr) {
  if (s == NULL || substr == NULL)
    return false;

  return strstr(s, substr) != NULL;
}
