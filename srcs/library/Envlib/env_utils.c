/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:38:44 by seolim            #+#    #+#             */
/*   Updated: 2021/01/25 14:17:51 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		**key_value_parse(char *env_string)
{
	char	**key_value;
	int		i;

	if (!(key_value = double_alloc(2)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(env_string))
	{
		if ((env_string)[i] == '=')
		{
			if (!(key_value[0] = ft_strndup(env_string, i)))
				return (NULL);
			if (!(key_value[1] = ft_strdup(env_string + i + 1)))
				return (NULL);
			break ;
		}
	}
	key_value[2] = NULL;
	return (key_value);
}

char		*init_shlvl(char *old_env)
{
	char	*env;
	char	**key_value;
	int		num;
	char	*lvl;

	if (!(key_value = key_value_parse(old_env)))
		return (NULL);
	if (!ft_strcmp(key_value[0], "SHLVL"))
	{
		num = ft_atoi(key_value[1]);
		lvl = ft_itoa(num + 1);
	}
	else
	{
		ft_double_free(key_value);
		return (NULL);
	}
	env = ft_strappend("SHLVL=", lvl);
	ft_double_free(key_value);
	ft_single_free(lvl);
	return (env);
}
