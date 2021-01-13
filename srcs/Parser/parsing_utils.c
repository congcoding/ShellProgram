/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:52:57 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:53:18 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		active_slash(char *line, int i)
{
	int	is_slash;
	int	j;

	is_slash = TRUE;
	j = 1;
	while (i - j >= 0 && line[i - j] == '\\')
	{
		is_slash = !is_slash;
		j++;
	}
	return (is_slash);
}

int		quotes(char *line, int idx)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (line[i] && i != idx)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (quote == 0 && line[i] == '\'')
			quote = 1;
		else if (quote == 0 && line[i] == '\"')
			quote = 2;
		else if (quote == 1 && line[i] == '\'')
			quote = 0;
		else if (quote == 2 && line[i] == '\"')
			quote = 0;
		i++;
	}
	if (quote == 1 && line[idx] == '\'')
		quote = 0;
	if (quote == 2 && line[idx] == '\"')
		quote = 0;
	return (quote);
}

int		is_sep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("<>|;", line[i]))
	{
		if (!active_slash(line, i - 1) && quotes(line, i) == 0)
			return (1);
		return (0);
	}
	else if (ft_strchr("<>|;", line[i]) && quotes(line, i) == 0)
		return (1);
	else
		return (0);
}

int		is_out(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("\"\'\\", line[i]))
	{
		if (!active_slash(line, i - 1) && quotes(line, i) == 0)
			return (1);
		return (0);
	}
	else if (ft_strchr("\'\"\\", line[i]) && quotes(line, i) == 0)
		return (1);
	else
		return (0);
}

char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			count++;
		i++;
	}
	if (!(new = malloc(sizeof(char) * (i + 2 * count + 1))))
		return (NULL);
	return (new);
}
