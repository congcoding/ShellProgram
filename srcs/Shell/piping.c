#include "minishell.h"

int piping(char *command)
{
	char	**execs;
	int		fd[2];
	int		fd_in = 0;
	int		pid;
	int		i;

	execs = seperator(command, '|');
	
	if (ft_strslen(execs) == 1)
	{
		single(execs[0]);
		ft_double_free(execs);
		return 0;
	}
	multi(execs);
	ft_double_free(execs);
}
