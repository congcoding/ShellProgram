#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	g_envp = init_envp(envp);
	printf("%s\n", get_env(g_envp, "PWD"));
	cd("./Env");
	printf("%s\n", get_env(g_envp, "PWD"));
	//; split
	/*
	char **commands = input_parser(str);
	while (*commands)
	{
		piping(*commands, envp);
		commands++;
	}
	*/
}