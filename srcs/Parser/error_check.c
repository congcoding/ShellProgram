/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:28:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 17:34:05 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_p(char *input)
{
	ft_write(2, "syntax error near unexpected token `");
	ft_write(2, input);
	ft_write_n(2, "\'");
	g_last_ret = 2;
}
