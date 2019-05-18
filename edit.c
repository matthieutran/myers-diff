#include "edit.h"
#include "utils.h"
#include <stdlib.h>

char *edit_text(edit *e, block *block1, block *block2) {
  return e->old_line ? block1->text[e->old_line] : block2->text[e->new_line];
}

edit *make_edit(int operation, int old_line, int new_line, block *b1,
                block *b2) {
  edit *e = malloc(sizeof(edit));
  e->operation = operation;
  e->old_line = old_line;
  e->new_line = new_line;
  e->text = edit_text;

  return e;
}

void edit_print(edit *e) {}
