#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE 

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>

extern char **environ;

/** string utilities */
int _putchar(char c);
void _print(char *str);
void prompt(void);
/*void _print_error(char *command, char *message);*/


/* shell utility */
char *read_inputs(void);
char **tokenize(char *str, const char *delim);
char **parse(char *input);
char *search_path(char *cmd);
char *get_env_path(void);
/* memory utility */
void free_toks(char **tokens);
int _execute(char **argv);
void free_line(void);

/* builtin ulility */
int check_builtin(char **av);
void s_exit(char **av);
int s_env(void);

void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);
#endif
