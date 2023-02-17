/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:51:00 by abartell          #+#    #+#             */
/*   Updated: 2023/02/17 14:32:43 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//initializing the different textures of the map
//for the game file
void    init_text(t_game *game)
{
    game->text_n = new_text(game, game->n_texture);
    game->text_s = new_text(game, game->s_texture);
    game->text_w = new_text(game, game->w_texture);
    game->text_e = new_text(game, game->e_texture);
}

//mlx functions to actually display the xpm image
//and get the address
t_texdata  *new_text(t_game *game, char *texture)
{
    t_texdata *input;
// "./textures/otterN.xpm"
	if (open(texture, O_RDONLY) == -1)
		exit(0);
    input = malloc (sizeof(t_texdata));
    input->img = mlx_xpm_file_to_image(game->mlx, texture , &input->w, &input->h);
    input->addr = mlx_get_data_addr(input->img, &input->bits_pp, &input->line_length, &input->endian);
    return (input);
}

int key_ray_loop(t_game *game)
{
    deal_key(game);
    raycaster(game);
    return (0);
}
