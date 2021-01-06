#include "minishell.h"

int work(char *exec, int fd[2])
{
	char	**argv;
	int		re_fd[2];

	argv = ft_split(exec, ' ');
	redirection(&argv, fd);
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

int pipe_processing(char **execs)
{
	int fd[2];
	int fd_in;
	int pid;
	int state;
	
	fd_in = 0;
	while (*execs)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			ft_write_n(2, "piping error");
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(execs + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			work(*execs, fd);
			exit(g_last_ret);
		}
		else
		{
			wait(&state);
			close(fd[1]);
			fd_in = fd[0];
			execs++;
		}
	}
}

int multi(char **input)
{
	char	**cmd;
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
		{
			cmd = ft_strsndup(input + start, i);
			start = i + 1;
			pipe_processing(cmd);
			ft_double_free(cmd);
		}
	}
	if (start != i)
	{
		cmd = ft_strsndup(input + start, i);
		pipe_processing(cmd);
		ft_double_free(cmd);
	}	
}