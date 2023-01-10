#include <unistd.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        
        // 1. Skip les espaces au debut
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        // 2. Boucle pour ecrire lettre par lettre
        while (str[i])
        {
            // 3. Si str[i] est n'est pas un espace, write str[i].
            if (str[i] != ' ' && str[i] != '\t')
                write(1,&str[i],1);

            //Si str[i] est un espace, et str[i + 1] aussi, skip le (i++)
            while ((str[i] == ' ' || str[i] == '\t') && (str[i+1] == ' ' || str[i+1] == '\t'))
                i++;

            // 4. On write si str[i] est un separateur suivi d'un ASCII. (hors espace)
            if ((str[i] == ' ' || str[i] == '\t') && (str[i+1] >= '!' && str[i+1] <= '~'))
                write(1,&str[i],1);
            i++;
        }
    }
    write(1,"\n",1);
}