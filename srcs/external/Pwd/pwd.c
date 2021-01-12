#include "minishell.h"

int pwd(int argc, char *argv[], char *envp[])
{
	char *pwd;
	
	if (!(pwd = get_env(envp, "PWD")))
	{
		ft_write_n(2, "pwd allocation error");
		g_last_ret = 2;
		return (1);
	}
	g_last_ret = 0;
	ft_write_n(1, pwd);
	return (0);
}