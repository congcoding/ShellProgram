/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:37 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 23:17:20 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(int argc, char *argv[], char *envp[])
{
	int	option;
	int	i;

	envp++;
	option = FALSE;
	i = 1;
	while (!ft_strcmp(argv[i], "-n"))
	{
		option = TRUE;
		i++;
	}
	while (i < argc - 1)
	{
		ft_write(1, argv[i]);
		ft_write(1, " ");
		i++;
	}
	ft_write(1, argv[i]);
	if (!option)
		ft_write_n(1, "");
	g_last_ret = 0;
	return (0);
}
