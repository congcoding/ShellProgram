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
char	**ft_strsdup(char **src);
char	**ft_strsndup(char **src, int n);
char	*ft_strndup(char *src, int len);
char	*ft_stredup(char *src, int start, int end);
int 	ft_strcmp(char *s1, char *s2);
int		ft_strcpy(char *dest, char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char **strs, char c);
char	**ft_split(char const *s, char c);
void	ft_single_free(char *data);
void	ft_double_free(char **data);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(const char *s, int c);

char	*single_alloc(int len);
char	**double_alloc(int len);
char	***triple_alloc(int len);

#endif