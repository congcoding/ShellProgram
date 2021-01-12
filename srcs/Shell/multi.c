#include "minishell.h"

static void child_exit()
{
	int i;

	ft_double_free(g_cmd);
	ft_double_free(g_input);
	ft_double_free(g_envp);
	i = -1;
	while (g_pipe_cmd[++i])
		ft_double_free(g_pipe_cmd[i]);
	free(g_pipe_cmd);
	exit(g_last_ret);
}

static int work2(char **argv, int fd[2], int backup[2])
{
	char	**argv_p;
	int		i;

	if (!(argv_p = malloc(sizeof(char *) * (ft_strslen(argv) + 1))))
		return (FALSE);
	i = -1;
	while (argv[++i])
		argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(argv_p[0]))
		return (FALSE);
	if (!ft_strcmp(argv_p[0], "echo"))
		echo(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "env"))
		env(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "pwd"))
		pwd(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "cd"))
		cd(argv_p[1]);
	if (!ft_strcmp(argv_p[0], "export"))
		export(argv_p);
	if (!ft_strcmp(argv_p[0], "unset"))
		unset(argv_p);
	if (!ft_strcmp(argv_p[0], "exit"))
		ft_exit();
	ft_double_free(argv_p);
	return (TRUE);
}

static int work(char **cmd)
{
	char	**argv;
	int		fd[2];
	int		backup[2];
	
	fd[0] = 0;
	fd[1] = 1;
	if (!(argv = redirection(cmd, fd)))
		return (FALSE);
	if (!work2(argv, fd, backup))
		return (FALSE);
	ft_double_free(argv);
	std_reset(fd, backup);
	return (TRUE);
}

int pipe_processing(char ***pipe_cmd)
{
	int fd[2];
	int fd_in;
	int pid;
	int state;
	
	fd_in = 0;
	while (*pipe_cmd)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			ft_write_n(2, "piping error");
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(pipe_cmd + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			work(*pipe_cmd);
			child_exit();
		}
		else
		{
			wait(&state);
			g_last_ret = state / 256;
			close(fd[1]);
			fd_in = fd[0];
			pipe_cmd++;
		}
	}
}

char ***pipe_alloc(char **input)
{
	char	***pipe_cmd;
	int		i;
	int		len;

	i = -1;
	len = 1;
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
			len +=1;
	}
	if (!(pipe_cmd = malloc(sizeof(char **) * (len + 1))))
		return (NULL);
	return (pipe_cmd);
}

int multi(char **input)
{
	int		start;
	int		i;
	int		j;

	i = -1;
	j = -1;
	start = 0;
	g_pipe_cmd = NULL;
	if (!(g_pipe_cmd = pipe_alloc(input)))
		return (FALSE);
	while (input[++i])
	{
		if (!strcmp(input[i], "|"))
		{
			g_pipe_cmd[++j] = ft_strsndup(input + start, i);
			start = i + 1;
		}
	}
	if (start != i)
		g_pipe_cmd[++j] = ft_strsndup(input + start, i);
	g_pipe_cmd[++j] = NULL;
	pipe_processing(g_pipe_cmd);
}