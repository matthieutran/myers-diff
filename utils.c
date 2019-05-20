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

int stricmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0' && (tolower(*s1) == tolower(*s2))) {
    ++s1;
    ++s2;
  }

  if (*s1 == '\n' && *s2 == '\n') {
    return 0;
  }

  return tolower(*s1) - tolower(*s2);
}
