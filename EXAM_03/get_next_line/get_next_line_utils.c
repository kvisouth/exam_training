/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:05:52 by kvisouth          #+#    #+#             */
/*   Updated: 2023/01/19 00:12:11 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//A coder : ft_strlen, ft_strjoin, ft_strchr, ft_substr, ft_strdup
//Seul ft_strjoin est different de la version classique

// ft_strlen classique
size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	while (str[i])
		i++;
	return i;
}

// ft_strjoin classique MAIS avec un free de s1 a la fin en plus
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i = 0;
	int		j = 0;
	size_t size = ft_strlen(s1) + ft_strlen(s2);
	char *str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free((char *)s1);
	return (str);
}

// ft_strchr classique
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

// ft_substr classique
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i = 0;
	int		y = 0;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (start + y < start + len && s[start + y] != '\0')
		y++;
	str = malloc((y) + 1);
	if (!str || start > ft_strlen(s))
		return (NULL);
	while (i < y)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

// ft_strdup classique
char	*ft_strdup(const char *s1)
{
	int i = 0;
	char *str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}