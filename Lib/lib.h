#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include "macro.h"

int		ft_strlen(char *str);
int 	ft_strslen(char *strs[]);
int		ft_write(int fd, char *str);
int		ft_write_n(int fd, char *str);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int len);
int 	ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char **strs, char c);
char	**ft_split(char const *s, char c);

#endif