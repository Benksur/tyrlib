#include <tyrlib/arena.h>

// credit to https://github.com/leiapollos

struct tyr_arena {
  char *base;
  size_t capacity;
  size_t size;
  size_t offset;
};

// POSIX only womp womp
#define PAGE_SIZE ((size_t)sysconf(_SC_PAGESIZE))
#define ALIGN_TO_PAGE(size) ((size + PAGE_SIZE - 1) / PAGE_SIZE * PAGE_SIZE)

tyr_arena *tyr_arena_create(size_t capacity) {
  tyr_arena *arena = (tyr_arena *)malloc(sizeof(tyr_arena));
  if (!arena)
    return NULL;

  capacity = ALIGN_TO_PAGE(capacity);

  void *block =
      mmap(NULL, capacity, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (block == MAP_FAILED) {
    free(arena);
    return NULL;
  }

  arena->base = (char *)block;
  arena->capacity = capacity;
  arena->size = 0;
  arena->offset = 0;

  return arena;
}

void *tyr_arena_alloc(tyr_arena *arena, size_t size) {
  if (!arena || size == 0)
    return NULL;

  const size_t alignment = TYR_MAX_ALIGNMENT;

  if (arena->offset > SIZE_MAX - (alignment - 1))
    return NULL;

  size_t aligned_offset = (arena->offset + alignment - 1) & ~(alignment - 1);

  if (aligned_offset > arena->capacity ||
      size > arena->capacity - aligned_offset)
    return NULL;

  size_t new_offset = aligned_offset + size;

  if (new_offset > arena->size) {
    size_t new_size_target = ALIGN_TO_PAGE(new_offset);

    if (new_size_target > arena->capacity) {
      new_size_target = arena->capacity;
    }

    size_t size_to_commit = new_size_target - arena->size;
    void *commit_start_addr = arena->base + arena->size;

    if (mprotect(commit_start_addr, size_to_commit, PROT_READ | PROT_WRITE) !=
        0) {
      return NULL;
    }

    arena->size = new_size_target;
  }

  void *memory = arena->base + arena->offset;
  arena->offset = new_offset;

  return memory;
}

void tyr_arena_reset(tyr_arena *arena) { arena->offset = 0; }

void tyr_arena_destroy(tyr_arena *arena) {
  munmap(arena->base, arena->capacity);
  free(arena);
}
