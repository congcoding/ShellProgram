/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:37 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 19:11:27 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(int argc, char *argv[], char *envp[])
{
	int	option;
	int	i;

	envp++;
	option = FALSE;
	if (!ft_strcmp(argv[1], "-n"))
		option = TRUE;
	i = 1;
	while (i + option < argc - 1)
	{
		ft_write(1, argv[i + option]);
		ft_write(1, " ");
		i++;
	}
	ft_write(1, argv[i + option]);
	if (!option)
		ft_write_n(1, "");
	g_last_ret = 0;
	return (0);
}
