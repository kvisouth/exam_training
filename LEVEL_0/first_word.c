#include <unistd.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];

        //Skip les espaces et tabs au debut
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        //Write les lettres du mot tant que c'est pas str[i] n'est pas ' ', '\t' et '\0'
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
            write(1,&str[i++],1);
    }
    write (1,"\n",1);
}