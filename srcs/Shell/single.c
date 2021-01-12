#include "minishell.h"

static char **allocation(int len)
{
	char **argv_p;

	if (!(argv_p = malloc(sizeof(char *) * len)))
		return (NULL);
	int i;
	i = -1;
	while (++i < len)
		argv_p[i] = NULL;
	return (argv_p);
}

static int work(char **argv, int fd[2], int backup[2])
{
	int		i;

	g_argv_p = NULL;
	g_argv_p = allocation(ft_strslen(argv) + 1);
	/*
	if (!(g_argv_p = malloc(sizeof(char *) * (ft_strslen(argv) + 1))))
		return (FALSE);
	*/
	i = -1;
	while (argv[++i])
		g_argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(g_argv_p[0]))
		return (FALSE);
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
	ft_double_free(g_argv_p);
	return (TRUE);
}

int single(char **cmd)
{
	int		fd[2];
	int		backup[2];
	
	fd[0] = 0;
	fd[1] = 1;
	g_argv = NULL;
	if (!(g_argv = redirection(cmd, fd)))
		return (FALSE);
	if (!work(g_argv, fd, backup))
		return (FALSE);
	ft_double_free(g_argv);
	std_reset(fd, backup);
	return (TRUE);
}