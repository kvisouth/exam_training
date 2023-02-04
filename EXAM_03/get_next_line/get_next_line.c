/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:26:38 by kvisouth          #+#    #+#             */
/*   Updated: 2023/01/19 00:28:15 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//A coder : cut_stash, check_for_nl, get_next_line.

// 1. Prend en paranetre le stash, et supprime tout ce qui est avant le \n.
//	Retournes le reste du stash.
static char	*cut_stash(char *str)
{
	int i = 0;
	int j = 0;
	while (str[i] != '\n')
		i++;
	char *cutted_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!cutted_str)
		return (NULL);
	i++;
	while (str[i])
		cutted_str[j++] = str[i++];
	cutted_str[j] = '\0';
	return free(str), cutted_str;
}

// 2. Prend en parametre le stash, retourne 1 si il y a un \n, 0 sinon.
static int	check_for_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;
	int			readed;

	// Partie 1 : Verif parametres
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return NULL;
	if ((readed = read(fd, buff, BUFFER_SIZE)) <= 0 && !stash)
		return free(buff), NULL;
	buff[readed] = '\0';
	stash = stash ? ft_strjoin(stash, buff) : ft_substr(buff, 0, ft_strlen(buff));
	free(buff);
	if (stash[0] == '\0')
		return free(stash), stash = NULL, NULL;

	// Partie 2 : Le while
	while (stash)
	{
		// Partie 2.1 : On lis a nouveau dans le fichier
		if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || (readed = read(fd, buff, BUFFER_SIZE)) == -1)
			return free(buff), NULL;
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
		free(buff);

		// Partie 2.2 : Cas "derniere ligne"
		if (readed < BUFFER_SIZE && check_for_nl(stash) == 0)
		{
			line = ft_strdup(stash);
			free(stash);
			stash = NULL;
			return (line);
		}

		// Paertie 2.3 : Cas "pas derniere ligne"
		else if (check_for_nl(stash) == 1)
		{
			line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
			stash = cut_stash(stash);
			return (line);
		}
	}
	return (NULL);
}

// int main(int ac, char **av)
// {
// 	char	*line;
// 	int i = 0;
// 	int fd = open("text", O_RDONLY);
// 	if (ac == 2)
// 	{
// 		while (i < atoi(av[1]))
// 		{
// 			line = get_next_line(fd);
// 			printf("Ligne %d : %s\n", i + 1, line);
// 			free(line);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

// gcc -Wall -Wextra -Werror *.c