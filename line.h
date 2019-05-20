#ifndef line_h
#define line_h

typedef struct line line;

struct line {
  char *content; // Text associated with the line
  int num;       // Line number
};

/* Create a line struct */
line *line_make(char *content, int num);

#endif
