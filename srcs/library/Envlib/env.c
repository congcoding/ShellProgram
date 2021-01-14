/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:37:55 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 22:42:05 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		**init_envp(char *old_envp[])
{
	char	**envp;
	int		len;
	int		i;

	len = ft_strslen(old_envp);
	if (!(envp = double_alloc(len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(envp[i] = ft_strdup(old_envp[i])))
			return (NULL);
	}
	envp[i] = NULL;
	return (envp);
}

char		*get_env(char *envp[], char *key)
{
	char	*env_key;
	int		i;

	if (key[0] == 0 || !key)
		return (ft_strdup(""));
	while (*envp)
	{
		i = -1;
		while (++i < ft_strlen(*envp))
			if ((*envp)[i] == '=')
			{
				env_key = ft_strndup(*envp, i);
				if (!ft_strcmp(env_key, key))
				{
					free(env_key);
					return (ft_strdup(*envp + i + 1));
				}
				free(env_key);
				break ;
			}
		envp++;
	}
	return (ft_strdup(""));
}

int			set_env(char *envp[], char *env_string)
{
	int		i;
	char	**key_value;

	key_value = key_value_parse(env_string);
	while (*envp)
	{
		i = -1;
		while (++i < ft_strlen(*envp))
		{
			if ((*envp)[i] == '=')
			{
				if (!ft_strncmp(*envp, key_value[0], i - 1))
				{
					free(*envp);
					if (!(*envp = ft_strdup(env_string)))
						return (FALSE);
					ft_double_free(key_value);
					return (TRUE);
				}
			}
		}
		envp++;
	}
	ft_double_free(key_value);
	return (FALSE);
}

int			add_env(char ***envp, char *env_string)
{
	char	**new_envp;
	int		i;
	int		len;

	len = ft_strslen(*envp);
	if (!(new_envp = double_alloc(len + 1)))
		return (FALSE);
	i = -1;
	while (++i < len)
		new_envp[i] = ft_strdup((*envp)[i]);
	new_envp[i] = ft_strdup(env_string);
	new_envp[i + 1] = NULL;
	ft_double_free(*envp);
	*envp = new_envp;
	return (TRUE);
}

int			delete_env(char ***envp, char *key)
{
	char	**new_envp;
	char	**key_value;
	int		i;
	int		j;

	if (!(new_envp = double_alloc(ft_strslen(*envp))))
		return (FALSE);
	i = -1;
	j = -1;
	while (++i < ft_strslen(*envp))
	{
		key_value = key_value_parse((*envp)[i]);
		if (!ft_strcmp(key_value[0], key))
		{
			ft_double_free(key_value);
			continue;
		}
		ft_double_free(key_value);
		new_envp[++j] = ft_strdup((*envp)[i]);
	}
	new_envp[++j] = 0;
	ft_double_free(*envp);
	*envp = new_envp;
	return (TRUE);
}
