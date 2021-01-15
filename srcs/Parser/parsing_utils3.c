/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:08:33 by seolim            #+#    #+#             */
/*   Updated: 2021/01/15 14:17:49 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		active_dallarnt(char *line, int i)
{
	int count;

	count = 1;
	while (i > 0)
	{
		if (line[--i] == '$')
			count++;
		else
			break ;
	}
	return (count % 2 == 1 ? TRUE : FALSE);
}

int		is_env(char *line, int i)
{
	if (quotes(line, i) != 1 && line[i] == '$' && i &&
		(line[i - 1] != '\\' || (line[i - 1] == '\\'
		&& !active_slash(line, i - 1)))
		&& line[i + 1] && line[i + 1] != ' ' && line[i + 1] != ';'
		&& active_dallarnt(line, i))
	{
		if (line[i + 1] == '\"')
		{
			if (quotes(line, i) == 0)
				return (TRUE);
			else if (quotes(line, i) == 2)
				return (FALSE);
		}
		if (ft_strchr("\%/\\", line[i + 1]))
			return (FALSE);
		return (TRUE);
	}
	if (line[i] == '$' && i == 0 && line[i + 1])
		return (TRUE);
	return (FALSE);
}
