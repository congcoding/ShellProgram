#include "minishell.h"

int single(char *exec)
{
	char	**argv;
	int		fd[2];

	argv = ft_split(exec, ' '); // TODO : re parsing
	fd[0] = 0;
	fd[1] = 1;
	redirection(argv, fd);
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
}