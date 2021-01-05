#include "lib.h"

int	ft_write(int fd, char *str)
{
	int len;

	if ((len = ft_strlen(str)) == -1)
		return (ERROR);
	write(fd, str, len);
	return (len);
}