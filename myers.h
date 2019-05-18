#ifndef myers_h
#define myers_h

#include "block.h"
#include "edit.h"

typedef struct myers myers;
struct myers {
  block *block1;       // First collection of lines
  block *block2;       // Second collection of lines
  int shortest_length; // Shortest possible # of moves
  edit *edits;         // Collection of edits needed for path
};

/* Returns a newly allocated myers object */
myers *myers_make(block *block1, block *block2);

/* Creates a complete collection of moves to make for backtracking */
int **myers_make_moveset(myers *m);

/* Finds the best path with the given moveset */
void myers_backtrack(myers *m, int **moveset);

/* Returns a collection of edit objects that contain the moves needed for the
 * end printing result */
edit *myers_gen_edits(myers *m);

/* Prints the end diff result */
void myers_print(myers *m, edit *edits);

#endif
