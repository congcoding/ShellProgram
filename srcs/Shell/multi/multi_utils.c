/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:01:22 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 18:54:34 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_free(void)
{
	int	i;

	i = -1;
	if (g_pipe_cmd != NULL)
	{
		while (g_pipe_cmd[++i])
			ft_double_free(g_pipe_cmd[i]);
		free(g_pipe_cmd);
	}
	g_pipe_cmd = NULL;
}

char	***pipe_alloc(char **input)
{
	char	***pipe_cmd;
	int		i;
	int		len;

	i = -1;
	len = 1;
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
			len += 1;
	}
	if (!(pipe_cmd = triple_alloc(len)))
		return (NULL);
	return (pipe_cmd);
}

void	child_exit(void)
{
	ft_double_free(g_cmd);
	ft_double_free(g_input);
	ft_double_free(g_envp);
	pipe_cmd_free();
	exit(g_last_ret);
}
