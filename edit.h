#include "block.h"

#define OPERATION_DELETE 0
#define OPERATION_INSERT 1
#define OPERATION_EQUALS 2

/* Represents the edits we will need to make in the end for printing */
typedef struct edit edit;
struct edit {
  int operation; // 0 - Delete, 1 - Insert, 2 - Equals
  int old_line;  // Line associated with first block
  int new_line;  // Line associated with second block
  char *(*text)(edit *e, block *b1,
                block *b2); // text associated with the edit
};

/* returns a newly allocated edit object */
edit *make_edit(int operation, int old_line, int new_line, block *b1,
                block *b2);

/* Returns either old_line or new_line */
char *edit_text(edit *e, block *block1, block *block2);

/* Prints each individual edit */
void edit_print(edit *e);
