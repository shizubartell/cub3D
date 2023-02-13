/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:51:00 by abartell          #+#    #+#             */
/*   Updated: 2023/02/13 15:32:43 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//initializing the different textures of the map
//for the game file
void    init_text(t_game *game)
{
    game->text_n = xpm_to_text(game, game->n_texture);
    game->text_s = xpm_to_text(game, game->s_texture);
    game->text_w = xpm_to_text(game, game->w_texture);
    game->text_e = xpm_to_text(game, game->e_texture);
}

//mlx functions to actually display the xpm image
//and get the address
t_data  *xpm_to_text(t_game *game, char *texture)
{
    t_texdata *input;

    input = malloc (sizeof(t_data));
    input->img = mlx_xpm_to_image(game->mlx, texture, &input->w, &input->h);
    input->addr = mlx_get_data_addr(input->img, &input->addr, &input->line_length, &input->endian);
    return (input);
}
