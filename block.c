#include "block.h"
#include <stdlib.h>

block *make_block(char **text, int lines) {
  block *b = malloc(sizeof(block));
  b->text = text;
  b->lines = lines;

  return b;
}
