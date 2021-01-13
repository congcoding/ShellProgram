/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:29:13 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 15:59:19 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	bufs[256];
	char	buf;
	int		len;
	int		i;

	i = -1;
	while (TRUE)
	{
		len = read(fd, &buf, 1);
		if (len == 0)
			return (0);
		if (buf == '\n')
			break ;
		bufs[++i] = buf;
	}
	bufs[++i] = 0;
	*line = ft_strdup(bufs);
	return (1);
}
