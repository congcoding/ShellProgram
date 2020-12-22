#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	g_envp = init_envp(envp);

	char str[] = "cd Env";

	char **input = input_parser(str);
	while (*input)
	{
		piping(*input);
		input++;
	}
}