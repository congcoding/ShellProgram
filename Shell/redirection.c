#include "minishell.h"

int redirection(char *exec, char *envp[])
{
	char **argv = exec_parser(exec);
	int out_fd;
	int in_fd;

	if (!ft_strcmp(argv[2], "<"))
	{
		in_fd = open("./main.c", O_RDONLY);
		dup2(in_fd, 0);
	}

	if (!ft_strcmp(argv[ft_strslen(argv) - 2], ">"))
	{
		out_fd = open("./out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(out_fd, 1);
	}
	
	execl("/bin/grep", "grep", ft_split(exec, ' ')[1], NULL);
	//execve("/bin/grep", ft_split(exec, ' '), envp);
	close(in_fd);
	close(out_fd);
}