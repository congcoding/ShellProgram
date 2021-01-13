/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:34 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 14:55:24 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	work2(void)
{
	if (!ft_strcmp(g_argv_p[0], "echo"))
		echo(ft_strslen(g_argv_p), g_argv_p, g_envp);
	if (!ft_strcmp(g_argv_p[0], "env"))
		env(ft_strslen(g_argv_p), g_argv_p, g_envp);
	if (!ft_strcmp(g_argv_p[0], "pwd"))
		pwd(ft_strslen(g_argv_p), g_argv_p, g_envp);
	if (!ft_strcmp(g_argv_p[0], "cd"))
		cd(g_argv_p[1]);
	if (!ft_strcmp(g_argv_p[0], "export"))
		export(g_argv_p);
	if (!ft_strcmp(g_argv_p[0], "unset"))
		unset(g_argv_p);
	if (!ft_strcmp(g_argv_p[0], "exit"))
		ft_exit();
}

static int	single_work(char **argv, int fd[2], int backup[2])
{
	int		i;

	g_argv_p = NULL;
	if (!(g_argv_p = double_alloc(ft_strslen(argv))))
		return (FALSE);
	i = -1;
	while (argv[++i])
		g_argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(g_argv_p[0]))
	{
		ft_double_free(g_argv_p);
		return (FALSE);
	}
	work2();
	ft_double_free(g_argv_p);
	return (TRUE);
}

int			single(char **cmd)
{
	int		fd[2];
	int		backup[2];

	fd[0] = 0;
	fd[1] = 1;
	g_argv = NULL;
	if (!(g_argv = redirection(cmd, fd)))
		return (FALSE);
	if (!single_work(g_argv, fd, backup))
	{
		ft_double_free(g_argv);
		return (FALSE);
	}
	ft_double_free(g_argv);
	std_reset(fd, backup);
	return (TRUE);
}
