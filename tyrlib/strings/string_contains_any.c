#include <stdint.h>
#include <string.h>
#include <tyrlib/strings.h>

bool tyr_str_contains_any(const char *s, const char *chars) {
  if (s == NULL || chars == NULL || s[0] == '\0' || chars[0] == '\0')
    return false;

  if (chars[1] == '\0')
    return strchr(s, chars[0]) != NULL;

  uint8_t lut[32] = {0};

  for (size_t i = 0; chars[i] != '\0'; i++)
    lut[(unsigned char)chars[i] >> 3] |=
        (uint8_t)(1u << ((unsigned char)chars[i] & 7));

  for (size_t i = 0; s[i] != '\0'; i++)
    if (lut[(unsigned char)s[i] >> 3] & (1u << ((unsigned char)s[i] & 7)))
      return true;

  return false;
}
