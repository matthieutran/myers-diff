#include "edit.h"
#include "utils.h"
#include <stdlib.h>

char *edit_text(edit *e) {
  return e->old_block != NULL ? e->old_block->text[e->old_line]
                              : e->new_block->text[e->new_line];
}

edit *edit_make(int operation, block *old_block, block *new_block, int old_line,
                int new_line) {
  edit *e = malloc(sizeof(edit));
  e->operation = operation;
  e->old_block = old_block;
  e->new_block = new_block;
  e->old_line = old_line;
  e->new_line = new_line;

  e->text = edit_text;

  return e;
}

void edit_print(edit *e) {}
