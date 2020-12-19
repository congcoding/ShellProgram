#include "lib.h"

char	*ft_strndup(char *src, int len)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}