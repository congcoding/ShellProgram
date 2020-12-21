#include "lib.h"

int ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (ERROR);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}