#include <unistd.h>
//Ecrire 1er mot apres le dernier mot.
//Ecrire le mot de debut a la fin.

int main(int ac, char **av)
{
	int i = 0;
	int start;
	int end;
	int flag = 0;
    char *str = av[1];
	
	if (ac > 1)
	{
        // 1. Placer 'i' sur la premiere lettre de str.
		while(str[i] == ' ' || str[i] == '\t')
			i++;

        // 2. Sauvegarder i dans start pour l'ecrire a la fin.
		start = i;

        // 3. Placer 'i' sur la derniere lettre de ce meme mot.
		while(str[i] && (str[i] != ' ' &&  str[i] != '\t'))
			i++;

        // 4. Sauvegarder i dans end pour ecrire de start a end a la fin.
		end = i;

        // 5. Skip les espaces apres le 1er mot.
		while(str[i] == ' ' || str[i] == '\t')
			i++;
        
        // 6. Ecrire la string jusqua la fin.
		while(str[i])
		{
			flag = 1;
            // Ne write pas un espace si suivi d'un autre espace (epur str)
            if ((str[i] == ' ' || str[i] == '\t') && (str[i+1] == ' ' || str[i+1] == '\t'))
                i++;
            else
			    write (1, &str[i++], 1);
		}

        // 7.Flag veut dire, il y a d'autres mots, donc si oui : write un espace
		if (flag == 1)
			write (1, " ", 1);

        // 8. Ecrit le mot sauvegarde au debut.
		while(start < end)
			write (1, &str[start++], 1);

	}	
	write (1, "\n",1);	
}