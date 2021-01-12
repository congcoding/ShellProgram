#include "minishell.h"

static int work(char **argv, int fd[2], int backup[2])
{
	char	**argv_p;
	int		i;

	if (!(argv_p = malloc(sizeof(char *) * (ft_strslen(argv) + 1))))
		return (FALSE);
	i = -1;
	while (argv[++i])
		argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(argv_p[0]))
		return (FALSE);
	if (!ft_strcmp(argv_p[0], "echo"))
		echo(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "env"))
		env(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "pwd"))
		pwd(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "cd"))
		cd(argv_p[1]);
	if (!ft_strcmp(argv_p[0], "export"))
		export(argv_p);
	if (!ft_strcmp(argv_p[0], "unset"))
		unset(argv_p);
	if (!ft_strcmp(argv_p[0], "exit"))
		ft_exit();
	ft_double_free(argv_p);
	return (TRUE);
}

int single(char **cmd)
{
	char	**argv;
	int		fd[2];
	int		backup[2];
	
	fd[0] = 0;
	fd[1] = 1;
	if (!(argv = redirection(cmd, fd)))
		return (FALSE);
	if (!work(argv, fd, backup))
		return (FALSE);
	ft_double_free(argv);
	std_reset(fd, backup);
	return (TRUE);
}