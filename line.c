#include "line.h"
#include <stdlib.h>

line *line_make(char *content, int num) {
  line *l = malloc(sizeof(line));

  l->content = content;
  l->num = num;

  return l;
}
