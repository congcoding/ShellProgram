#include "minishell.h"

void	rediretioning(char *file, int flag, int fd[2])
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
	if (flag == TRUNC)
		fd[1] = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (flag == APPEND)
		fd[1] = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	else if (flag == INPUT)
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
		g_last_ret = 2;
		ft_write(2, cmd);
		ft_write_n(2, " is not command");
		return (FALSE);
	}
	
}

int redirection(char **argv, int fd[2])
{
	int		i;
	
	i = -1;
	if (!is_cmd(argv[++i]))
		return (FALSE);
	while (argv[++i])
	{
		if (!strcmp(argv[i], "<"))
			rediretioning(argv[++i], INPUT, fd);
		if (!strcmp(argv[i], ">"))
			rediretioning(argv[++i], TRUNC, fd);
		if (!strcmp(argv[i], ">>"))
			rediretioning(argv[++i], APPEND, fd);
		if (fd[0] == -1 || fd[1] == -1)
		{
			char c = i + '0';
			ft_write_n(1, &c);
			ft_write(2, argv[i]);
			ft_write_n(2, ": No such file or directory");
			g_last_ret = 1;
			return (FALSE);
		}
	}
	return (TRUE);
}