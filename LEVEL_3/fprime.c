#include <stdlib.h>
#include <stdio.h>

//Printf les facteurs premiers d'un unsigned int en parametre.
//Exemple : ./fprime 42 
//Return  : 2*3*7$

int		main(int ac, char **av)
{
    if(ac == 2)
    {

        int nb = atoi(av[1]);

        //Cas special nb negatif
        if (nb < 0)
            return(printf("\n"), 0);

        //Cas special nb = 1
        if (nb == 1)
            printf("1");
        
        //Le vrai programme
        else
        {
            int prime = 2;
            while (nb > 1)
            {
                if (nb % prime == 0)
                {
                    printf("%d", prime);
                    nb /= prime;
                    if (nb > 1) // Pour pas mettre de '*' a la fin.
                        printf("*");
                    prime--;
                }
                prime++;
            }
        }
    }
    printf("\n");
}