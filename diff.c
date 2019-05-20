/* Diff Program written in C based on the Myer's Algorithm explained in
 * https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/
 * by James Coglan
 */

#include "diff.h"
#include "block.h"
#include "myers.h"
#include "options.h"
#include "tests.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *filenames[2] = {NULL, NULL};

int main(int argc, const char *argv[]) {
  // run_tests();
  handle_options(argc, argv);

  /* Build file blocks */
  block *old_block = block_from_file(filenames[0]);
  block *new_block = block_from_file(filenames[1]);

  myers *m = myers_make(old_block, new_block);

  /* Process myers algorithm */
  myers_do(m);

  return 0;
}

void handle_options(int argc, const char *argv[]) {
  set_options(--argc, --argv);

  if (show_version) {
    show_version_text();
    exit(1);
  }

  if (show_help) {
    show_options_text();
    exit(1);
  }

  if (argc < 2) { // Since show version/help can be only arg
    fprintf(stderr, "Usage: ./diff [options] file1 file2\n");
  }
}

int show_version = 0, show_brief = 0, ignorecase = 0, report_identical = 0,
    diffnormal = 0, show_sidebyside, show_leftcolumn = 0, suppress_common = 0,
    show_context = 0, show_unified = 0, show_help = 0;

/* From Dr. William McCarthy init_options_files() */
void set_options(int argc, const char *argv[]) {
  int cnt = 0, count = 1;

  while (count++ < argc + 1) {
    set_option(argv[count], "-v", "--version", &show_version);
    set_option(argv[count], "-q", "--brief", &show_brief);
    set_option(argv[count], "-i", "--ignore-case", &ignorecase);
    set_option(argv[count], "-s", "--report-identical-files",
               &report_identical);
    set_option(argv[count], "--normal", NULL, &diffnormal);
    set_option(argv[count], "-y", "--side-by-side", &show_sidebyside);
    set_option(argv[count], "--left-column", NULL, &show_leftcolumn);
    set_option(argv[count], "--suppress-common-lines", NULL, &suppress_common);
    set_option(argv[count], "-c", "--context", &show_context);
    set_option(argv[count], "-u", "--unified", &show_unified);
    set_option(argv[count], "-h", "--help", &show_help);

    if (argv[count][0] != '-') {
      if (cnt == 2) {
        fprintf(stderr,
                "apologies, this version of diff only handles two files\n");
        fprintf(stderr, "Usage: ./diff [options] file1 file2\n");
        exit(3);
      } else {
        filenames[cnt++] = (char *)argv[count];
      }
    }
  }

  if (!show_context && !show_unified && !show_sidebyside && !show_leftcolumn) {
    diffnormal = 1;
  }

  if (((show_sidebyside || show_leftcolumn) &&
       (diffnormal || show_context || show_unified)) ||
      (show_context && show_unified) ||
      (diffnormal && (show_context || show_unified))) {

    fprintf(stderr, "diff: conflicting output style options\n");
    fprintf(stderr, "diff: Try `diff --help' for more information.)\n");
    exit(1);
  }
}

/* From Dr. William McCarthy set_option() */
void set_option(const char *text, const char *nick, const char *fullname,
                int *option) {
  if ((strcmp(text, nick) == 0) ||
      ((fullname != NULL && strcmp(text, fullname) == 0))) {
    *option = 1;
  }
}

/* From Dr. William McCarthy showoptions() */
void show_options_text() {
  show_version_text();
  printf("diff options...\n");
  print_option("diffnormal", diffnormal);
  print_option("show_version", show_version);
  print_option("show_brief", show_brief);
  print_option("ignorecase", ignorecase);
  print_option("report_identical", report_identical);
  print_option("show_sidebyside", show_sidebyside);
  print_option("show_leftcolumn", show_leftcolumn);
  print_option("suppresscommon", suppress_common);
  print_option("showcontext", show_context);
  print_option("show_unified", show_unified);

  printf("file1: %s,  file2: %s\n\n\n", filenames[0], filenames[1]);

  printline();
}

/* From Dr. William McCarthy print_option() */
void print_option(const char *name, int value) {
  printf("%17s: %s\n", name, value == 0 ? "OFF" : "ON");
}

void show_version_text(void) {
  printline();
  printf(
      "Diff Tool. Created by Matthieu Tran for CPSC 223C. This tool is "
      "based off of Jame Coglan's \nimplementation of the Myer's algorithm in "
      "the blog post below.\n"
      "https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/"
      "\n\n");
  printline();
}
