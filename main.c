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
	
	//parent only work pipe location
	while (*execs)
	{
		printf("%d\n", ft_strslen(execs));
		
		int fd1[2], fd2[2];
		int pid;
		int state;
		
		pipe(fd1);
		pipe(fd2);
		pid = fork();

		if (pid == 0)
		{
			close(fd1[1]);
			close(fd2[0]);
			if(fd1[0] != 0)
			{
				//duplicate pipe in to string, so alread read
				dup2(fd1[0], 0);
				close(fd1[0]);
			}
			execve("/bin/echo", exec_parser(*execs), envp);
		}
		else //parent = shell
		{
			close(fd1[0]);
			close(fd2[1]);
			if (fd1[1] != 1) {
				//duplicate pipe out to stdout
				dup2(fd1[1], 1);
				close(fd1[1]);
			}
			//waitpid(pid, &state, 0);
		}
		execs++;	
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