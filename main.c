/* Diff Program written in C based on the Myer's Algorithm explained in
 * https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/
 */

#include "myers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *a[5];
  char *b[4];
  int shortest_path_size;

  // TODO: get text from file
  a[0] = "It is important to spell";
  a[1] = "check this dokument. On";
  a[2] = "the other hand, a";
  a[3] = "misspelled word isn't";
  a[4] = "the end of the world.";

  b[0] = "It is important to spell";
  b[1] = "check this document. On";
  b[2] = "the other hand, a";
  b[3] = "misspelled word isn't";

  myers *m = myers_make(a, b, 5, 4);
  myers_process_diff(m);

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