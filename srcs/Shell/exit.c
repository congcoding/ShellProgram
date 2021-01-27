/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:03:56 by seolim            #+#    #+#             */
/*   Updated: 2021/01/27 17:22:44 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		arg_is_num(char *argv)
{
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (!ft_isnum(argv[i]))
			return (FALSE);
	}
	return (TRUE);
}

void	exit_code(char *argv[])
{
	if (ft_strslen(argv) == 1)
		return ;
	if (ft_strslen(argv) > 2)
	{
		ft_write_n(2, "exit: too many arguments");
		g_last_ret = 1;
		return ;
	}
	if (!arg_is_num(argv[1]))
	{
		ft_write(2, "exit: ");
		ft_write(2, argv[1]);
		ft_write_n(2, ": numeric argument required");
		g_last_ret = 2;
		return ;
	}
	else
		g_last_ret = ft_atoi(argv[1]);
}

int		ft_exit(char *argv[])
{
	if (argv)
		exit_code(argv);
	if (g_input)
		ft_double_free(g_input);
	if (g_argv)
		ft_double_free(g_argv);
	if (g_argv_p)
		ft_double_free(g_argv_p);
	if (g_cmd)
		ft_double_free(g_cmd);
	ft_double_free(g_envp);
	pipe_cmd_free();
	exit(g_last_ret);
}
