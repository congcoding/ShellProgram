#include "minishell.h"

int is_piping(char **cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return (TRUE);
	return (FALSE);
}

int piping(char **cmd)
{
	int		i;
	
	i = -1;
	if (!is_piping(cmd))
	{
		single(cmd);
		return (0);
	}
	multi(cmd);
}
