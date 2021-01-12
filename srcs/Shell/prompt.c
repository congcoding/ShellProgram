#include "minishell.h"

static void arr_init(char str[255])
{
	int	i;

	i = -1;
	while (++i < 255)
		str[i] = 0;
}

int		prompt(char str[255])
{
	int i;

	arr_init(str);
	ft_write(1, "$> ");
	read(0, str, 255);
	i = -1;
	while(str[++i] != '\n')
		;
	str[i] = 0;
}