#ifndef edit_h
#define edit_h

#include "block.h"

#define OPERATION_DELETE 0
#define OPERATION_INSERT 1
#define OPERATION_EQUALS 2

/* Represents the edits we will need to make in the end for printing */
typedef struct edit edit;
struct edit {
  int operation;          // 0 - Delete, 1 - Insert, 2 - Equals
  block *old_block;       // First block
  block *new_block;       // Second block
  int line;               // Line associated with the blocks
  char *(*text)(edit *e); // text associated with the edit
};

/* returns a newly allocated edit object */
edit *edit_make(int operation, block *old_block, block *new_block, int line);

/* Returns either old_line or new_line */
char *edit_text(edit *e);

/* Prints each individual edit */
void edit_print(edit *e);

#endif
