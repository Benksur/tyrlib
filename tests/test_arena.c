
#include "test.h"
#include <tyrlib/arena.h>

static void test_create_destroy(void) {
  tyr_arena *arena = tyr_arena_create(1024);
  TEST_ASSERT(arena != NULL);
  tyr_arena_destroy(arena);
}

static void test_arena_alloc(void) {
  tyr_arena *arena = tyr_arena_create(1024);
  TEST_ASSERT(arena != NULL);

  void *ptr = tyr_arena_alloc(arena, 64);
  TEST_ASSERT(ptr != NULL);

  tyr_arena_destroy(arena);
}

int main(void) {
  test_create_destroy();
  test_arena_alloc();

  return EXIT_SUCCESS;
}
