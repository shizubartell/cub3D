/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:11 by abartell          #+#    #+#             */
/*   Updated: 2023/02/03 11:38:04 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	errorhandler(int i)
{
	if (i == 1)
		ft_putstr_fd("Extension of map must be .cub \n", 2);
	else if (i == 2)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error filedescriptor\n", 2);
	else if (i == 4)
		ft_putstr_fd("No texture in map\n", 2);	
	else if (i == 5)
		ft_putstr_fd("Wrong letter in map\n", 2);
	else if (i == 6)
		ft_putstr_fd("Wrong border of the map\n", 2);
	else if (i == 7)
		ft_putstr_fd("Wrong colour\n", 2);
	else if (i == 8)
		ft_putstr_fd("Wrong character in colour\n", 2);		
	else if (i == 9)
		ft_putstr_fd("ERROR\n", 2);		
	return (1);
}

