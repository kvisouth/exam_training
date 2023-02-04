#include <stdlib.h>
//Du par coeur ngl

//Compte la longueur d'un nombre pour malloc dans str.
int nblen(int nb)
{
    int cpt = 0;

    if (nb < 0 || nb == 0)
    {
        cpt++;
        nb *= -1;
    }

    while (nb > 0)
    {
        cpt++;
        nb /= 10;
    }

    return(cpt);
}

//En gros on prend nb, et on met les chiffres dans str de droite a gauche.
//Pas besoin de verifier le int min pour exam
char *ft_itoa(int nbr)
{
    long nb = nbr; //on met nbr dans un long pour gerer int min int max, c'est pas verrifie dans grademe mais a l'examen il faut le faire je me suis fait avoir
    int i = nblen(nb);
    char *str = malloc(i + 1);
    if (!str)
        return(NULL);
    str[i--] = '\0';
    if (nb == 0)    //Verif egal a 0
        return(str[0] = '0', str);
    if (nb < 0)     //Verif negatif
    {
        str[0] = '-';
        nb *= -1;
    }
    while (nb > 0)
    {
        str[i--] = (nb % 10) + '0'; //On met le chiffre le plus a droite du nb dans str et on recule dans str.
        nb /= 10;   //On enleve ce chiffre pour reduire notre nb jusqua 0.
    }
    return(str);
}

// #include <stdio.h>
// int main (int ac, char **av)
// {
//     if (ac == 2)
//     {
//         printf("%s\n",ft_itoa(atoi(av[1])));
//     }
// }