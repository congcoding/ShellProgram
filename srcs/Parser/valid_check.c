/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:17:28 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 18:27:04 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_token_check(char **token)
{
	if (!ft_strcmp(*(token + 1), "|") || !ft_strcmp(*(token + 1), ";")
	|| !ft_strcmp(*(token + 1), ">") || !ft_strcmp(*(token + 1), "<")
	|| !ft_strcmp(*(token + 1), ">>"))
	{
		ft_write(2, "syntax error near unexpected token `");
		ft_write(2, *token);
		ft_write_n(2, "\'");
		g_last_ret = 2;
		return (FALSE);
	}
	return (TRUE);
}

int		redi_check(char **input)
{
	if (!ft_strcmp(*input, ">") || !ft_strcmp(*input, "<")
		|| !ft_strcmp(*input, ">>"))
	{
		if (!ft_strcmp(*(input + 1), ">") || !ft_strcmp(*(input + 1), "<")
		|| !ft_strcmp(*(input + 1), ">>"))
		{
			ft_write_n(2, "syntax error near unexpected token `<\'");
			g_last_ret = 2;
		}
		else if (!*(input + 1))
		{
			ft_write_n(2, "syntax error near unexpected token `newline\'");
			g_last_ret = 2;
		}
		else if (!ft_strcmp(*(input + 1), "|") || !ft_strcmp(*(input + 1), ";"))
		{
			ft_write(2, "syntax error near unexpected token `");
			ft_write(2, *(input + 1));
			ft_write_n(2, "\'");
			g_last_ret = 2;
		}
		else
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);
}

int		input_check(char **input)
{
	if ((!ft_strcmp(*input, ";") || !ft_strcmp(*input, "|"))
		&& ft_strslen(input) == 1)
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, *input);
		g_last_ret = 2;
		return (FALSE);
	}
	while (*input)
	{
		if (!redi_check(input))
			return (FALSE);
		if (!strcmp(*input, ";") || !strcmp(*input, "|"))
			if (!is_token_check(input))
				return (FALSE);
		input++;
	}
	return (TRUE);
}
