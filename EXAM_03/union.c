#include <unistd.h>

// Union
// Programme qui prend 2 chaines de caracteres en parametres et qui affiche
// la chaine de caracteres obtenue en enlevant les caracteres en double
// dans la premiere chaine de caracteres.
// Exemple : ./union "abc" "abc" affiche "abc"
// Exemple : ./union "abc" "def" affiche "abcdef"
// Exemple : ./union "abc" "abf" affiche "abcf"
// Exemple : ./union "POP" "BOB" affiche "POB"
// Si il n'y a pas exactement 2 arguments, le programme affiche "\n"
// Affiche aussi "\n" si le programme est correctement execute.

// Fonction qui verifie si :
// - le caractere c est present dans la chaine str jusqu'a l'index x
int check (char c, char *str, int x)
{
	int i = 0;

	while (i < x)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

// En gros ce programme fait :
// concatene s1 et s2 dans s1
// i recule de 1 pour partir du \0
// puis on affiche s1 sans les doublons avec k
int main (int ac, char **av)
{
	int i = 0; // index qui se placera sur la derniere lettre de s1
	int j = 0; // index de s2 qui permettra de copier s2 dans s1
	int k = 0; // index de s1 qui permettra d'ecrire s1 jusqu'a i sans les doublons
	char *s1 = av[1]; // copie des arguments pour + de lisibilite
	char *s2 = av[2]; // copie des arguments pour + de lisibilite

	if (ac == 3)
	{
		// on met i a la fin de s1
		while (s1[i])
			i++;

		// on copie s2 dans s1
		while (s2[j])
		{
			s1[i] = s2[j];
			i++;
			j++;
		}

		// on recule i de 1 pour partir du \0
		i--;

		// on affiche s1 sans les doublons
		while (k <= i)
		{
			if (check(s1[k], s1, k) == 1)
				write(1, &s1[k], 1);
			k++;
		}
	}
	write (1, "\n", 1);
}