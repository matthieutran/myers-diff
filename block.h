#ifndef block_h
#define block_h

#include <stdlib.h>

typedef struct block block;
struct block {
  char **text;  // block content
  size_t lines; // # of lines in the block
};

/* returns a newly allocated block object */
block *block_make(char **text, size_t lines);

#endif
