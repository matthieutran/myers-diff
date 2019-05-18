/* Diff Program written in C based on the Myer's Algorithm explained in
 * https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/
 */

#include "myers.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  run_tests();

  /*
  int hi[] = {1, 2, 3, 4, 5};
  int hi2[] = {1, 2};

  int **test = malloc(sizeof(hi) * 5);
  test[1] = hi;
  test[2] = hi2;

  for (int i = 0; i < 5; i++) {
    printf("%d", test[1][i]);
  }

  for (int i = 0; i < 2; i++) {
    printf("%d", test[2][i]);
  }*/

  return 0;
}
