/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:52:24 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 18:07:53 by seolim           ###   ########.fr       */
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
