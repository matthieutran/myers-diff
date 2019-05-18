#include "utils.h"
#include <ctype.h>
#include <string.h>


/* By Dr. William McCarthy
 * string_appendix_b3.c
 */
char *rstrip(char *s) {
  char *t = s + strlen(s) - 1;
  while (t >= s && isspace(*t)) {
    *t-- = '\0';
  }

  return s;
}
