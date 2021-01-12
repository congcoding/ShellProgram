#include "minishell.h"

static void	rediretioning(char *file, char *flag, int fd[2])
{
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

static char	**error(char **argv, char *cmd)
{
	ft_write(2, cmd);
	ft_write_n(2, ": No such file or directory");
	ft_double_free(argv);
	g_last_ret = 1;
	return (NULL);
}

char	**redirection(char **cmd, int fd[2])
{
	char	**argv;
	int		i;
	int		j;
	
	argv = NULL;
	if (!(argv = double_alloc(ft_strslen(cmd))))
		return (NULL);
	i = -1;
	j = -1;
	while (cmd[++i])
	{
		if (!strcmp(cmd[i], "<") || !strcmp(cmd[i], ">")
			|| !strcmp(cmd[i], ">>"))
		{
			rediretioning(cmd[++i], cmd[i], fd);
			if (fd[0] == -1 || fd[1] == -1)
				return (error(argv, cmd[i]));
			continue;
		}
		argv[++j] = ft_strdup(cmd[i]);
	}
	argv[++j] = NULL;
	return (argv);
}