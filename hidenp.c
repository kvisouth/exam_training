#include <unistd.h>
//Programme qui prend en parametre 2 strings.
//Write 1 si il trouve les caracteres de s1 dans l'ordre dans s2.
//Write 0 si il ne les trouves pas ou ne sont pas dans l'ordre.
//Exemple : ./hidenp "abc" "a...b..c" | $> 1$
//Exemple : ./hidenp "abc" "a...c..b" | $> 0$

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	char *s1 = av[1];
    char *s2 = av[2];
    
	if (ac == 3)
	{
		while (s2[j] && s1[i])
		{
			if (s2[j] == s1[i])
				i++;
			j++;
		}
		if (s1[i] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}