#include "test.h"
#include <tyrlib/strings.h>

static void test_contains(void) {
  TEST_ASSERT(tyr_str_contains("hello world", "world"));
  TEST_ASSERT(tyr_str_contains("hello world", "hello"));
  TEST_ASSERT(tyr_str_contains("hello world", "lo wo"));

  TEST_ASSERT(!tyr_str_contains("hello world", "xyz"));
  TEST_ASSERT(!tyr_str_contains("hello", "hello!"));

  TEST_ASSERT(tyr_str_contains("", ""));
  TEST_ASSERT(tyr_str_contains("hello", ""));
  TEST_ASSERT(tyr_str_contains("hello", "hello"));
  TEST_ASSERT(!tyr_str_contains("", "hello"));

  TEST_ASSERT(tyr_str_contains("Hello", "Hell"));
  TEST_ASSERT(!tyr_str_contains("Hello", "hello"));
}

static void test_contains_any(void) {
  TEST_ASSERT(!tyr_str_contains_any("team", "i"));
  TEST_ASSERT(tyr_str_contains_any("fail", "ui"));
  TEST_ASSERT(tyr_str_contains_any("ure", "ui"));
  TEST_ASSERT(tyr_str_contains_any("failure", "ui"));
  TEST_ASSERT(tyr_str_contains_any("hello", "h"));
  TEST_ASSERT(tyr_str_contains_any("hello", "o"));
  TEST_ASSERT(tyr_str_contains_any("hello", "ol"));
  TEST_ASSERT(tyr_str_contains_any("hello", "xyzlo"));
  TEST_ASSERT(!tyr_str_contains_any("hello", "xyz"));

  TEST_ASSERT(!tyr_str_contains_any("foo", ""));
  TEST_ASSERT(!tyr_str_contains_any("", "foo"));
  TEST_ASSERT(!tyr_str_contains_any("", ""));

  TEST_ASSERT(!tyr_str_contains_any(NULL, "foo"));
  TEST_ASSERT(!tyr_str_contains_any("foo", NULL));
  TEST_ASSERT(!tyr_str_contains_any(NULL, NULL));

  TEST_ASSERT(tyr_str_contains_any("hello", "llll"));
  TEST_ASSERT(tyr_str_contains_any("hello", "zzzzlo"));
  TEST_ASSERT(!tyr_str_contains_any("hello", "zzz"));

  TEST_ASSERT(tyr_str_contains_any("hello", "Hh"));
  TEST_ASSERT(!tyr_str_contains_any("hello", "H"));
  TEST_ASSERT(!tyr_str_contains_any("HELLO", "h"));

  TEST_ASSERT(tyr_str_contains_any("aaaaaa", "a"));
  TEST_ASSERT(!tyr_str_contains_any("aaaaaa", "b"));

  TEST_ASSERT(tyr_str_contains_any("\x01", "\x01"));
  TEST_ASSERT(tyr_str_contains_any("\x07", "\x07"));
  TEST_ASSERT(tyr_str_contains_any("\x08", "\x08"));
  TEST_ASSERT(tyr_str_contains_any("\x7f", "\x7f"));
  TEST_ASSERT(tyr_str_contains_any("\x80", "\x80"));
  TEST_ASSERT(tyr_str_contains_any("\xff", "\xff"));
  TEST_ASSERT(!tyr_str_contains_any("\x01", "\x02"));
}

static void test_has_prefix(void) {
  TEST_ASSERT(tyr_str_has_prefix("Gopher", "Go"));
  TEST_ASSERT(!tyr_str_has_prefix("Gopher", "C"));
  TEST_ASSERT(tyr_str_has_prefix("Gopher", ""));

  TEST_ASSERT(!tyr_str_has_prefix("Go", "Gopher"));
}

static void test_has_suffix(void) {
  TEST_ASSERT(tyr_str_has_suffix("Amigo", "o"));
  TEST_ASSERT(!tyr_str_has_suffix("Amigo", "O"));
  TEST_ASSERT(!tyr_str_has_suffix("Amigo", "Ami"));
  TEST_ASSERT(tyr_str_has_suffix("Amigo", ""));
}

int main(void) {
  test_contains();
  test_contains_any();
  test_has_prefix();
  test_has_suffix();
  return EXIT_SUCCESS;
}
