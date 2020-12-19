#include "lib.h"

int ft_write_n(int fd, char *str)
{
	int len;

	if ((len = ft_strlen(str)) == -1)
		return (ERROR);
	write(fd, str, len);
	write(fd, "\n", 1);
	return (len + 1);
}