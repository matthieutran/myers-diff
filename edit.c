#include "edit.h"
#include "utils.h"
#include <stdlib.h>

char *edit_text(edit *e) { return e->old_line ? e->old_line : e->new_line; }

edit *edit_make(int operation, char *old_line, char *new_line) {
  edit *e = malloc(sizeof(edit));
  e->operation = operation;
  e->old_line = old_line;
  e->new_line = new_line;
  e->text = edit_text;

  return e;
}

void edit_print(edit *e) {}
