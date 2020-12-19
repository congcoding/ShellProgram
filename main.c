#include "minishell.h"

int exec_pro(char *execs)
{

}

int command_pro(char *command, char *envp[])
{
	//| split
	char **execs = command_parser(command);

	if (ft_strslen(execs) == 1)
	{
		exec_pro(execs[0]);
		return 1;
	}
	
	int fd[2];
	int pid;
	int fd_in = 0;

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
			execve("/bin/echo", ft_split(*execs, ' '), envp);
			wait(NULL);
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

int main(int argc, char *arg[], char *envp[])
{
	char str[] = "echo first > file.txt | echo -n second | echo -n third ; echo third";

	//; split
	char **commands = input_parser(str);
	while (*commands)
	{
		command_pro(*commands, envp);
		commands++;
	}

}