#include <unistd.h>

// Inter
// Programme qui prend 2 chaines e caracteres en parametres et qui affiche
// les caracteres qui apparaissent dans les deux chaines de caracteres, sans doublons.
// Exemple : ./inter "abc" "abc" affiche "abc"
// Exemple : ./inter "abc" "def" affiche "\n"
// Exemple : ./inter "abc" "abf" affiche "ab"
// Exemple : ./inter "POP" "BOB" affiche "O"
// Affiche un seul \n quoi qu'il arrive.

// Fonction qui retourne 1 si :
// - c est present dans str jusqu'a l'index x
int	iter(char c, char *str, int x)
{
	int	i = 0;

	while (str[i] && (i < x || x == -1))
		if (str[i++] == c)
			return (1);
	return (0);
}

// En gros ce programme fait :
// Verifie si la lettre s1[i] n'est PAS presente dans s1 jusqu'a i
// ET que  si la lettre s1[i] EST presente dans s2
// Alors on affiche la lettre s1[i].
// On repete ce if jusqu'a la fin de s1.
int	main(int ac, char **av)
{
	int	i = 0;
    char *s1 = av[1];
    char *s2 = av[2];

	if (ac == 3)
	{
		while (s1[i])
		{
			if (!iter(s1[i], s1, i) && iter(s1[i], s2, -1))
				write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}