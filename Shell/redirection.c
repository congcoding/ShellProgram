#include "minishell.h"

static void arr_init(int *arr, int len, int var)
{
	int i;

	i = -1;
	while (++i < len)
		arr[i] = var;
}

int out_process(char **argv, int i)
{
	while (argv[0][++i])
	{
		
	}
}

int red_check(char **argv)
{
	int		quote[2];
	int		is_slash;
	int		i;

	arr_init(quote, 2, 0);
	is_slash = FALSE;
	i = -1;
	while (argv[0][++i])
	{
		if (argv[0][i] == '\\')
		{
			is_slash = !is_slash;
			continue;
		}
		if (argv[0][i] == '\'' && !quote[1])
		{
			if (!is_slash && i != 0)
				;
			quote[0] = !quote[0];
		}
		if (argv[0][i] == '\"'&& !quote[0] && argv[0][i - 1] != '\\')
		{
			if (!is_slash && i != 0)
				;
			quote[1] = !quote[1];
		}
		if (argv[0][i] == '>' && !quote[0] && !quote[1] && !is_slash)
			out_process(argv, i);
		if (argv[0][i] == '<' && !quote[0] && !quote[1] && !is_slash)
			in_process();
		is_slash = FALSE;
	}

}

int redirection(char *exec)
{
	char **argv;
	int i;
	
	i = -1;
	argv = parser(exec, ' ');
	while (argv[++i])
		red_check(&(argv[i]));
	ft_double_free(argv);
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