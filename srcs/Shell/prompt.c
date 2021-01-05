#include "minishell.h"

int		prompt(char str[255])
{
	int i;

	ft_write(1, "$> ");
	read(0, str, 255);
	i = -1;
	while(str[++i] != '\n')
		;
	str[i] = 0;
}