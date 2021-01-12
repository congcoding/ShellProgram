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

void	std_reset(int fd[2], int backup[2])
{
	if (fd[0] != 0)
		dup2(backup[0], 0);
	if (fd[1] != 1)
		dup2(backup[1], 1);
}

int		is_cmd(char *cmd)
{
	if (!strcmp(cmd, "echo") || !strcmp(cmd, "cd")
		|| !strcmp(cmd, "pwd") || !strcmp(cmd, "export")
		|| !strcmp(cmd, "unset")|| !strcmp(cmd, "env")
		|| !strcmp(cmd, "exit"))
		return (TRUE);
	else
	{
		g_last_ret = 3; //(normally 127)
		ft_write(2, cmd);
		ft_write_n(2, " : command not found");
		return (FALSE);
	}
}