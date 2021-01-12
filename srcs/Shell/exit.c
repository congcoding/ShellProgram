#include "minishell.h"

int ft_exit()
{
	int i;

	ft_double_free(g_input);
	ft_double_free(g_argv);
	ft_double_free(g_argv_p);
	ft_double_free(g_cmd);
	ft_double_free(g_envp);
	if (g_pipe_cmd)
	{
		i = -1;
		while (g_pipe_cmd[++i])
			ft_double_free(g_pipe_cmd[i]);
		free(g_pipe_cmd);
	}
	exit(0);
}