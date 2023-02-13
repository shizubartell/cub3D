/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:09:33 by abartell          #+#    #+#             */
/*   Updated: 2023/02/13 13:18:27 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//setting down pixel by pixel the previous colour
void    mlx_pixels(t_game *game, int x, int y, int colour)
{
    char    *dest;

    dest = game->data.addr + (y * game->data.line_length + x * (game->data.bits_pp / 8));
    *(unsigned int*)dest = colour;
}

//setting down pixel by pixel the colour according
//to the specific texture it goes through
int text_pixels(int x, int y, t_game *game)
{
	char	*source;
	int		colour;

	source = game->texdata.addr + (y * game->texdata.line_length + x * (game->texdata.bits_pp / 8));
	colour = *(unsigned int *)source;
	return (colour);
}

//direciton might be renamed, displaying the texture in terms of the 
//direction of where the texture is supposed to be displayed
void    display_texture(int direction, t_game *game, int x, int y)
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
//in the future?
void    pixeldrawer(t_game *game)
{
    int  y;
    int     x;
    
    y = 0;
    while (y < game->screen_h)
    {
        x = -1;
        while (++x < game->screen_w)
        {
			if (y < game->screen_h / 2)
            	mlx_pixels(game, x, y, game->ceilling_rgb);
			else
				mlx_pixels(game, x, y, game->floor_rgb);
        }	
        y++;
    }   
    mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);
}
