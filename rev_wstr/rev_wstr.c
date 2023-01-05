#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0') //on cale i a la fin de la string
			i++;
		while(i >= 0) //tant que i n'est pas au debut de la string
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--; //i decremente tant qu'on est sur un \0 OU un separateur
			end = i; //end est a la fin du mot qu'on va ecrire
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--; //tant qu'on est sur une lettre, i decremente
			start = i + 1; //start est a la premiere lettre du mot qu'on va ecrire
			int flag = start; //flag prend la valeur de start pr y revenir apres avoir ecrit le mot

            //on ecrit le mot, de start a end.
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}

            //si on est pas sur le premier mot de la str, met un espace pour espacer les mots.
			if (flag != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}