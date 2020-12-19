#include "lib.h"

int ft_strlen(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (ERROR);
	while (str[++i])
		;
	return (i);
}

