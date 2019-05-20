#include "utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

FILE *process_file(char *filename) {
  FILE *file;

  if ((file = fopen(filename, "r")) == NULL) {
    printf("Can't open '%s' Please make sure it exists and try again.\n",
           filename);
    exit(1);
  }

  return file;
}

char *rstrip(char *s) {
  char *t = s + strlen(s) - 1;
  while (t >= s && isspace(*t)) {
    *t-- = '\0';
  }

  return s;
}

void printline(void) {
  for (int i = 0; i < 10; ++i) {
    printf("==========");
  }
  printf("\n");
}
