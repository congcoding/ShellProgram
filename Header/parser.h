#ifndef PARSER_H
# define PARSER_H

#include "macro.h"
#include "lib.h"

struct		s_parse
{
	int		single_quote;
	int		double_quote;
}			t_parse;

char		**input_parser(char *str);
char 		**command_parser(char *command);
char 		**exec_parser(char *exec);
char 		**parser(char *str, char c);

#endif