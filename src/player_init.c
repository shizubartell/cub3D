/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:38:11 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/22 15:22:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//initialises starting angle depending on character in the map
void static	player_starting_angle(char c, t_game *game)
{
	if (c == 'N')
		game->p_angle = 270.0;
	else if (c == 'S')
		game->p_angle = 90.0;
	else if (c == 'W')
		game->p_angle = 180.0;
	else if (c == 'E')
		game->p_angle = 0.0;
}

//sets starting postion of the player
void static	player_set(t_game *game, int i, int j)
{
	player_starting_angle(game->map[i][j], game);
	game->map[i][j] = '0';
	game->pl_x = j + 0.5;
	game->pl_y = i + 0.5;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
}

//checks if there is only one player + calls to set its starting postition
int	player_check(t_game *game)
{
	int	num_player;
	int	i;
	int	j;

	i = 0;
	j = 0;
	num_player = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				player_set(game, i, j);
				num_player++;
			}
			j++;
		}
		i++;
	}
	if (num_player != 1)
		return (0);
	return (1);
}
