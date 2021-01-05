#include "lib.h"

char	*ft_strjoin(char **strs, char c)
{
	char	*str;
	int		total_len;
	int		strs_len;
	int		i;
	int		j;
	
	strs_len = ft_strslen(strs);
	total_len = 0;
	i = -1;
	while (++i < strs_len)
		total_len += ft_strlen(strs[i]);
	if (!(str = malloc(sizeof(char) * (total_len + strs_len))))
		return (NULL);
	i = -1;
	total_len = -1;
	while (++i < strs_len)
	{
		j = -1;
		while (strs[i][++j])
			str[++total_len] = strs[i][j];
		str[++total_len] = c;
	}
	str[total_len] = 0;
	return (str);
}