/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:49:04 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 17:01:59 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(int argc, char *argv[], char *envp[])
{
	char	**env;
	int		i;

	argc++;
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
	g_last_ret = 0;
	ft_double_free(env);
	return (0);
}
