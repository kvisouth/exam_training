#include <stdlib.h>

//Verification si lettre est un separateur
int is_sep(char letter)
{
    if (letter == ' ' || letter == '\t' || letter == '\n')
        return (1);
    return (0);
}

//Retourne la longueur d'un mot (pr malloc dans strdup)
int wdlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_sep(str[i]) == 1)
            return (i);
        i++;
    }
    return (i);
}

//Retourne le nombre de mots dans str (pr malloc dans split)
int tablen(char *str)
{
    int i = 0;
    int cpt = 0;
    
    while (str[i])
    {
        while(is_sep(str[i] == 1 && str[i]))
            i++;
        if (str[i])
        {
            cpt++;
            i++;
        }
        while (is_sep(str[i] == 0) && str[i])
            i++;
    }
    return (cpt);
}

//strdup de 0 a sep
char *word(char *str)
{
    int len = wdlen(str);
    int i = 0;
    char *new = malloc(len + 1);
    if (!new)
        return(NULL);
    i = 0;
    while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}


//1. malloc la taille du tab de tab
//2. parcours *str jusqua \0
//3. dans while, check si on est sur sep ou \0
//4. on est sur un mot, strndup ce mot dans le 1er **tab & passe au prochain **tab
//5. vu quon a strndup notre mot, osef du mot dont incremente str jusaqua un sep ou un 0
char    **ft_split(char *str)
{
    char **split = malloc((sizeof(char *) * (tablen(str) + 1)));
    if (!split)
        return (NULL);
    int i = 0;
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
    return (split);
}

// #include <stdio.h>
// int main (int ac, char **av)
// {
//     int i = 0;
//     if (ac == 2)
//     {
//         char **split = ft_split(av[1]);
//         while (split[i])
//         {
//             printf("%s\n",split[i]);
//             i++;
//         }
//     }
// }