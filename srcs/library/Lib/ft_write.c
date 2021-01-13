/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:23:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:23:39 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_write(int fd, char *str)
{
	int len;

	if ((len = ft_strlen(str)) == -1)
		return (ERROR);
	write(fd, str, len);
	return (len);
}
