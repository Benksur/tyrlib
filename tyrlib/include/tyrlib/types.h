typedef union {
  long long ll;
  long double ld;
  void *ptr;
  void (*func_ptr)(void);
} tyr_max_align_t;

#define TYR_MAX_ALIGNMENT sizeof(tyr_max_align_t)
