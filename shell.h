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

/* shell mode **/

void interactive_shell_mode(char *name);

/** string utilities */
int _putchar(char c);
void _print(char *str);
void prompt(void);
/*void _print_error(char *command, char *message);*/


/* shell utility */
char *read_inputs(void);
char *read_stream(void);
char **tokenize(char *str, const char *delim);
char **parse(char *input);
char *search_path(char *cmd);
int fork_command(char *full_path, char **argv);
int execute_call(char **argv, char *name);

/* pipe utility */
int exec_semiColon(char *args[]);
int pipe_command(char *args[]);

/* memory utility */
void free_toks(char **tokens);

/* builtin ulility */
int check_builtin(char **av);
void s_exit(char **av);
int s_env(void);
void s_cd(char **av);

void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);
#endif
