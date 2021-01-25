/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:46:57 by seolim            #+#    #+#             */
/*   Updated: 2021/01/25 20:44:21 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ordering(char **envp)
{
	char	**order_env;
	char	*temp;
	int		i;
	int		j;

	if (!(order_env = ft_strsdup(envp)))
		return (NULL);
	i = -1;
	while (order_env[++i])
	{
		j = i;
		while (order_env[++j])
		{
			if (ft_strcmp(order_env[i], order_env[j]) > 0)
			{
				temp = order_env[i];
				order_env[i] = order_env[j];
				order_env[j] = temp;
			}
		}
	}
	return (order_env);
}

static int	declare(void)
{
	char	**order_env;
	char	**key_value;
	int		i;

	order_env = ordering(g_envp);
	i = -1;
	while (order_env[++i])
	{
		key_value = key_value_parse(order_env[i]);
		ft_write(1, "declare -x ");
		ft_write(1, key_value[0]);
		ft_write(1, "=\"");
		ft_write(1, key_value[1]);
		ft_write_n(1, "\"");
		ft_double_free(key_value);
	}
	ft_double_free(order_env);
	return (0);
}

static int	valid_key(char *env_string)
{
	if (ft_isnum(env_string[0]))
	{
		ft_write(1, "export: `");
		ft_write(1, env_string);
		ft_write_n(1, "': not valid identifier");
		return (FALSE);
	}
	return (TRUE);
}

static int	valid_arg(char *env_string)
{
	int	i;

	i = -1;
	while (env_string[++i])
		if (env_string[i] == '=')
			return (TRUE);
	return (FALSE);
}

int			export(char *argv[])
{
	int		i;

	i = 0;
	if (ft_strslen(argv) == 1)
		return (declare());
	while (argv[++i])
	{
		if (!valid_key(argv[i]))
			continue;
		if (!valid_arg(argv[i]))
			continue;
		if (set_env(g_envp, argv[i]) == FALSE)
			add_env(&g_envp, argv[i]);
	}
	g_last_ret = 0;
	return (0);
}
