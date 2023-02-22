/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:09:33 by abartell          #+#    #+#             */
/*   Updated: 2023/02/22 10:37:32 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_text_start(t_game *game, double *y_incrementer,
	double save_dist, int *y_text)
{
	int	wall_height;
	int	wheight;

	wheight = (int)(game->screen_h / 2 / save_dist);
	*y_incrementer = (wheight * 2.0) / 64.0;
	if (save_dist >= 1)
	{
		*y_text = 0;
		return ;
	}
	save_dist = 1;
	wall_height = (int)(game->screen_h / 2 / save_dist);
	*y_text = (wheight - game->screen_h / 2) / *y_incrementer;
	*y_incrementer = (wall_height * 2) / (64.0 - *y_text * 2);
}

//displaying the texture in terms of the 
//direction of where the texture is supposed to be displayed
void	display_texture(int direction, t_game *game, int x, int y)
{
	if (direction == 1)
		mlx_pixels(game, x, y, \
			text_pixels(game->txt_pos_x, game->txt_pos_y, game->text_n));
	else if (direction == 2)
		mlx_pixels(game, x, y, \
			text_pixels(game->txt_pos_x, game->txt_pos_y, game->text_s));
	else if (direction == 3)
		mlx_pixels(game, x, y, \
			text_pixels(game->txt_pos_x, game->txt_pos_y, game->text_w));
	else if (direction == 4)
		mlx_pixels(game, x, y, \
			text_pixels(game->txt_pos_x, game->txt_pos_y, game->text_e));
}

//drawing the pixels along the x and y coordinates
//from floor and ceiling rgb
//additionally adding setting the texture pixels
void	pixeldrawer(t_game *game, int x, int direction)
{
	double	y;
	double	y_incrementer;
	double	d;
	int		y_max;

	y = -1;
	y_incrementer = 0;
	y_max = game->screen_h;
	get_text_start(game, &y_incrementer, game->save_dist, &game->txt_pos_y);
	while (++y < y_max / 2 - game->wall_h)
		mlx_pixels(game, x, y, game->ceilling_rgb);
	d = y;
	while (y < y_max / 2 + game->wall_h)
	{
		d = d + y_incrementer;
		while (y < d && y < y_max)
		{
			display_texture(direction, game, x, y);
			y++;
		}
		game->txt_pos_y++;
	}
	while (++y < y_max)
		mlx_pixels(game, x, y, game->floor_rgb);
}
