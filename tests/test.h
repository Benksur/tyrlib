#ifndef _TYRLIB_TEST_H
#define _TYRLIB_TEST_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_RESET "\033[0m"
#define TEST_BOLD "\033[1m"
#define TEST_RED "\033[31m"

#define TEST_ASSERT(condition)                                                 \
  do {                                                                         \
    if (!(condition)) {                                                        \
      fprintf(stderr, TEST_BOLD TEST_RED "FAIL:" TEST_RESET " %s:%d: %s\n",    \
              __FILE__, __LINE__, #condition);                                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)

#endif
