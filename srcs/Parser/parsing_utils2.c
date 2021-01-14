/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:53:22 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 19:38:28 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{
		if (quotes(line, i) != 1 && line[i] == '$' && i && line[i - 1] != '\\'
			&& line[i + 1] && line[i + 1] != ' ' && line[i + 1] != ';')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && line[i - 1] == '>' && line[i] == '>')
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	return (new);
}

int		valid_quote(char *line)
{
	if (quotes(line, 256))
	{
		ft_write_n(2, "syntax error : open quote");
		g_last_ret = 2;
		return (FALSE);
	}
	return (TRUE);
}

void	int_arr_init(int *arr, int len, int var)
{
	int i;

	i = -1;
	while (++i < len)
		arr[i] = var;
}

char	**cutting(char *str, int *cut, int len)
{
	char	**strs;
	char	*temp;
	int		i;
	int		j;

	if (!(strs = double_alloc(len)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len)
	{
		temp = ft_stredup(str, cut[i], cut[i + 1]);
		if (strcmp(temp, ""))
			strs[++j] = ft_strdup(temp);
		cut[i + 1]++;
		free(temp);
	}
	strs[i] = NULL;
	return (strs);
}

int		is_sep_space(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr(" ", line[i]))
	{
		if (!active_slash(line, i - 1) && quotes(line, i) == 0)
			return (1);
		return (0);
	}
	else if (ft_strchr(" ", line[i]) && quotes(line, i) == 0)
		return (1);
	else
		return (0);
}
