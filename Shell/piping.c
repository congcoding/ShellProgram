#include "minishell.h"

int piping(char *command, char *envp[])
{
	//| split
	char **execs = command_parser(command);
	int fd[2];
	int fd_in = 0;
	int pid;

	if (ft_strslen(execs) == 1)
	{
		redirection(execs[0], envp);
		return 1;
	}
	while (*execs)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(execs + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			redirection(*execs, envp);
			exit(0);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			execs++;
		}
	}
}