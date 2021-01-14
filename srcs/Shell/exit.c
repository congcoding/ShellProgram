/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:03:56 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 22:51:55 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(void)
{
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
