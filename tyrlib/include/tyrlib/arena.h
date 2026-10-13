#ifndef _TYRLIB_ARENA_H
#define _TYRLIB_ARENA_H

#include <stddef.h>
#include <stdlib.h>

typedef struct tyr_arena tyr_arena;

tyr_arena *tyr_arena_create(size_t capacity);
void tyr_arena_destroy(tyr_arena *arena);

#endif
