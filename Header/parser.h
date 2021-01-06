#ifndef PARSER_H
# define PARSER_H

#include "macro.h"
#include "lib.h"

struct		s_parse
{
	int		single_quote;
	int		double_quote;
}			t_parse;

char	**seperator(char *line, char c);
int		pre_parsing(char *line, char ***input);
char	**sep_space(char *line);
int		argv_parsing(char **arg);

#endif