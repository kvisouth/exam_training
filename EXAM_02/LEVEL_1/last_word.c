#include <unistd.h>

//En gros, dans un premier temps, on incremente i jusqu'a la fin.
// a chaque fois que i est un separateur et i+1 est une lettre, j prend la valeur de i+1
// C'est a dire la 1ere lettre d'un mot.
//
//Ensuite on write tant que j est un printable hors separateurs. (de ! a ~)
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