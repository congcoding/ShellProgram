#include "minishell.h"

int shell(char **input)
{
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], ";"))
		{
			g_cmd = ft_strsndup(input + start, i);
			start = i + 1;
			piping(g_cmd);
			ft_double_free(g_cmd);
		}
	}
	if (start != i)
	{
		g_cmd = ft_strsndup(input + start, i);
		piping(g_cmd);
		ft_double_free(g_cmd);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char	str[255];
	int		i;

	sig_int();
	g_envp = init_envp(envp);
	g_pipe_cmd = NULL;
	g_last_ret = 0;
	while (TRUE)
	{	
		prompt(str);
		if (!pre_parsing(str, &g_input))
			continue;
		i = -1;
		shell(g_input);
		ft_double_free(g_input);
	}
	ft_double_free(g_envp);
}