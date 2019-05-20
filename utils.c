#include "utils.h"
#include "options.h"
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

void printleft(const char *left) {
  if (show_brief) {
    return;
  }

  char buf[1024];

  strcpy(buf, left);
  if (show_sidebyside) {
    int j = 0, len = (int)strlen(buf) - 1;
    for (j = 0; j <= 48 - len; ++j) {
      buf[len + j] = ' ';
    }
    buf[len + j++] = '<';
    buf[len + j++] = '\0';
    printf("%s\n", buf);
  } else {
    int j = 0, len = (int)strlen(buf) - 1;
    printf("< ");
    printf("%s", buf);
  }
}

void printright(const char *right) {
  if (show_brief) {
    return;
  }

  if (right == NULL) {
    return;
  }

  if (show_unified) {
    printf("%s %s", ">", right);
  } else if (show_sidebyside) {
    printf("%50s %s", ">", right);
  } else {
    printf("%s %s", ">", right);
  }
}

void printboth(const char *left_right) {
  if (show_brief) {
    return;
  }

  char buf[1024];
  size_t len = strlen(left_right);
  if (len > 0) {
    strncpy(buf, left_right, len);
  }
  buf[len - 1] = '\0';

  if (show_leftcolumn || show_unified) {
    char *lp = (char *)left_right;
    while (*lp != '\n') {
      lp++;
    }
    *lp = '\0';

    printf("%-50s", left_right);
    if (show_leftcolumn) {
      printf(")");
    }

    printf("\n");
  } else {
    printf("%-50s %s", buf, left_right);
  }
}
