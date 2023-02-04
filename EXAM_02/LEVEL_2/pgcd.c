#include <stdlib.h>
#include <stdio.h>


int main (int ac, char **av)
{
    int a;
    int b;

    if (ac == 3)
    {
        a = atoi(av[1]);
        b = atoi(av[2]);
        if (a > 0 && b > 0)
        {
            //Tant que a et b sont pas egaux
            while (a != b)
            {
                //Soustrait 'b' a 'a' si a est plus grand que b
                if (a > b)
                    a -= b;
                //Soustrait 'a' a 'b' si l'inverse
                else
                    b -= a;
            }
            printf("%d",a);
        }
    }
    printf("\n");
}