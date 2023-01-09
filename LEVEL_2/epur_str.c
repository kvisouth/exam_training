#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return(1);
    return(0);
}

int is_ascii(char c)
{
    if (c >= 32 && c <= 126)
        return(1);
    return(0);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        
        //On ignore les separateurs au debut de la string
        while (is_space(str[i]) == 1)
            i++;

        while (str[i])
        {
            //On write si str[i] n'est pas un separateur.
            if (is_space(str[i]) == 0)
                write(1,&str[i],1);

            //Tant que str[i] et str[i + 1] est un separateur, on i++.
            while (is_space(str[i]) == 1 && is_space(str[i + 1]) == 1)
                i++;

            //On write si str[i] est un separateur suivi d'un ASCII.
            if (is_space(str[i]) == 1 && is_ascii(str[i + 1]) == 1)
                write(1,&str[i],1);
            i++;
        }
    }
    write(1,"\n",1);
}