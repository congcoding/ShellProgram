/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:01:33 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 19:17:00 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	path(char **argv)
{
	char	*temp;
	char	*cmd;
	char	*path_env;
	char	**paths;
	int		i;

	path_env = get_env(g_envp, "PATH");
	paths = ft_split(path_env, ':');
	free(path_env);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strappend(paths[i], "/");
		cmd = ft_strappend(temp, argv[0]);
		free(temp);
		execve(cmd, argv, g_envp);
		free(cmd);
	}
	ft_double_free(paths);
	ft_write(2, g_argv_p[0]);
	ft_write_n(2, " : command not found");
	exit(127);
}

static void	work3(char **argv_p)
{
	if (!ft_strcmp(argv_p[0], "echo"))
		echo(ft_strslen(argv_p), argv_p, g_envp);
	else if (!ft_strcmp(argv_p[0], "env"))
		env(ft_strslen(argv_p), argv_p, g_envp);
	else if (!ft_strcmp(argv_p[0], "pwd"))
		pwd(ft_strslen(argv_p), argv_p, g_envp);
	else if (!ft_strcmp(argv_p[0], "cd"))
		cd(argv_p[1]);
	else if (!ft_strcmp(argv_p[0], "export"))
		export(argv_p);
	else if (!ft_strcmp(argv_p[0], "unset"))
		unset(argv_p);
	else if (!ft_strcmp(argv_p[0], "exit"))
		ft_exit();
	else
		path(argv_p);
}

static int	work2(char **argv, int fd[2], int backup[2])
{
	int		i;

	if (!(g_argv_p = double_alloc(ft_strslen(argv))))
		return (FALSE);
	i = -1;
	while (argv[++i])
		g_argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	work3(g_argv_p);
	ft_double_free(g_argv_p);
	g_argv_p = NULL;
	return (TRUE);
}

int			work(char **cmd)
{
	int		fd[2];
	int		backup[2];

	fd[0] = 0;
	fd[1] = 1;
	if (!(g_argv = redirection(cmd, fd)))
		return (FALSE);
	if (!work2(g_argv, fd, backup))
	{
		ft_double_free(g_argv);
		g_argv = NULL;
		return (FALSE);
	}
	ft_double_free(g_argv);
	g_argv = NULL;
	std_reset(fd, backup);
	return (TRUE);
}
