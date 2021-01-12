#include "minishell.h"

char	***pipe_alloc(char **input)
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
	if (!(pipe_cmd = triple_alloc(len)))
		return (NULL);
	return (pipe_cmd);
}

void	child_exit()
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