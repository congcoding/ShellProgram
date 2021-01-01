#include "minishell.h"

int red_parsing(char *exec, int fd[2])
{
	int		quote[2];
	int		is_slash;
	int		i;

	is_slash = FALSE;
	i = -1;
	while (exec[++i])
	{
		if (exec[i] == '\\')
		{
			is_slash = !is_slash;
			continue;
		}
		if (exec[i] == '\'' && !quote[1])
		{
			if (!is_slash && i != 0)
				;
			quote[0] = !quote[0];
		}
		if (exec[i] == '\"'&& !quote[0] && exec[i - 1] != '\\')
		{
			if (!is_slash && i != 0)
				;
			quote[1] = !quote[1];
		}
		is_slash = FALSE;
	}
	
}

int redirection(char *exec)
{
	int fd[2];
	int i;
	i = -1;
	ft_write_n(1, exec);
	//red_parsing(exec, fd);
	/*
	while (argv[++i])
		ft_write_n(1, argv[i]);
	*/
	/*
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