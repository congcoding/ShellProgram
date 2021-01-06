#include "minishell.h"

void	std_backup(int fd[2], int backup[2])
{
	backup[0] = 20;
	backup[1] = 21;
	if (fd[0] != 0)
	{
		dup2(0, backup[0]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	if (fd[1] != 1)
	{		
		dup2(1, backup[1]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
}

void std_reset(int fd[2], int backup[2])
{
	if (fd[0] != 0)
		dup2(backup[0], 0);
	if (fd[1] != 1)
		dup2(backup[1], 1);
}

int single(char **argv)
{
	int		fd[2];
	int		backup[2];

	fd[0] = 0;
	fd[1] = 1;
	if (!redirection(&argv, fd))
		return (FALSE);
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