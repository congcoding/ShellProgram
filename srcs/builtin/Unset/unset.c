#include "minishell.h"

int		unset(char **argv)
{
	delete_env(&g_envp, argv[1]);
	return (0);
}