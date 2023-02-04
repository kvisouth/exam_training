#include <unistd.h>
//Ecrire une phrase, avec les mots a l'envers. Mais les mots sont a l'endroits.
//Durant les test, il y aura toujours que 1 espace/tab et il n'y en aura pas a la fin ni au debut.
//Exemple : Yo les mec
//Devient : mec les Yo

int main(int ac, char **av)
{
	int start;
	int end;
	int i = 0;
	int flg = 0;
		
	if(ac == 2)
	{   
		char *str = av[1];

		// 1. On cale i sur la fin de la string.
		while(str[i] != '\0')
			i++;
		
		// 2. Boucle de la fin, jusqu'au debut pour str[i]
		while(i >= 0)
		{
			// 3. On recule i tant que str[i] n'est pas une lettre
			while( str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
				i--;

			// 4. On sauvegarde la position de i car str[i] est forcement la derniere lettre d'un mot
			end = i;
			
			// 5. On recule i tant que str[i] n'est pas un separateur (une lettre)
			while(str[i] && str[i] != ' ' && str[i] != '\t')
				i--;

			// 6. On sauvegarde la position de i+1 (premierre lettre) car i est sur l'espace avant cette lettre (d'ou le +1)
			start = i + 1;

			// 7. On met flg a 1 pour write un espace apres avoir ecrit le mot
			flg = 1;

			// 8. On write le mot de start a end.
			while(start <= end)
			{
				write (1, &str[start],1);
				start++;		
			}

			// 9. On write un espace si flg est egal a 1
			if (flg != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}

//flg est la pour eviter qu'on mette un espace de trop