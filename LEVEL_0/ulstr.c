#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        int i = 0;
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            write (1, &str[i], 1);
            i++;
        }
    }
    write(1,"\n",1);
}