#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#define MAX_ARGUMENTS 20
void print_prompt(void);
void read_input(char **buf, size_t *n);
void parse_input(char *input, char **argv);
void execute_cmd(char **argv);
void env(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _printf(const char *format, ...);
int _putchar(char c);
char *_strchr(char *s, char c);
char *_getenv(const char *name);
int _strlen(const char *s);
extern char **environ;
#endif
