#ifndef PARSER_H
# define PARSER_H

#include "macro.h"
#include "lib.h"

struct		s_parse
{
	int		single_quote;
	int		double_quote;
}			t_parse;

int		pre_parsing(char *line, char ***input);
char	**sep_space(char *line);
char	*argv_parsing(char *arg);

char	*space_alloc(char *line);
int		is_out(char *line, int i);
int		is_sep(char *line, int i);
int		quotes(char *line, int idx);
int		active_slash(char *line, int i);

int		is_sep_space(char *line, int i);
char	**cutting(char *str, int *cut, int len);
void	int_arr_init(int *arr, int len, int var);
int		valid_quote(char *line);
char	*space_line(char *line);

#endif