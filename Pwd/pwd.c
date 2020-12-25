#include "minishell.h"

int pwd(int argc, char *argv[], char *envp[])
{
	char *pwd;
	
	if (!(pwd = get_env(envp, "PWD")))
		exit(0); //errno 처리
	ft_write_n(1, pwd);
}