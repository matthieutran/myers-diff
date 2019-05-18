#include "myers.h"
#include <stdlib.h>
#include <string.h>

myers *myers_make(block *block1, block *block2) {
  myers *m = malloc(sizeof(myers));
  m->block1 = block1;
  m->block2 = block2;

  return m;
}

void myers_do(myers *m) {
  int **moveset;

  moveset = myers_make_moveset(m);

  /* Initialize our edit collection */
  m->edits = malloc(sizeof(edit) * m->shortest_length);
}

int **myers_make_moveset(myers *m) {
  int **moveset, *moves;
  size_t max_tries =
      m->block1->lines + m->block2->lines; // Maximum possible # of moves
  size_t max_index = 2 * max_tries + 1, moves_length, prev, next;
  int x, y;

  moves = malloc(sizeof(moves) * (max_index));
  moveset = malloc(sizeof(moveset) * sizeof(moves) * max_tries);

  /* Initialize all values to -1 except first index */
  for (size_t i = 0; i < max_index; i++) {
    moves[i] = i != 1 ? -1 : 0;
  }

  for (int d = 0; d < max_tries; d++) { // Path
    moveset[moves_length++] = moves;

    for (int k = -d; k < d + 1; k += 2) { // Move
      prev = k - 1 >= 0 ? k - 1 : max_index + k - 1;
      next = k + 1 >= 0 ? k + 1 : max_index + k + 1;

      /* Determine to move upwards or downwards */
      if (k == -d || (k != d && moves[prev] < moves[next])) {
        x = moves[next];
      } else {
        x = moves[prev] + 1;
      }

      y = x - k;

      /* Check for diagonals and move accordingly */
      while (x < m->block1->lines && y < m->block2->lines &&
             strcmp(m->block1->text[x], m->block2->text[y]) == 0) {
        ++x;
        ++y;
      }

      moves[k >= 0 ? k : max_index + k] = (int)x;

      if (x >= m->block1->lines && y >= m->block2->lines) {
        m->shortest_length = d;

        return moveset;
      }
    }
  }

  return NULL;
}

void myers_backtrack(myers *m, int **moveset) {}

void myers_print(myers *m, edit *edits) {}
