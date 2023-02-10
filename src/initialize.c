/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:37:01 by abartell          #+#    #+#             */
/*   Updated: 2023/02/10 10:34:53 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//init img and adding the data address to be able
//to properly display the colours and textures
void	ft_img_init(t_game *game)
{
	game->data.img = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_pp, \
		&game->data.line_length, &game->data.endian);
}

//init mlx window, maye renaming into different
//struct in the future (using one small struct to
//call the different structs of the programm)
void    init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, game->screen_w, game->screen_h, "Otter 3D");
}

t_data *data_init(void)
{
	t_data *pixel;

	pixel = malloc (sizeof(t_data));
	pixel->addr = 0;
	pixel->bits_pp = 0;
	pixel->endian = 0;
	pixel->img = 0;
	pixel->line_length = 0;
	return (pixel);
}

//game initialisation
t_game	*init_game(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->width = 0;
	game->height = 0;
	game->n_texture = 0;
	game->s_texture = 0;
	game->w_texture = 0;
	game->e_texture = 0;
	game->ceilling_colour = 0;
	game->floor_colour = 0;
	game->ceilling_rgb = 0;
	game->floor_rgb = 0;
	game->row_beggining_of_map = 0;
	game->screen_w = 1060.0;
	game->screen_h = 710.0;
	init_for_moves(game);
	return (game);
}

void init_for_moves(t_game *game)
{
	game->a = 0;
	game->d = 0;
	game->w = 0;
	game->s = 0;
	game->arrow_l = 0;
	game->arrow_r = 0;
	game->pl_x = 0.0;
	game->pl_y = 0.0;
	game->p_angle = 0.0;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
	game->fov = 60.0;
}