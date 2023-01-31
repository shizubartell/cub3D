/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:38:13 by abartell          #+#    #+#             */
/*   Updated: 2023/01/31 15:09:52 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* strtrim removes all whitespace char from beginning
* and end of a str
*/

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	front;
// 	size_t	back;
// 	char	*dest;

// 	if (!(s1 && set))
// 		return (NULL);
// 	front = 0;
// 	back = ft_strlen(s1);
// 	while (s1[front] && ft_strchr(set, s1[front]))
// 		front++;
// 	while (s1[back - 1] && ft_strchr(set, s1[back - 1]) && back > front)
// 		back--;
// 	dest = malloc(sizeof(char) * (back - front + 1));
// 	if (!dest)
// 		return (NULL);
// 	ft_strlcpy(dest, &s1[front], back - front + 1);
// 	return (dest);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;

	index = 0;
	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	index = ft_strlen(s1);
	while (index && ft_strchr(set, s1[index]))
		index--;
	return (ft_substr(s1, 0, index + 1));
}
