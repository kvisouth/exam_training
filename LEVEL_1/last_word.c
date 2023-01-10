#include <unistd.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        int i = 0;
        int j = 0;

        while(str[i])
        {
            // j = le caractere apres un separateur (debut d'un mot)
            if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] >= '!' && str[i + 1] <= '~'))
                j = i + 1;
            i++;
        }
        // write tant que str[i] est printable (sauf '\t' et ' ')
        while (str[j] >= '!' && str[j] <= '~')
            write(1, &str[j++], 1);
    }
    write(1, "\n", 1);
}