/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:36:08 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/20 13:01:40 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//convert degrees to radians to be used in math functions
double	deg_to_rad(double deg)
{
	return (deg * PI / 180);
}

//rotate the field of view after the arrow is pressed
void	rotation(t_game *game, double dir)
{
	game->p_angle += dir;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
}

//changes player coordinates after key is pressed
void	moving(t_game	*game, double move_x, double move_y)
{
	float	i;

	i = (game->pl_x + move_x);
	if (game->map[(int) game->pl_y][(int) i] != '1')
		game->pl_x += move_x;
	i = (game->pl_y + move_y);
	if (game->map[(int) i][(int) game->pl_x] != '1')
		game->pl_y += move_y;
}

//defines how to move the player depending on what key is pressed
int	deal_key(t_game *game)
{
	if (game->w == 1)
		moving(game, game->pl_dx * 0.05, game->pl_dy * 0.05);
	if (game->s == 1)
		moving(game, -(game->pl_dx * 0.05), -(game->pl_dy * 0.05));
	if (game->a == 1)
		moving(game, cos(deg_to_rad(game->p_angle - 90)) * 0.05,
			sin(deg_to_rad(game->p_angle - 90)) * 0.05);
	if (game->d == 1)
		moving(game, cos(deg_to_rad(game->p_angle + 90)) * 0.05,
			sin(deg_to_rad(game->p_angle + 90)) * 0.05);
	if (game->arrow_l == 1)
		rotation(game, -3);
	if (game->arrow_r == 1)
		rotation(game, 3);
	return (0);
}
