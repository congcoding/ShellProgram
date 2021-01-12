#include "minishell.h"

static char	*get_key(char *arg, int *idx)
{
	char	*key;
	int		i;

	i = *idx;
	while (arg[i])
	{
		if (ft_strchr("<>|;\"\'\\ ", arg[i]))
		{
			key = ft_strndup(arg + *idx, i - *idx);
			*idx =  i - 1;
			return (key);
		}
		i++;
	}
	key = ft_strndup(arg + *idx, i - *idx);
	*idx = i - 1;
	return (key);
}

static char	enving(char *arg, char *new, int *idx, int *jdx)
{
	char	*key;
	char	*env;
	int		i;
	int		j;

	i = *idx;
	j = *jdx;
	if (arg[i + 1] == '?')
	{
		new[++j] = g_last_ret + '0';
		i++;
	}
	i++;
	key = get_key(arg, &i);
	env = get_env(g_envp, key);
	j += ft_strcpy(new + ++j, env) - 1;
	free(key);
	free(env);
	*idx = i;
	*jdx = j;
}

char		*argv_parsing(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = malloc(1000); // TODO : have to change
	while (arg[++i])
	{
		if (is_out(arg, i))
			continue;
		if (arg[i] == (-1 * '$'))
		{
			enving(arg, new, &i, &j);
			continue;
		}
		new[++j] = arg[i];
	}
	new[++j] = 0;
	return (new);
}
