#include <unistd.h>

//En gros : Skip les espaces du debut
//Ecrit 3 espaces avant un mot.
//Et ecrit le mot.
int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        int flg;
        
        // 1. Skip les espaces du debut.
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        // 2. Boucle pour ecrire caractere par caracteres.
        while (str[i])
        {
            // 3. Si on est sur un espace, flg = 1.
            if (str[i] == ' ' || str[i] == '\t')
                flg = 1;

            // 4. Si on est sur une lettre (pas un espace).
            if (str[i] != ' ' && str[i] != '\t')
            {
                // 5. Alors, si flag est a 1, write 3 espaces.
                if (flg == 1)
                    write (1,"   ",3);
                // 6. Reset flag a 0
                flg = 0;
                // 7. Puis write la lettre.
                write(1,&str[i],1);
            }
            // 8. Puis passe a la lettre suivante.
            i++;
        }
    }
    write(1,"\n",1);
}

//La variable flg sers a ne mettre des espaces QUE avant des mots.
//Cela fait en sorte qu'on ne se retrouve pas avec 3 espaces a la fin
//si la fin de notre string est composee d'espaces.