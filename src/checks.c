/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:04:09 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/20 14:45:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/cub3D.h"

//checks if the extension is valid
int	valid_extension(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strnstr(path + length - 4, ".cub", 4) == 0)
	{
		return (errorhandler(1));
	}
	return (0);
}

//checks if the map begins in that row
int	is_beggining_of_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

//checks if the map is surrounded by 1
int	check_map_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			// free_map(game);
			dead_end("Wrong borders for the map!\n");
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			// free_map(game);
			dead_end("Wrong borders for the map!\n");
		}
		i++;
	}
	return (1);
}

//checks if map has only allowed leters
int	check_map_letters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if (!(game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E'
				|| game->map[i][j] == '0' || game->map[i][j] == '1'))
			{
				printf("Wrong character: %c \n", game->map[i][j]);
				errorhandler(5);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
