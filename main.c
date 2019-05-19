/* Diff Program written in C based on the Myer's Algorithm explained in
 * https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/
 * by James Coglan
 */

#include "block.h"
#include "myers.h"
#include "tests.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // run_tests();

  char *old[BLOCK_SIZE];
  int old_lines = block_from_file(old, argv[1]);

  char *new[BLOCK_SIZE];
  int new_lines = block_from_file(new, argv[2]);

  block *old_block = block_make(old, old_lines);
  block *new_block = block_make(new, new_lines);

  myers *m = myers_make(old_block, new_block);

  myers_do(m);

  return 0;
}
