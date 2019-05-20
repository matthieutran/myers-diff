#ifndef diff_h
#define diff_h

/* Enables option flags based on user input */
void set_options(int argc, const char *argv[]);

/* Enables option flag */
void set_option(const char *text, const char *nick, const char *fullname,
                int *option);

void handle_options(int argc, const char *argv[]);

/* Show version and options */
void show_options_text(void);

/* Show program version and credits */
void show_version_text(void);

/* Show option text */
void print_option(const char *name, int value);

#endif
