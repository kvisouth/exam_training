#include <unistd.h>

void ft_putnbr(int n)
{
    char nbr[10] = "0123456789";
    if (n > 9)
        ft_putnbr(n / 10);
    write(1, &nbr[n % 10], 1);
}

int main(int ac, char **av)
{
    (void)av;
    int nb = ac - 1;

    ft_putnbr(nb);
    write(1,"\n",1);
} 