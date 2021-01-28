/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:51:51 by seolim            #+#    #+#             */
/*   Updated: 2021/01/28 15:54:59 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_key(char *arg, int *idx)
{
	char	*key;
	int		i;

	i = *idx;
	while (arg[i])
	{
		if (ft_strchr("<>|;\"\'\\ -*#", arg[i]) || arg[i] == -'$')
		{
			key = ft_strndup(arg + *idx, i - *idx);
			*idx = i - 1;
			return (key);
		}
		i++;
	}
	key = ft_strndup(arg + *idx, i - *idx);
	*idx = i - 1;
	return (key);
}

static void	special_env(char *new, char special, int *idx, int *jdx)
{
	char	*num;
	int		i;
	int		j;

	i = *idx;
	j = *jdx;
	if (special == '$' || special == '?' || special == '#')
	{
		if (special == '$')
			num = ft_itoa(g_pid);
		else if (special == '?')
			num = ft_itoa(g_last_ret);
		else
			num = ft_itoa(0);
		++j;
		j += ft_strcpy(new + j, num) - 1;
		free(num);
		i++;
	}
	else if (special == '@' || ft_isnum(special) || special == '*')
		i++;
	*idx = i;
	*jdx = j;
}

static void	enving(char *arg, char *new, int *idx, int *jdx)
{
	char	*key;
	char	*env;
	int		i;
	int		j;

	i = *idx;
	j = *jdx;
	if (arg[i + 1] == '$' || arg[i + 1] == '?'
		|| arg[i + 1] == '#' || arg[i + 1] == '@'
		|| arg[i + 1] == '*' || ft_isnum(arg[i + 1]))
	{
		special_env(new, arg[i + 1], &i, &j);
		*idx = i;
		*jdx = j;
		return ;
	}
	i++;
	key = get_key(arg, &i);
	env = get_env(g_envp, key);
	++j;
	j += ft_strcpy(new + j, env) - 1;
	free(key);
	free(env);
	*idx = i;
	*jdx = j;
}

char		*argv_parsing(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = malloc(1024);
	while (arg[++i])
	{
		if (is_out(arg, i))
			continue;
		if (arg[i] == (-1 * '$'))
		{
			enving(arg, new, &i, &j);
			continue;
		}
		new[++j] = arg[i];
	}
	new[++j] = 0;
	return (new);
}
