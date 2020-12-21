#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "macro.h"

int		ft_strlen(char *str);
int 	ft_strslen(char *strs[]);
int		ft_write(int fd, char *str);
int		ft_write_n(int fd, char *str);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int len);
int 	ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char **strs, char c);
char	**ft_split(char const *s, char c);
void	ft_single_free(char *data);
void	ft_double_free(char **data);

#endif