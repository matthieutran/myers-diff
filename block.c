#include "block.h"
#include "line.h"
#include "string.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


block *block_make(line **lines, size_t line_count) {
  block *b = malloc(sizeof(block));
  b->lines = lines;
  b->line_count = line_count;

  return b;
}

char buf[BUF_SIZE];

block *block_from_file(char *filename) {
  line **lines = malloc(sizeof(line) * BUF_SIZE);
  int line_count = 0;

  FILE *file = process_file(filename);

  while (!feof(file) && fgets(buf, BUF_SIZE, file) != NULL) {
    lines[line_count++] = line_make(strdup(buf), strlen(buf));
  }

  fclose(file);

  return block_make(lines, line_count);
  ;
}
