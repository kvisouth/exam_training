#include <stdlib.h>
#include <stdio.h>

int is_sep(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return (1);
    return(0);
}

int wdlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_sep(str[i]) == 1)
            return(i);
        i++;
    }
    return(i);
}

int tablen(char *str)
{
    int i = 0;
    int c = 0;
    while (str[i])
    {
        while (is_sep(str[i]) == 1 && str[i])
            i++;
        if (str[i])
            c++;
        while (is_sep(str[i]) == 0 && str[i])
            i++;
    }
    return(c);
}

char *word(char *str)
{
    int len = wdlen(str);
    int i = 0;
    char *new = malloc (len + 1);
    if (!new)
        return (NULL);
    while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return(new);
}

char **ft_split(char *str)
{
    int i = 0;
    char **split = malloc((tablen(str) + 1) * (sizeof(char *)));
    if (!split)
        return(NULL);
    while (*str)
    {
        while (is_sep(*str) == 1 && *str)
            str++;
        if (*str)
        {
            split[i] = word(str);
            i++;
        }
        while (is_sep(*str) == 0 && *str)
            str++;
    }
    split[i] = NULL;
    return(split);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char **split = ft_split(av[1]);
        while (split[i])
        {
            printf("%s\n",split[i]);
            i++;
        }
    }
}