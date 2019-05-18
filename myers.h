#include "edit.h"

typedef struct myers myers;
struct myers {
  char **str1;
  char **str1;
  char **str1_size;
  char **str2_size;
};

/* Returns a newly allocated myers object */
myers *make_myers(char **str1, char **str2);

/* Creates a complete collection of moves to make for backtracking */
int **myers_make_moveset(myers *m);

/* Finds the best path */
void myers_backtrack();

/* Returns a collection of edit objects that contain the moves needed for the
 * end printing */
edit *myers_gen_edits(myers *m);