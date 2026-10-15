
#include "test.h"
#include <tyrlib/arena.h>

static void test_create_destroy(void) {
  tyr_arena *arena = tyr_arena_create(1024);

  TEST_ASSERT(arena == NULL);

  tyr_arena_destroy(arena);
}

int main(void) {
  test_create_destroy();

  return EXIT_SUCCESS;
}
