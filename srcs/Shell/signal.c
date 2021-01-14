/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 17:29:51 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle(int signum)
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
			ft_write_n(1, "");
			ft_write(1, "$> ");
		}
		else
			ft_write_n(1, "\b\b");
	}
}

static void	none(int signum)
{
	signum++;
	ft_write(1, "\b\b");
}

void		sig_int(void)
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
	signal(SIGQUIT, none);
}
