#include "myers.h"
#include <stdlib.h>

myers *make_myers(char **lines1, char **lines2, int amt1, int amt2) {
  myers *m = malloc(sizeof(myers));
  m->lines1 = lines1;
  m->lines2 = lines2;
  m->lines1_amt = amt1;
  m->lines2_amt = amt2;

  return m;
}

int **myers_make_moveset(myers *m) { return NULL; }

void myers_backtrack(myers *m) {}

edit *myers_gen_edits(myers *m) { return NULL; }

void myers_print(myers *m, edit *edits) {}
