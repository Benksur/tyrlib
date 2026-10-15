#ifndef _TYRLIB_ARENA_H
#define _TYRLIB_ARENA_H

#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <tyrlib/types.h>
#include <unistd.h>

typedef struct tyr_arena tyr_arena;

tyr_arena *tyr_arena_create(size_t capacity);
void tyr_arena_destroy(tyr_arena *arena);

#endif
