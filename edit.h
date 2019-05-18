#define OPERATION_DELETE 0
#define OPERATION_INSERT 1
#define OPERATION_EQUALS 2

/* Represents the edits we will need to make in the end for printing */
typedef struct edit edit;
struct edit {
  int operation;
  int old_line;
  int new_line;
};

/* returns a newly allocated edit object */
edit *make_edit(int type, int old_line, int new_line);
