#include "lib.h"

int ft_strslen(char *strs[])
{
	int i;

	i = -1;
	if (!strs)
		return (ERROR);
	while (strs[++i])
		;
	return (i);
}