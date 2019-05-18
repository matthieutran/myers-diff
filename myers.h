#include "edit.h"

typedef struct myers myers;
struct myers {
  char **lines1;  // First collection of lines
  char **lines2;  // Second collection of lines
  int lines1_amt; // Number of lines from first collection
  int lines2_amt; // Number of lines from second collection
};

/* Returns a newly allocated myers object */
myers *make_myers(char **lines1, char **lines2, int lines1_size,
                  int lines2_size);

/* Creates a complete collection of moves to make for backtracking */
int **myers_make_moveset(myers *m);

/* Finds the best path */
void myers_backtrack(myers *m);

/* Returns a collection of edit objects that contain the moves needed for the
 * end printing */
edit *myers_gen_edits(myers *m);

/* Prints the end diff result */
void myers_print(myers *m, edit *edits);
