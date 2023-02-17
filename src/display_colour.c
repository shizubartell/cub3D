/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:09:33 by abartell          #+#    #+#             */
/*   Updated: 2023/02/17 14:24:15 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//setting down pixel by pixel the previous colour
void    mlx_pixels(t_data *game, int x, int y, int colour)
{
    char    *dest;

    dest = game->addr + (y * game->line_length + x * (game->bits_pp / 8));
    *(unsigned int*)dest = colour;
}

//setting down pixel by pixel the colour according
//to the specific texture it goes through
int text_pixels(int x, int y, t_texdata *game)
{
	char	*source;
	int		colour;

	source = game->addr + (y * game->line_length + x * (game->bits_pp / 8));
	colour = *(unsigned int *)source;
	return (colour);
}

//calculates the start position and increment of the y-coordinate
// for rendering a wall texture on the screen
void texture_start(t_game *game, double *y_incrementer, double save_dist, int *y_text)
{
    int wheight;
    
    wheight = (int)(game->screen_h / 2 / save_dist);
    *y_incrementer = (wheight * 2.0) / 64.0;

    if (save_dist < 1)
    {
        int wall_height = (int)(game->screen_h / 2);
        *y_text = (wheight - game->screen_h / 2) / *y_incrementer;
        *y_incrementer = (wall_height * 2) / (64.0 - *y_text * 2);
    }
    else
    {
        *y_text = 0;
    }
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
void pixeldrawer(t_game *game, int x, int direction)
{
    double y;
    double y_incrementer;
    double d;
    int y_max;
    
    y = -1;
    y_incrementer = 0;
    y_max = game->screen_h;
    texture_start(game, &y_incrementer, game->save_dist, &game->txt_pos_y);
    while (++y < y_max / 2 - game->wall_h)
    {
        mlx_pixels(game, x, y, game->ceilling_rgb);
    }
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
    {
        mlx_pixels(game, x, y, game->floor_rgb);
    }
}

// void    pixeldrawer(t_game *game)
// {
//     int  y;
//     int     x;
    
//     y = 0;
//     while (y < game->screen_h)
//     {
//         x = -1;
//         while (++x < game->screen_w)
//         {
// 			if (y < game->screen_h / 2)
//             	mlx_pixels(game, x, y, game->ceilling_rgb);
// 			else
// 				mlx_pixels(game, x, y, game->floor_rgb);
//         }	
//         y++;
//     }   
//     mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);
// }
