#include <unistd.h>

void ft_putchar(int c)
{
    write(1, &c, 1);
}

int main (int ac, char **av)
{
    char *str = av[1];

    if (ac == 2)
    {
        int i = 0;
        while (str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Y')
                ft_putchar(str[i] + 1);
            else if (str[i] >= 'a' && str[i] <= 'y')
                ft_putchar(str[i] + 1);
            else if (str[i] == 'Z' || str[i] == 'z')
                ft_putchar(str[i] - 25);
            else
                ft_putchar(str[i]);
            i++;
        }
    }
    write(1,"\n",1);
}