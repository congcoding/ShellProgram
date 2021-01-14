/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:21:27 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 21:24:07 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char *ft_strappend(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		str[++j] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[++j] = s2[i];
	return (str);
}