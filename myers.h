#ifndef myers_h
#define myers_h

#include "block.h"
#include "edit.h"

typedef struct myers myers;
struct myers {
  block *block1;       // First collection of lines
  block *block2;       // Second collection of lines
  int shortest_length; // Shortest possible # of moves
  int num_edits;       // # of edits made in final path
};

/* Returns a newly allocated myers object */
myers *myers_make(block *block1, block *block2);

/* Perform the myer's algorithm on the block of lines */
void myers_do(myers *m);

/* Clones the current path onto the moveset */
void myers_clone_path(int **moveset, int *path, int size, int length);

/* Creates a complete collection of moves to make for backtracking
 * @returns moveset
 */
int **myers_make_moveset(myers *m);

/* Creates the edit with the associated operation */
edit *myers_handle_op(myers *m, int prev_x, int prev_y, int x, int y);

/* Finds the best path with the given moveset
 * @param moveset
 * @returns - edit collection
 */
edit **myers_backtrack(myers *m, int **moveset);

/* Returns a collection of edit objects that contain the moves needed for the
 * end printing result */
edit *myers_gen_edits(myers *m);

/* Prints the end diff result */
void myers_print(myers *m, edit *edits);

#endif
