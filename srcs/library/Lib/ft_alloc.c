#include "lib.h"

char	*single_alloc(int len)
{
	char *alloc;

	if (!(alloc = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (alloc);
}

char	**double_alloc(int len)
{
	char **alloc;
	int i;
	
	if (!(alloc = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len + 1)
		alloc[i] = NULL;
	return (alloc);
}

char	***triple_alloc(int len)
{
	char ***alloc;

	alloc = NULL;
	if (!(alloc = malloc(sizeof(char **) * (len + 1))))
		return (NULL);
	int i;
	i = -1;
	while (++i < len + 1)
		alloc[i] = NULL;
	return (alloc);
}
