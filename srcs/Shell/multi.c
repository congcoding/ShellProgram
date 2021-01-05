#include "minishell.h"

int work(char *exec, int fd[2])
{
	char	**argv;

	argv = ft_split(exec, ' ');
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

int multi(char **execs)
{
	int fd[2];
	int i;
	int fd_in;
	int pid;
	int state;
	
	fd_in = 0;
	i = 0;
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
			char c = state + '0';
			ft_write_n(2, &c);
			close(fd[1]);
			fd_in = fd[0];
			execs++;
		}
	}
}