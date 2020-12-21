#include "minishell.h"

int main(int argc, char *arg[], char *envp[])
{
	char str[] = "echo one > two | echo three";

	//; split
	char **commands = input_parser(str);
	while (*commands)
	{
		piping(*commands, envp);
		commands++;
	}
}