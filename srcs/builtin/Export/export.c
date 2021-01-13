#include "minishell.h"

static int valid_arg(char *env_string)
{
	int	i;

	i = -1;
	while (env_string[++i])
		if (env_string[i] == '=')
			return (TRUE);
	return (FALSE);
}

int export(char *argv[])
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!valid_arg(argv[i]))
			continue;
		if (set_env(g_envp, argv[i]) == FALSE)
			add_env(&g_envp, argv[i]);
	}
	g_last_ret = 0;
}