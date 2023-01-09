#include <unistd.h>
#include <stdlib.h>
//Remplace la lettre s1 par la lettre s2 dans str.
//Write le tout

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int main (int ac, char **av)
{
    if (ac == 4 && !av[2][1] && !av[3][1])
    {
        char *str = av[1];
        char s1 = av[2][0];
        char s2 = av[3][0];
        int i = 0;

        while (str[i])
        {
            if (str[i] == s1)
                write(1, &s2, 1);
            else
                write(1, &str[i], 1);
            i++;
        }
    }
    write (1,"\n",1);
}