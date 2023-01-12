#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Atoi qui ne gere QUE si la string n'est fait absoulument que un nombre positif.
int ft_atoi_du_pauvre(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i])
        nb = (nb*10 + str[i++]) - '0';
    return (nb);
}

void printhex(int n)
{
    char *nbr = "0123456789abcdef";
    if (n >= 16)
        printhex(n/16);
    write(1, &nbr[n%16], 1);
}

int main (int ac, char **av)
{
    if (ac == 2)
        printhex(ft_atoi_du_pauvre(av[1]));
    write(1, "\n", 1);
}