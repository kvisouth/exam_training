int ft_atoi(char *str)
{
    int sym = 1;
    int nb = 0;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sym *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        nb = (nb * 10 + str[i++]) - '0';
    return (nb * sym);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main (int ac, char **av)
// {
//     if (ac == 2)
//     {
//         char *str = av[1];
//         printf("Real :%d\n",atoi(str));
//         printf("Mine :%d\n", ft_atoi(str));
//     }
// }