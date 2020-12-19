#ifndef PARSER_H
# define PARSER_H

#include "macro.h"
#include "lib.h"

char **input_parser(char *str);
char **command_parser(char *command);
char **exec_parser(char *exec);

#endif