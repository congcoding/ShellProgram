#include "minishell.h"

int is_piping(char **command)
{
	int i;

	i = -1;
	while (command[++i])
		if (!strcmp(command[i], "|"))
			return (TRUE);
	return (FALSE);
}

int piping(char **command)
{
	int		i;
	
	i = -1;
	if (!is_piping(command))
	{
		single(command);
		return (0);
	}
	multi(command);
}
