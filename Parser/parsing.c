#include "minishell.h"

int quotes(char *line, int idx)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (line[i] && i != idx)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (quote == 0 && line[i] == '\'')
			quote = 1;
		else if (quote == 0 && line[i] == '\"')
			quote = 2;
		else if (quote == 1 && line[i] == '\'')
			quote = 0;
		else if (quote == 2 && line[i] == '\"')
			quote = 0;
		i++;
	}
	return (quote);
}

int		is_sep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("<>|;", line[i]))
		return (0);
	else if (ft_strchr("<>|;", line[i]) && quotes(line, i) == 0)
		return (1);
	else
		return (0);
}

char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			count++;
		i++;
	}
	if (!(new = malloc(sizeof(char) * (i + 2 * count + 1))))
		return (NULL);
	return (new);
}

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{
		if (quotes(line, i) != 1 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && line[i] == '>')
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	
	return (new);
}

int	valid_quote(char *line)
{
	if (quotes(line, 256))
	{
		ft_write_n(2, "syntax error : open quote");
		ft_single_free(line);
		g_last_ret = 2;
		return (FALSE);
	}
	return (TRUE);
}

void arr_init(int *arr, int len, int var)
{
	int i;

	i = -1;
	while (++i < len)
		arr[i] = var;
}

char **cutting(char *str, int *cut, int len)
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
		cut[i + 1]++;
		free(temp);
	}
	strs[++i] = NULL;
	return (strs);
}

char **seperator(char *line, char c)
{
	int i;
	int	j;
	int cut[256];

	i = -1;
	j = -1;
	arr_init(cut, 255, -1);
	cut[++j] = 0;
	while (line[++i])
	{
		if (line[i] == c && is_sep(line, i))
			cut[++j] = i;
	}
	cut[++j] = i;
	return cutting(line, cut, j);
}

int parsing(char *line)
{
	//get_next_line(0, &line); //TODO : gnl error fixing
	/* open quote check */
	if (!valid_quote(line))
		return (0);
	
	/* spacing before & after ;<>| */
	line = space_line(line);
	
	char **par = seperator(line, ';');
}



