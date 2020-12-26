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
	//have to get Redirection & clean it
	return (ft_split(exec, ' '));
}

static void arr_init(int *arr, int len, int var)
{
	int i;

	i = -1;
	while (++i < len)
		arr[i] = var;
}

char		**parsing(char *str, int *cut, int len)
{
	char	**strs;
	int		i;

	if (!(strs = malloc(sizeof(char *) * (len + 1))))
		return (NULL); //error process
	i = -1;
	while (++i < len)
		strs[i] = ft_stredup(str, cut[i], cut[i + 1]);
	strs[i] = NULL;
	return (strs);
}

char 		**parser(char *raw, char c)
{
	int		quote[2];
	int		cut[255];
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	arr_init(cut, 255, -1);
	cut[0] = 0;
	arr_init(quote, 2, 0);
	str = ft_strtrim(raw, " ");
	while (str[++i])
	{
		if (str[i] == '\'' && !quote[1])
		{
			if (str[i - 1] == '\\' && i != 0)
				;
			quote[0] = !quote[0];
		}
			
		if (str[i] == '\"'&& !quote[0] && str[i - 1] != '\\')
		{
			if (str[i - 1] == '\\' && i != 0)
				;
			quote[1] = !quote[1];
		}
		if (str[i] == c && !quote[0] && !quote[1] && str[i - 1] != '\\')
			cut[++j] = ++i;
	}
	cut[++j] = ++i;
	return parsing(str, cut, j);
}
