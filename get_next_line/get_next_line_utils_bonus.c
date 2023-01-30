/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:53:59 by abartell          #+#    #+#             */
/*   Updated: 2022/08/16 13:38:33 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//copying the string from the remaining input
//basically strcpy but with returning the length from
//strlen 

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
			i++;
	return (i);
}

//returns a portion of the string, starting at the
//specified index and extending for a given number
//of characters afterwards
//
char	*gnl_substr(char const *s, unsigned int beginn, size_t length)
{
	size_t	i;
	size_t	b;
	char	*str;

	str = malloc((sizeof(*s)) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	b = 0;
	while (s[i])
	{
		if (i >= beginn && b < length)
		{
			str[b] = s[i];
			b++;
		}
		i++;
	}
	str[b] = 0;
	return (str);
}

char	*gnl_strdup(void)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * 1);
	ptr[0] = '\0';
	return (ptr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*ptr;

	i = 0;
	b = 0;
	ptr = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
			ptr[i] = s1[i];
			i++;
	}
	while (s2[b] != '\0')
	{
			ptr[i + b] = s2[b];
			b++;
	}
	ptr[i + b] = '\0';
	return (ptr);
}

//returns a pointer to the first occurrence of the
//character c in the string s
//going through the loop as long as it doesnt hit the
//NULL Terminator
//if character c hits the NULL terminator 
char	*gnl_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
