/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:09:33 by abartell          #+#    #+#             */
/*   Updated: 2023/02/06 19:04:08 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    mlx_pixels(t_game *game, int x, int y, int colour)
{
    char    *dest;
    // data->addr = mlx_get_data_addr(data->img, &(data->bits_pp), &(data->line_length), &(data->endian));
    dest = game->data.addr + (y * game->data.line_length + x * (game->data.bits_pp / 8));
    *(unsigned int*)dest = colour;
}

void    pixeldrawer(t_game *game)
{
    int  y;
    int     x;
    
    y = 0;
    while (y < WHEIGHT)
    {
        x = 0;
        while (x++ < WWIDTH)
        {
			if (y < 720)
            	mlx_pixels(game, x, y, game->ceilling_rgb);
			else
				mlx_pixels(game, x, y, game->floor_colour);
        }	
        y++;
    }   
    mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);
}