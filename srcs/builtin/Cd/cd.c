/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:46:31 by seolim            #+#    #+#             */
/*   Updated: 2021/01/25 20:17:12 by jbeen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_error(char *dir)
{
	ft_write(2, "cd: ");
	ft_write(2, dir);
	ft_write(2, ": ");
	ft_write_n(2, strerror(errno));
	g_last_ret = 1;
}

int			cd(char *dir)
{
	char	pwd[260];

	ft_strcpy(pwd, "PWD=");
	if (!dir)
		dir = get_env(g_envp, "HOME");
	if (chdir(dir))
	{
		cd_error(dir);
		return (FALSE);
	}
	if (!getcwd(pwd + 4, 255))
	{
		cd_error(dir);
		return (FALSE);
	}
	set_env(g_envp, pwd);
	g_last_ret = 0;
	return (TRUE);
}
