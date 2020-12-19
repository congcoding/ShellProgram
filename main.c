#include "minishell.h"

int main(int argc, char *arg[], char *envp[])
{
	char str[] = "grep ma < main.c | grep main > out.txt";

	//; split
	char **commands = input_parser(str);
	while (*commands)
	{
		piping(*commands, envp);
		commands++;
	}

}