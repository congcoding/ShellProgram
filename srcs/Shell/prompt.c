/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:24 by seolim            #+#    #+#             */
/*   Updated: 2021/01/27 17:05:41 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		line_append(char **line, char c)
{
	char	*new_line;
	int		len;

	len = ft_strlen(*line);
	if (!(new_line = malloc(sizeof(char) * (len + 2))))
		return (0);
	ft_strcpy(new_line, *line);
	new_line[len] = c;
	new_line[len + 1] = 0;
	if (*line != NULL)
		free(*line);
	*line = new_line;
	return (1);
}

int		eof_input(char *line)
{
	if (line == NULL)
	{
		ft_write_n(1, "exit");
		ft_exit(NULL);
	}
	return (FALSE);
}

char	*read_line(void)
{
	char	*line;
	char	buf;
	int		flag;

	line = NULL;
	while ((flag = read(0, &buf, 1)) != -1)
	{
		if (flag == 0)
			if (!eof_input(line))
				continue;
		if (buf != '\n')
		{
			line_append(&line, buf);
			continue;
		}
		if (buf == '\n')
			return (line);
	}
	return (NULL);
}

int		prompt(char **line)
{
	ft_write(1, "$> ");
	if (!(*line = read_line()))
		return (1);
	return (0);
}
