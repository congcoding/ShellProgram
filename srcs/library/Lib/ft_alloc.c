/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:19:59 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 16:59:29 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*single_alloc(int len)
{
	char	*alloc;
	int		i;

	if (!(alloc = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len + 1)
		alloc[i] = '\0';
	return (alloc);
}

char	**double_alloc(int len)
{
	char	**alloc;
	int		i;

	if (!(alloc = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len + 1)
		alloc[i] = NULL;
	return (alloc);
}

char	***triple_alloc(int len)
{
	char	***alloc;
	int		i;

	alloc = NULL;
	if (!(alloc = malloc(sizeof(char **) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len + 1)
		alloc[i] = NULL;
	return (alloc);
}
