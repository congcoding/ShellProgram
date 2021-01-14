/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:49:04 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 18:32:54 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_arg(char *env_string)
{
	int	i;

	i = -1;
	while (env_string[++i])
		if (env_string[i] == '=')
			return (TRUE);
	return (FALSE);
}

static int	error_a(char *argv, char **env)
{
	ft_write(2, "env: '");
	ft_write(2, argv);
	ft_write_n(2, "': No such file or directory");
	ft_double_free(env);
	g_last_ret = 127;
	return (0);
}

int			env(int argc, char *argv[], char *envp[])
{
	char	**env;
	int		i;

	argc++;
	env = init_envp(envp);
	i = 0;
	while (argv[++i])
		if (!valid_arg(argv[i]))
			return (error_a(argv[i], env));
	i = 0;
	while (argv[++i])
	{
		if (set_env(env, argv[i]) == FALSE)
			add_env(&env, argv[i]);
	}
	i = -1;
	while (env[++i])
		ft_write_n(1, env[i]);
	g_last_ret = 0;
	ft_double_free(env);
	return (0);
}
