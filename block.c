#include "block.h"
#include <stdlib.h>

block *block_make(char **text, size_t lines) {
  block *b = malloc(sizeof(block));
  b->text = text;
  b->lines = lines;

  return b;
}
