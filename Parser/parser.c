#include "parser.h"

char **input_parser(char *str)
{
	return (ft_split(str, ';'));
}

char **command_parser(char *command)
{
	return (ft_split(command, '|'));
}

char **exec_parser(char *exec)
{
	return (ft_split(exec, ' '));
}