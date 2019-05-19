#include "utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char buf[BUF_SIZE];

FILE *process_file(char *filename) {
  FILE *file;

  if ((file = fopen(filename, "r")) == NULL) {
    printf("Can't open '%s' Please make sure it exists and try again.\n",
           filename);
    exit(1);
  }

  return file;
}

int block_from_file(char **block, char *filename) {
  int lines = 0;

  FILE *file = process_file(filename);

  while (!feof(file) && fgets(buf, BUF_SIZE, file) != NULL) {
    block[lines++] = strdup(buf);
  }

  fclose(file);

  return lines;
}

char *rstrip(char *s) {
  char *t = s + strlen(s) - 1;
  while (t >= s && isspace(*t)) {
    *t-- = '\0';
  }

  return s;
}
