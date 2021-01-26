/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:08:14 by seolim            #+#    #+#             */
/*   Updated: 2021/01/26 15:34:23 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		global_init(void)
{
	g_last_ret = 0;
	g_pipe_cmd = NULL;
	g_envp = NULL;
	g_input = NULL;
	g_cmd = NULL;
	g_argv = NULL;
	g_argv_p = NULL;
	g_pid = 1;
}

void		shell(char **input)
{
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!ft_strcmp(input[i], ";"))
		{
			g_cmd = ft_strsndup(input + start, i - start);
			start = i + 1;
			piping(g_cmd);
			ft_double_free(g_cmd);
			g_cmd = NULL;
		}
	}
	if (start != i)
	{
		g_cmd = ft_strsndup(input + start, i);
		piping(g_cmd);
		ft_double_free(g_cmd);
		g_cmd = NULL;
	}
}

int			main(int argc, char *argv[], char *envp[])
{
	char	*line;

	argc++;
	argv++;
	sig_int();
	global_init();
	g_envp = init_envp(envp);
	while (TRUE)
	{
		if (prompt(&line))
			continue;
		if (!pre_parsing(line, &g_input))
			continue;
		shell(g_input);
		ft_double_free(g_input);
		g_input = NULL;
	}
	ft_double_free(g_envp);
}
