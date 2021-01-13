/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:52:24 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 16:30:45 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**sep_space(char *line)
{
	int	i;
	int	j;
	int	cut[256];

	i = -1;
	j = -1;
	int_arr_init(cut, 255, -1);
	cut[++j] = 0;
	while (line[++i])
	{
		if (line[i] == ' ' && is_sep_space(line, i))
			cut[++j] = i;
	}
	cut[++j] = i;
	return (cutting(line, cut, j));
}

int		is_token_check(char **token)
{
	if (!ft_strcmp(*(token + 1), "|") || !ft_strcmp(*(token + 1), ";"))
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, *token);
		g_last_ret = 2;
		return (FALSE);
	}
	return (TRUE);
}

int		input_check(char **input)
{
	if ((!ft_strcmp(*input, ";") || !ft_strcmp(*input, "|"))
		&& ft_strslen(input) == 1)
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, *input);
		g_last_ret = 2;
		return (FALSE);
	}
	while (*input)
	{
		if ((!ft_strcmp(*input, ">") || !ft_strcmp(*input, "<")
		|| !ft_strcmp(*input, ">>")) && !*(input + 1))
		{
			ft_write_n(2, "syntax error near unexpected token \'newline\'");
			g_last_ret = 2;
			return (FALSE);
		}
		if (!strcmp(*input, ";") || !strcmp(*input, "|"))
			if (!is_token_check(input))
				return (FALSE);
		input++;
	}
	return (TRUE);
}

int		pre_parsing(char *line, char ***input)
{
	char *s_line;

	if (!valid_quote(line))
		return (FALSE);
	s_line = space_line(line);
	free(line);
	*input = sep_space(s_line);
	free(s_line);
	if (!input_check(*input))
		return (FALSE);
	return (TRUE);
}
