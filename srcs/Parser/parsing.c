#include "minishell.h"

char **sep_space(char *line)
{
	int	i;
	int	j;
	int	cut[256];

	i = -1;
	j = -1;
	int_arr_init(cut, 255, -1);
	cut[++j] = 0;
	while (line[++i])
	{
		if (line[i] == ' ' && is_sep_space(line, i))
			cut[++j] = i;
	}
	cut[++j] = i;
	return cutting(line, cut, j);
}

int is_token_check(char **token)
{	
	if (!ft_strcmp(*(token + 1), "|") || !ft_strcmp(*(token + 1), ";"))
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, *token);
		g_last_ret = 2;
		return (FALSE);
	}
	return (TRUE);
}
/*
	Have to fix it  > < 관련
*/
int input_check(char **input)
{
	if ((!ft_strcmp(*input, ";") || !ft_strcmp(*input, "|"))
		&& ft_strslen(input) == 1)
	{
		ft_write(2, "syntax error near unexpected token ");
		ft_write_n(2, *input);
		g_last_ret = 2;
		return (FALSE);
	}
	while (*input)
	{
		if ((!ft_strcmp(*input, ">") || !ft_strcmp(*input, "<") 
		|| !ft_strcmp(*input, ">>")) && !*(input + 1))
		{
			ft_write_n(2, "syntax error near unexpected token \'newline\'");
			g_last_ret = 2;
			return (FALSE);
		}
		if (!strcmp(*input, ";") || !strcmp(*input, "|"))
			if (!is_token_check(input))
				return (FALSE);
		input++;
	}
	return (TRUE);
}

int pre_parsing(char *line, char ***input)
{
	if (!valid_quote(line))
		return (FALSE);
	line = space_line(line);
	*input = sep_space(line);
	free(line);
	if (!input_check(*input))
		return (FALSE);
	return (TRUE);
}