#include "edit.h"
#include "utils.h"
#include <stdlib.h>

char *edit_text(edit *e) {
  return e->old_block ? e->old_block->text[e->line]
                      : e->new_block->text[e->line];
}

edit *edit_make(int operation, block *old_block, block *new_block, int line) {
  edit *e = malloc(sizeof(edit));
  e->operation = operation;
  e->old_block = old_block;
  e->new_block = new_block;
  e->line = line;

  e->text = edit_text;

  return e;
}

void edit_print(edit *e) {}
