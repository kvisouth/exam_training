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
	int flag = 0;
		
	if(ac == 2)
	{   
		char *str = av[1];

		//On se cale sur la fin de la string.
		while(str[i] != '\0')
			i++;
		while(i >= 0)
		{
			//On recule i tant que str[i] n'est pas une lettre
			while( str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
				i--;

			//On sauvegarde la position de i car str[i] est forcement la derniere lettre d'un mot
			end = i;
			
			//On recule i tant que str[i] n'est pas un separateur (une lettre)
			while(str[i] && str[i] != ' ' && str[i] != '\t')
				i--;

			//i est sur le caractere avant la 1ere lettre d'un mot (le meme que end)
			//Donc on sauvegarde la position de cette lettre dans start (i + 1)
			start = i + 1;

			//On met flag a 1 pour write un espace apres avoir ecrit le mot
			flag = 1;

			//On write le mot de start a end.
			while(start <= end)
			{
				write (1, &str[start],1);
				start++;		
			}

			//On write un espace si flag est egal a 1
			if (flag != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}