#include "tests.h"
#include "block.h"
#include "line.h"
#include "myers.h"
#include <assert.h>
#include <stdlib.h>

void run_tests() { test_shortest_path_length(); }

void test_shortest_path_length(void) {
  line **a = malloc(sizeof(line) * 5);
  line **b = malloc(sizeof(line) * 4);
  int **moveset;

  a[0] = line_make("It is important to spell", 1);
  a[1] = line_make("check this dokument. On", 2);
  a[2] = line_make("the other hand, a", 3);
  a[3] = line_make("misspelled word isn't", 4);
  a[4] = line_make("the end of the world.", 5);

  b[0] = line_make("It is important to spell", 1);
  b[1] = line_make("check this document. On", 2);
  b[2] = line_make("the other hand, a", 3);
  b[3] = line_make("misspelled word isn't", 4);

  block *ab = block_make(a, 5);
  block *bb = block_make(b, 4);

  myers *m = myers_make(ab, bb);
  moveset = myers_make_moveset(m);

  // printf("shortest length:%d", m->shortest_length);

  assert(m->shortest_length == 3);
  assert(moveset[3][0] == 4);
}
