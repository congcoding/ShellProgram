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

void	rediretioning(char *file, char *flag, int fd[2])
{
	if (!file)
	{
		ft_write_n(2, "syntax error near unexpected token `newline'");
		g_last_ret = 2;
		return ;
	}
	if (!strcmp(file, "<") || !strcmp(file, ">")
		|| !strcmp(file, ">>") || !strcmp(file, "|")
		|| !strcmp(file, ";"))
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, file);
		g_last_ret = 2;
		return ;
	}
	if (!ft_strcmp(flag, ">"))
		fd[1] = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (!ft_strcmp(flag, ">>"))
		fd[1] = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	else if (!ft_strcmp(flag, "<"))
		fd[0] = open(file, O_RDONLY, S_IRWXU);
}

int is_cmd(char *cmd)
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

int redirection(char ***argv, int fd[2])
{
	char	**new;
	int		i;
	int		j;
	
	if (!(new = malloc(sizeof(char *) * ft_strslen(*argv))))
		return (FALSE);
	i = -1;
	j = -1;
	while ((*argv)[++i])
	{
		if (!strcmp((*argv)[i], "<") || !strcmp((*argv)[i], ">")
			|| !strcmp((*argv)[i], ">>"))
		{
			rediretioning((*argv)[++i], (*argv)[i], fd);
			if (fd[0] == -1 || fd[1] == -1)
			{
				ft_write(2, (*argv)[i]);
				ft_write_n(2, ": No such file or directory");
				g_last_ret = 1;
				return (FALSE);
			}
			continue;
		}
		new[++j] = ft_strdup((*argv)[i]);
	}
	new[++j] = NULL;
	*argv = new;
	return (TRUE);
}