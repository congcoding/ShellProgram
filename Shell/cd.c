#include "minishell.h"

int cd(char *dir)
{
	char	pwd[260];

	ft_strcpy(pwd, "PWD=");
	if (chdir(dir))
		return FAIL;
	if (!getcwd(pwd + 4, 255))
		return FAIL;
	set_env(g_envp, pwd);
	return SUCCESS;
}