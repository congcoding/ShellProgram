#include "minishell.h"

int piping(char *command)
{
	/*
	char **execs = parser(command, '|');
	int fd[2];
	int fd_in = 0;
	int pid;
	int state;
	int	i;
	
	if (ft_strslen(execs) == 1)
	{
		redirection(execs[0]);
		ft_double_free(execs);
		return 0;
	}
	i = 0;
	while (execs[i])
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, 0);
			if (execs[i + 1])
				dup2(fd[1], 1);
			close(fd[0]);
			redirection(*execs);
			exit(1);
		}
		else
		{
			wait(&state);
			close(fd[1]);
			fd_in = fd[0];
			i++;
		}
	}
	ft_double_free(execs);
	*/
}