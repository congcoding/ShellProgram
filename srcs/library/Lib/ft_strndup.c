/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:25:31 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:33:35 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strndup(char *src, int len)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_stredup(char *src, int start, int end)
{
	char	*dest;
	int		i;
	int		j;

	if (!(dest = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = start - 1;
	j = -1;
	while (++i < end)
		dest[++j] = src[i];
	dest[++j] = 0;
	return (dest);
}
