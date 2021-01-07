#include "minishell.h"

int single(char **argv)
{
	int		fd[2];
	int		backup[2];

	fd[0] = 0;
	fd[1] = 1;

	
	if (!redirection(&argv, fd))
		return (FALSE);
	
	int i = -1;
	while (argv[++i])
		argv_parsing(&argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(argv[0]))
		return (FALSE);
	if (!ft_strcmp(argv[0], "echo"))
		echo(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "env"))
		env(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "pwd"))
		pwd(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "cd"))
		cd(argv[1]);
	if (!ft_strcmp(argv[0], "export"))
		export(argv);
	if (!ft_strcmp(argv[0], "exit"))
		exit(0);
	std_reset(fd, backup);
}