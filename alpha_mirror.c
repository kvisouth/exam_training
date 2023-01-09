#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];

        int i = 0;
        while (str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = 'Z' - str[i] + 'A';
            else if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = 'z' - str[i] + 'a';
            write (1, &str[i++], 1);
        }
    }
    write(1,"\n",1);
}