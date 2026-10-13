#include <tyrlib/arena.h>

struct tyr_arena {
  char *base_ptr;
  size_t capacity;
  size_t size;
  size_t offset;
};

tyr_arena *tyr_arena_create(size_t capacity) {
  tyr_arena *arena = (tyr_arena *)malloc(sizeof(tyr_arena));
  if (!arena)
    return NULL;

  arena->base_ptr = (char *)block;
  arena->capacity;

  return arena;
}
