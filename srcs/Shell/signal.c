/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/27 23:48:31 by jbeen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int signum)
{
	if (signum == SIGINT)
	{
		if (g_pid == 0)
		{
			kill(g_pid, SIGKILL);
			g_pid = 1;
			return ;
		}
		if (g_pid == 1)
		{
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
		ft_write(1, "Quit: 3");
		ft_write_n(1, "");
	}
}

void		sig_int(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
