#include <unistd.h>
//Transforme une str de format lowerCamelCase en snake_case.
//Exemple : yoLesAmisCaVa
//Retourne: yo_les_amis_ca_va

//Transforme en minuscule str[i] majuscule
//Et write un underscore.
//Puis write str[i] transformer ou non
int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        while (str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
                write(1, "_", 1);
            }
            write(1, &str[i++], 1);
        }
    }
    write (1, "\n", 1);
}