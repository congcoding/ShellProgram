#include "parser.h"

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
	char	*temp;
	int		i;

	if (!(strs = malloc(sizeof(char *) * (len + 1))))
		return (NULL); //error process
	i = -1;
	while (++i < len)
	{
		temp = ft_stredup(str, cut[i], cut[i + 1]);
		strs[i] = ft_strtrim(temp, " ");
		printf("%d/%d/%s->%s\n", cut[i], cut[i + 1], temp, strs[i]);
		cut[i + 1]++;
		free(temp);
	}
	strs[i] = NULL;
	return (strs);
}

char 		**parser(char *raw, char c)
{
	int		quote[2];
	int		cut[255];
	int		is_slash;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	arr_init(cut, 255, -1);
	cut[0] = 0;
	arr_init(quote, 2, 0);
	is_slash = FALSE;
	str = ft_strtrim(raw, " ");
	while (str[++i])
	{
		if (str[i] == '\\')
		{
			is_slash = !is_slash;
			continue;
		}
		if (str[i] == '\'' && !quote[1])
		{
			if (!is_slash && i != 0)
				;
			quote[0] = !quote[0];
		}
		if (str[i] == '\"'&& !quote[0] && str[i - 1] != '\\')
		{
			if (!is_slash && i != 0)
				;
			quote[1] = !quote[1];
		}
		if (str[i] == c && !quote[0] && !quote[1] && !is_slash)
		{
			cut[++j] = i;
		}
		is_slash = FALSE;
	}
	cut[++j] = i;
	return parsing(str, cut, j);
}
