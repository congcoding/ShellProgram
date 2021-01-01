#include "lib.h"

static int  check_word_in(char c, char const *set)
{
    int i;

    i = 0;
    while (*(set + i))
    {
        if (c == *(set + i))
            return (1);
        i++;
    }
    return  (0);
}

static char *ft_strdup_start_end(char const *src, int start, int end)
{
    char    *dest;
    int     i;
    
    i = -1;
    if((dest = malloc(sizeof(char) * (end - start + 1))) == 0)
        return (0);
    if (start == (end + 1))
        return (0);
    while (++i < (end - start))
        *(dest + i) = *(src + start + i);
    *(dest + i) = 0;
    return (dest);
}

char		*ft_strtrim(char *s1, char *set)
{
    int start;
    int end;

    end = ft_strlen(s1);
    start = 0;
    while (*(s1 + start) && check_word_in(*(s1 + start), set))
        start++;
    while (end >= start && check_word_in(*(s1 + end - 1), set))
        end--;
    return (ft_strdup_start_end(s1, start, end));
}