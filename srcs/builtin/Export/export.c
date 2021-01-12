#include "minishell.h"

int export(char *argv[])
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (set_env(g_envp, argv[i]) == FALSE)
			add_env(&g_envp, argv[i]);
	}
	g_last_ret = 0;
}