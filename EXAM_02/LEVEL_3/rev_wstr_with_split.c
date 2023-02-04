#include <unistd.h>
#include <stdlib.h>

int is_sep(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

int wdlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_sep(str[i]) == 1)
            return i;
        i++;
    }
    return i;
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
    return i;
}

char *word(char *str)
{
    int len = wdlen(str);
    int i = 0;
    char *new = malloc (len + 1);
    if (!new)
        return NULL;
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
    char **split = malloc((sizeof(char *))*(tablen(str) + 1));
    if (!split)
        return NULL;
    while (*str)
    {
        while (is_sep(*str) == 1 && *str)
            str++;
        if (*str)
            split[i++] = word(str);
        while (is_sep(*str) == 0 && *str)
            str++;
    }
    split[i] = NULL;
    return split;
}


//C'est split mais on a ajouter ca et modifier le main pour afficher split a l'envers.
//Vu que split c'est du par coeur c'est plus facile
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        char **split = ft_split(str);
        int i = 0;
        while (split[i])
            i++;
        i--;
        while (i >= 0)
        {
            ft_putstr(split[i]);
            if (i > 0)
                write(1," ",1);
            i--;
        }
    }
    write(1,"\n",1);
}