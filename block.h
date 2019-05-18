typedef struct block block;
struct block {
  char **text; // block content
  int lines;   // # of lines in the block
};

/* returns a newly allocated block object */
block *make_block(char **text, int lines);
