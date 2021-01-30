/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:34 by seolim            #+#    #+#             */
/*   Updated: 2021/01/30 10:17:10 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void external(char **argv, char **cmds)
{
	int		state;
	int		i;

	state = 0;
	g_pid = fork();
	if (g_pid == 0)
	{
		execve(argv[0], argv, g_envp);
		i = -1;
		while (cmds[++i])
			execve(cmds[i], argv, g_envp);
		ft_write(2, g_argv_p[0]);
		ft_write_n(2, " : command not found");
		exit(127);
	}
	else
	{
		wait(&state);
		if (state == 2)
			g_last_ret = 130;
		else if (state == 131)
			g_last_ret = 131;
		else
			g_last_ret = state / 256;
		g_pid = 1;
	}
}

static int	internal()
{
	if (!ft_strcmp(g_argv_p[0], "echo"))
		echo(ft_strslen(g_argv_p), g_argv_p, g_envp);
	else if (!ft_strcmp(g_argv_p[0], "env"))
		env(ft_strslen(g_argv_p), g_argv_p, g_envp);
	else if (!ft_strcmp(g_argv_p[0], "pwd"))
		pwd(ft_strslen(g_argv_p), g_argv_p, g_envp);
	else if (!ft_strcmp(g_argv_p[0], "cd"))
		cd(g_argv_p[1]);
	else if (!ft_strcmp(g_argv_p[0], "export"))
		export(g_argv_p);
	else if (!ft_strcmp(g_argv_p[0], "unset"))
		unset(g_argv_p);
	else if (!ft_strcmp(g_argv_p[0], "exit"))
		ft_exit(g_argv_p);
	else
		return (FALSE);
	return (TRUE);
}

static char	**make_cmd(char *cmd)
{
	char	*path_env;
	char	**paths;
	char	*temp; 
	char	**cmds;
	int		i;
	
	path_env = get_env(g_envp, "PATH");
	paths = ft_split(path_env, ':');
	free(path_env);
	if (!(cmds = malloc(sizeof(char *) * (ft_strslen(paths) + 1))))
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strappend(paths[i], "/");
		cmds[i] = ft_strappend(temp, cmd);
		free(temp);
	}
	ft_double_free(paths);
	cmds[i] = NULL;
	return (cmds);
}

static void	work2(void)
{
	char	**cmds;	

	if (!internal())
	{
		cmds = make_cmd(g_argv_p[0]);
		external(g_argv_p, cmds);
		ft_double_free(cmds);
	}	
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
	work2();
	ft_double_free(g_argv_p);
	g_argv_p = NULL;
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
		g_argv = NULL;
		return (FALSE);
	}
	ft_double_free(g_argv);
	g_argv = NULL;
	std_reset(fd, backup);
	return (TRUE);
}
