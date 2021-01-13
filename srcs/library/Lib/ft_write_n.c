/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:22:50 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:23:21 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_write_n(int fd, char *str)
{
	int len;

	if ((len = ft_strlen(str)) == -1)
		return (ERROR);
	write(fd, str, len);
	write(fd, "\n", 1);
	return (len + 1);
}
