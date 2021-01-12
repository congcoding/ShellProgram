#include "minishell.h"

int shell(char **input)
{
	char	**cmd;
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], ";"))
		{
			cmd = ft_strsndup(input + start, i);
			start = i + 1;
			piping(cmd);
			ft_double_free(cmd);
		}
	}
	if (start != i)
	{
		cmd = ft_strsndup(input + start, i);
		piping(cmd);
		ft_double_free(cmd);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char	str[255];
	char	**input;
	int		i;

	sig_int();
	g_envp = init_envp(envp);
	g_last_ret = 0;
	while (TRUE)
	{	
		prompt(str);
		if (!pre_parsing(str, &input))
			continue;
		i = -1;
		shell(input);
		ft_double_free(input);
	}
	ft_double_free(g_envp);
}