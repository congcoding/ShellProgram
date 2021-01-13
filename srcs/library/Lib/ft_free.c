/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:24:03 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:24:07 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_single_free(char *data)
{
	free(data);
}

void	ft_double_free(char **data)
{
	int i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}
