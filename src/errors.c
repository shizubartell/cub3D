/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:11 by abartell          #+#    #+#             */
/*   Updated: 2023/01/30 12:46:50 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	errorhandler(int i)
{
	if (i == 1)
		ft_putstr_fd("ERROR\nExtension of map must be .cub", 2);
	else if (i == 2)
		ft_putstr_fd("ERROR\n", 2);
	return (1);
}

int	mapending(const char *map)
{
	char	*tmp;

	tmp = ft_strchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
	return (errorhandler(1));
}
