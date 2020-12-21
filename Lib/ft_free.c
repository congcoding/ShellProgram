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