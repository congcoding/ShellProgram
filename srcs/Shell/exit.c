#include "minishell.h"

int ft_exit()
{
	ft_double_free(g_envp);
	exit(0);
}