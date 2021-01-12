#include "minishell.h"

int echo(int argc, char *argv[], char *envp[])
{
	int option;
	int i = 1;

	option = FALSE;
	if (!ft_strcmp(argv[1], "-n"))
		option = TRUE;
	while (i + option < argc - 1)
	{
		ft_write(1, argv[i + option]);
		ft_write(1, " ");
		i++;
	}
	if (option)
		ft_write(1, argv[i + option]);
	else 
		ft_write_n(1, argv[i + option]);
	g_last_ret = 0;
	return 0;
}