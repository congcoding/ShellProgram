/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:10 by seolim            #+#    #+#             */
/*   Updated: 2021/01/15 14:21:54 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_piping(char **cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
		if (!ft_strcmp(cmd[i], "|"))
			return (TRUE);
	return (FALSE);
}

int	piping(char **cmd)
{
	if (!is_piping(cmd))
	{
		single(cmd);
		return (0);
	}
	multi(cmd);
	return (0);
}
