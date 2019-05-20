#ifndef block_h
#define block_h

#include "line.h"
#include <stdlib.h>

typedef struct block block;
struct block {
  line **lines;      // block content
  size_t line_count; // # of lines in the block
};

/* returns a newly allocated block struct */
block *block_make(line **lines, size_t line_count);

/* Create block with file contents */
block *block_from_file(char *filename);

#endif
