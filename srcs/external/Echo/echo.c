/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:37 by seolim            #+#    #+#             */
/*   Updated: 2021/01/28 14:45:08 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_check(char *argv)
{
	int i;

	i = 1;
	while (argv[++i])
	{
		if (argv[i] != 'n')
			return (FALSE);
	}
	return (TRUE);
}

void	printing(int *i, char *argv[], int argc)
{
	int	is_start;
	int	idx;

	is_start = TRUE;
	idx = *i;
	while (idx < argc)
	{
		if (!ft_strcmp(argv[idx], ""))
		{
			idx++;
			continue;
		}
		if (!is_start)
			ft_write(1, " ");	
		ft_write(1, argv[idx]);
		idx++;
		is_start = FALSE;
	}
	*i = idx;
}

int	echo(int argc, char *argv[], char *envp[])
{
	int	option;
	int	i;

	envp++;
	option = FALSE;
	i = 1;
	while (!ft_strncmp(argv[i], "-n", 1))
	{
		if (option_check(argv[i]))
			option = TRUE;
		else
			break ;
		i++;
	}
	printing(&i, argv, argc);
	if (!option)
		ft_write_n(1, "");
	g_last_ret = 0;
	return (0);
}
