//Calcule le plus petit multiple commun (FR: PPCM, EN: LCM) entre 'a' et 'b'.

//Fait une boucle infinie qui se termine lorsque n sera un multiple de 'a' ET 'b'
//Elle incremente n tant que ce n'est pas le cas.
unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int n;

    if (!a || !b)
        return 0;
    if (a > b)
        n = a;
    else
        n = b;
    while(1)
    {
        if (n % a == 0 && n % b == 0)
            return n;
        n++;
    }
}

// Resultat attendu : 630
// #include <stdio.h>
// int main (void)
// {
//     unsigned int a = 35;
//     unsigned int b = 90;
//     printf("%d\n", lcm(a,b));
// }