/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:13:55 by seolim            #+#    #+#             */
/*   Updated: 2021/01/28 17:38:59 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "macro.h"
# include "lib.h"

struct		s_parse
{
	int		single_quote;
	int		double_quote;
}			t_parse;

int			pre_parsing(char *line, char ***input);
char		**sep_space(char *line);
char		*argv_parsing(char *arg);

char		*space_alloc(char *line);
int			is_out(char *line, int i);
int			is_sep(char *line, int i);
int			quotes(char *line, int idx);
int			active_slash(char *line, int i);
int			is_env(char *line, int i);

int			is_sep_space(char *line, int i);
char		**cutting(char *str, int *cut, int len);
void		int_arr_init(int *arr, int len, int var);
int			valid_quote(char *line);
char		*space_line(char *line);

int			input_check(char **input);

#endif
