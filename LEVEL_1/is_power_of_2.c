//Check si n est egal a 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048 etc..
//Si c'est le cas, retourne 1
//Si non, multiplie nb par 2, jusqu'a qu'il depasse n, notre parametre de base.

int is_power_of_2(unsigned int n)
{
    unsigned int nb = 1;
    int ntm = n;
    if (ntm < 0) //trop relou
        return 0;
    while(nb <= n)
    {
        if (nb == n)
            return 1;
        nb *= 2;
    }
    return 0;
}
