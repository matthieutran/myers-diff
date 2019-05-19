#include "myers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

myers *myers_make(block *block1, block *block2) {
  myers *m = malloc(sizeof(myers));
  m->block1 = block1;
  m->block2 = block2;

  return m;
}

void myers_do(myers *m) {
  int **moveset; // Moveset
  edit **edits;  // Edit collection

  /* Generate the moveset for the blocks */
  moveset = myers_make_moveset(m);

  /* Backtrack to look for best path */
  edits = myers_backtrack(m, moveset);
}

void myers_clone_path(int **moveset, int *path, int size, int length) {
  int *cloned_path = malloc(sizeof(int) * size);
  moveset[length] = cloned_path;

  for (size_t i = 0; i < size; i++) {
    cloned_path[i] = path[i];
  }
}

int **myers_make_moveset(myers *m) {
  int **moveset, *path;
  size_t max_tries =
      m->block1->lines + m->block2->lines; // Maximum possible # of moves
  size_t max_index = 2 * max_tries + 1, moves_length = 0, prev, next;
  int x, y;

  path = malloc(sizeof(int) * (max_index));
  moveset = malloc(sizeof(path) * max_tries);

  /* Initialize all values to -1 except first index */
  for (size_t i = 0; i < max_index; i++) {
    path[i] = i != 1 ? -1 : 0;
  }

  for (int d = 0; d < max_tries; d++) { // Path
    myers_clone_path(moveset, path, max_index, moves_length++);

    for (int k = -d; k < d + 1; k += 2) { // Move
      prev = k - 1 >= 0 ? k - 1 : max_index + k - 1;
      next = k + 1 >= 0 ? k + 1 : max_index + k + 1;

      /* Determine to move upwards or downwards */
      if (k == -d || (k != d && path[prev] < path[next])) {
        x = path[next];
      } else {
        x = path[prev] + 1;
      }

      y = x - k;

      /* Check for diagonals and move accordingly */
      while (x < m->block1->lines && y < m->block2->lines &&
             strcmp(m->block1->text[x], m->block2->text[y]) == 0) {
        ++x;
        ++y;
      }

      path[k >= 0 ? k : max_index + k] = x;

      if (x >= m->block1->lines && y >= m->block2->lines) {
        m->shortest_length = d;
        free(path);

        return moveset;
      }
    }
  }

  return NULL;
}

edit *myers_handle_op(myers *m, int prev_x, int prev_y, int x, int y) {
  edit *e;

  if (x == prev_x) {
    e = edit_make(OPERATION_INSERT, NULL, m->block2, prev_y);
  } else if (y == prev_y) {
    e = edit_make(OPERATION_DELETE, m->block1, NULL, prev_x);
  } else {
    e = edit_make(OPERATION_DELETE, m->block1, m->block2, prev_x);
  }

  return e;
}

edit **myers_backtrack(myers *m, int **moveset) {
  int x, y, k, prev_k, prev_x, prev_y;
  edit **edits; // Collection of edits
  int num_edits;

  x = m->block1->lines;
  y = m->block2->lines;

  edits = malloc(sizeof(edit) * m->shortest_length);

  for (int d = m->shortest_length; d > -1; d--) {
    k = x - y; // from y = x - k

    /* Determine what the previous k was */
    if (k == -d || (k != d && moveset[d][k - 1] < moveset[d][k + 1])) {
      prev_k = k + 1;
    } else {
      prev_k = k - 1;
    }

    /* Calculate previous y */
    prev_x = moveset[d][prev_k];
    prev_y = prev_x - prev_k;

    /* Check for diagonals */
    while (x > prev_x && y > prev_y) {
      edit *e = myers_handle_op(m, x - 1, y - 1, x, y);
      edits[num_edits++] = e;

      --x;
      --y;
    }

    /* Go to position before diagonals */
    if (d > 0) { // no previous pos to move back to, skip
      edit *e = myers_handle_op(m, prev_x, prev_y, x, y);
      edits[num_edits++] = e;
    }

    /* set x and y to values in prev round and continue */
    x = prev_x;
    y = prev_y;
  }

  m->num_edits = num_edits; // store edits to reverse later

  return edits;
}

void myers_print(myers *m, edit *edits) {}
