/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/30 10:13:12 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int signum)
{
	if (signum == SIGINT)
	{
		if (g_pid == 0)
		{
			kill(g_pid, SIGINT);
			g_pid = 1;
			return ;
		}
		if (g_pid == 1)
		{
			g_last_ret = 130;
			ft_write(1, "\b\b  ");
			ft_write_n(1, "");
			ft_write(1, "$> ");
		}
		else
			ft_write_n(1, "");
	}
}

static void	handle_sigquit(int signum)
{
	signum++;
	if (g_pid == 1)
		ft_write(1, "\b\b  \b\b");
	else
	{
		g_last_ret = 130;
		ft_write(1, "Quit: 3");
		ft_write_n(1, "");
	}
}

void		sig_int(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
