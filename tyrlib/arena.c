#include <tyrlib/arena.h>

struct tyr_arena {
  char *base_ptr;
  size_t capacity;
  size_t size;
  size_t offset;
};

// POSIX only womp womp
#define PAGE_SIZE ((size_t)sysconf(_SC_PAGESIZE))

tyr_arena *tyr_arena_create(size_t capacity) {
  tyr_arena *arena = (tyr_arena *)malloc(sizeof(tyr_arena));
  if (!arena)
    return NULL;

  capacity = (capacity + PAGE_SIZE - 1) / PAGE_SIZE * PAGE_SIZE;

  void *block =
      mmap(NULL, capacity, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (block == MAP_FAILED) {
    free(arena);
    return NULL;
  }

  arena->base_ptr = (char *)block;
  arena->capacity = capacity;
  arena->size = 0;
  arena->offset = 0;

  return arena;
}

void *tyr_arena_alloc(tyr_arena *arena, size_t size) {}
