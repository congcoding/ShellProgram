/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:57:43 by seolim            #+#    #+#             */
/*   Updated: 2021/01/15 14:22:36 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	std_backup(int fd[2], int backup[2])
{
	backup[0] = 20;
	backup[1] = 21;
	if (fd[0] != 0)
	{
		dup2(0, backup[0]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	if (fd[1] != 1)
	{
		dup2(1, backup[1]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
}

void	std_reset(int fd[2], int backup[2])
{
	if (fd[0] != 0)
		dup2(backup[0], 0);
	if (fd[1] != 1)
		dup2(backup[1], 1);
}

int		is_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"))
		return (TRUE);
	else
	{
		g_last_ret = 127;
		ft_write(2, cmd);
		ft_write_n(2, " : command not found");
		return (FALSE);
	}
}
