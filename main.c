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

  block *old_block = block_from_file(argv[1]);
  block *new_block = block_from_file(argv[2]);

  myers *m = myers_make(old_block, new_block);

  myers_do(m);

  return 0;
}
