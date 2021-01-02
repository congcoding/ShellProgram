#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	str[255];
	char	**input;
	char	**pipe;
	int		i;

	sig_int();
	g_envp = init_envp(envp);
	while (TRUE)
	{	
		prompt(str);
		input = parser(str, ';');
		i = -1;
		while (input[++i])
			piping(input[i]);;
		ft_double_free(input);
	}
}