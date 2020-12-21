#include "minishell.h"

int cd(char *dir)
{
	char	pwd[260];

	ft_strcpy(pwd, "PWD=");
	if (chdir(dir))
		return ERROR; //errno process
	if (!getcwd(pwd + 4, 255))
		exit(1); //errno process
	set_env(g_envp, pwd);
	return SUCCESS;
}