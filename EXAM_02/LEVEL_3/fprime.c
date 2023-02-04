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
                //Si prime est un diviseur de nb.
                if (nb % prime == 0)
                {
                    // 1. Print le diviseur (prime)
                    printf("%d", prime);

                    // 2. Divise nb par prime.
                    nb /= prime;

                    // 3. Print un '*' si nb > 1
                    if (nb > 1)
                        printf("*");

                    // 4. Decremente prime de 1.
                    prime--;
                }
                prime++;
            }
        }
    }
    printf("\n");
}