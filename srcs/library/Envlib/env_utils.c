/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:38:44 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 17:00:32 by seolim           ###   ########.fr       */
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
