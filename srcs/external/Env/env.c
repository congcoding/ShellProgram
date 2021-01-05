#include "minishell.h"

int		env(int argc, char *argv[], char *envp[])
{
	char	**env;
	int		i;
	
	env = init_envp(envp);
	i = 0;
	while (argv[++i])
	{
		if (set_env(env, argv[i]) == FALSE)
			add_env(&env, argv[i]);
	}
	i = -1;
	while (env[++i])
		ft_write_n(1, env[i]);
	free(env);
}