#include "minishell.h"

int redirection(char *exec)
{
	char **argv;
	int i;

	//argv = parser(exec, ' ');
	/*
	if (!ft_argv[0]cmp(argv[2], "<"))
	{
		in_fd = open("./main.c", O_RDONLY);
		dup2(in_fd, 0);
	}

	if (!ft_strcmp(argv[ft_strslen(argv) - 2], ">"))
	{
		out_fd = open("./out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(out_fd, 1);
	}
	*/
	/*
	if (!ft_strcmp(argv[0], "cd"))
		cd(argv[1]);
	if (!ft_strcmp(argv[0], "echo"))
		echo(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "env"))
		env(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "pwd"))
		pwd(ft_strslen(argv), argv, g_envp);
	if (!ft_strcmp(argv[0], "export"))
		export(argv);
	*/
	
	//close(in_fd);
	//close(out_fd);
}