#include "env.h"

static char	**key_value_parse(char *env_string)
{
	char	**key_value;
	int		i;

	if (!(key_value = double_alloc(2)))
		exit(1); // errorno process;
	i = -1;
	while (++i < ft_strlen(env_string))
	{
		if ((env_string)[i] == '=')
		{
			if (!(key_value[0] = ft_strndup(env_string, i)))
				exit(1); // errorno process;
			if (!(key_value[1] = ft_strdup(env_string + i + 1)))
				exit(1); // errorno process;
		}
	}
	key_value[2] = NULL;
	return (key_value);
}

char		**init_envp(char *old_envp[])
{
	char	**envp;
	int		len;
	int		i;

	len = ft_strslen(old_envp);
	if (!(envp = double_alloc(len)))
		exit(1); // errorno process
	i = -1;
	while (++i < len)
	{
		if (!(envp[i] = ft_strdup(old_envp[i])))
			exit(1); // errorno process
	}
	envp[i] = NULL;
	return (envp);
}

char		*get_env(char *envp[], char *key)
{
	char	*env;
	int		i;

	if (key[0] == 0 || !key)
		return (ft_strdup(""));
	while (*envp)
	{
		i = -1;
		while (++i < ft_strlen(*envp))
		{
			if ((*envp)[i] == '=')
				if (!ft_strncmp(*envp, key, i - 1))
					return (ft_strdup(*envp + i + 1));
		}
		envp++;
	}
	return (ft_strdup(""));
}

int			set_env(char *envp[], char *env_string)
{
	int		i;
	char	**key_value;

	key_value = key_value_parse(env_string);
	while (*envp)
	{		
		i = -1;
		while (++i < ft_strlen(*envp))
		{
			if ((*envp)[i] == '=')
			{
				if (!ft_strncmp(*envp, key_value[0], i - 1))
				{
					free(*envp);
					if(!(*envp = ft_strdup(env_string)))
						exit(1); // errno process;
					ft_double_free(key_value);
					return (TRUE);
				}
			}
		}
		envp++;
	}
	ft_double_free(key_value);
	return (FALSE);
}

int			add_env(char ***envp, char *env_string)
{
	char	**new_envp;
	int		i;
	int		len;

	len = ft_strslen(*envp);
	if (!(new_envp = double_alloc(len + 1)))
		return (ERROR); // errno process
	i = -1;
	while (++i < len)
		new_envp[i] = ft_strdup((*envp)[i]);
	new_envp[i] = ft_strdup(env_string);
	new_envp[i + 1] = NULL;
	ft_double_free(*envp);
	*envp = new_envp;
	return (TRUE);
}

int			delete_env(char ***envp, char *key)
{
	char	**new_envp;
	char	**key_value;
	int		i;
	int		j;
	int		len;

	len = ft_strslen(*envp);
	if (!(new_envp = double_alloc(len)))
		return (ERROR); // errno process
	i = -1;
	j = -1;
	while (++i < len)
	{
		key_value = key_value_parse((*envp)[i]);
		if (!ft_strcmp(key_value[0], key))
		{
			ft_double_free(key_value);
			continue;
		}
		ft_double_free(key_value);
		new_envp[++j] = ft_strdup((*envp)[i]);
	}
	new_envp[++j] = 0;
	*envp = new_envp;
	return (TRUE);
}