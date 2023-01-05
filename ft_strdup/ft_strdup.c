#include <stdlib.h>

char *ft_strdup(char *src)
{
    int len = 0;
    while (src[len])
        len++;
    
    char *new = malloc(len + 1);
    int i = 0;
    while (src[i])
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

// #include <stdio.h>
// int main (int ac, char **av)
// {
//     if (ac == 2)
//     {
//         char *str = av[1];
//         char *new = ft_strdup(str);
//         printf("%s\n", new);
//     }
// }