#include "tests.h"
#include "block.h"
#include "myers.h"
#include <assert.h>

void run_tests() { test_shortest_path_length(); }

void test_shortest_path_length(void) {
  char *a[5];
  char *b[4];
  int shortest_path_size;
  int **moveset;

  a[0] = "It is important to spell";
  a[1] = "check this dokument. On";
  a[2] = "the other hand, a";
  a[3] = "misspelled word isn't";
  a[4] = "the end of the world.";

  b[0] = "It is important to spell";
  b[1] = "check this document. On";
  b[2] = "the other hand, a";
  b[3] = "misspelled word isn't";

  block *ab = make_block(a, 5);
  block *bb = make_block(b, 4);

  myers *m = myers_make(ab, bb);
  moveset = myers_make_moveset(m);

  // printf("shortest length:%d", m->shortest_length);

  assert(m->shortest_length == 3);
  assert(moveset[3][0] == 4);

  myers_do(m);
}
