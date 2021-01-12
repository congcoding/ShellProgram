#include "minishell.h"

static int child(int fd_in, char ***pipe_cmd, int fd[2])
{
	dup2(fd_in, 0);
	if (*(pipe_cmd + 1))
		dup2(fd[1], 1);
	close(fd[0]);
	work(*pipe_cmd);
	child_exit();
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
			child(fd_in, pipe_cmd, fd);
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