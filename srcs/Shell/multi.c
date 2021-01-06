#include "minishell.h"

int work(char **argv, int fd[2])
{
	int		re_fd[2];
	int		backup[2];
	
	if (!redirection(&argv, re_fd))
		return (FALSE);
	std_backup(re_fd, backup);
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

/*
int work(char **argv, int fd[2])
{
	int		re_fd[2];
	
	if (!redirection(&argv, fd))
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
}
*/

int pipe_processing(char ***pipe_cmd)
{
	int fd[2];
	int fd_in;
	int pid;
	int state;
	
	fd_in = 0;
	while (*pipe_cmd)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			ft_write_n(2, "piping error");
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(pipe_cmd + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			work(*pipe_cmd, fd);
			exit(g_last_ret);
		}
		else
		{
			wait(&state);
			close(fd[1]);
			fd_in = fd[0];
			pipe_cmd++;
		}
	}
}

char ***pipe_alloc(char **input)
{
	char	***pipe_cmd;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
			len +=1;
	}
	if (!(pipe_cmd = malloc(sizeof(char **) * (len + 1))))
		return (NULL);
	return (pipe_cmd);
}

int multi(char **input)
{
	char	***pipe_cmd;
	int		start;
	int		i;
	int		j;

	i = -1;
	j = -1;
	start = 0;
	if (!(pipe_cmd = pipe_alloc(input)))
		return (FALSE);
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
		{
			pipe_cmd[++j] = ft_strsndup(input + start, i);
			start = i + 1;
		}
	}
	if (start != i)
		pipe_cmd[++j] = ft_strsndup(input + start, i);
	pipe_cmd[++j] = NULL;
	pipe_processing(pipe_cmd);
}