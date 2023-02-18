/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:51:00 by abartell          #+#    #+#             */
/*   Updated: 2023/02/18 15:14:17 by abartell         ###   ########.fr       */
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
t_texdata  *xpm_to_text(t_game *game, char *texture)
{
    t_texdata *input;

    input = ft_calloc (sizeof(t_texdata), 1);
    printf("\nVALUES INTS: %d, %d, %d\n", input->bits_pp, input->line_length, input->endian);
    printf("Adress: %x\n", game->texdata.addr);
    input->img = mlx_xpm_file_to_image(game->mlx, texture , &input->w, &input->h);
    printf("Adress2: %x\n", game->texdata.addr);
        // input->addr = mlx_get_data_addr(input->img, &a, &b, &c);
    input->addr = mlx_get_data_addr(input->img, &input->bits_pp, &input->line_length, &input->endian);
    return (input);
}

int	deal_loop(t_game *game)
{
	deal_key(game);
	raycaster(game);
	return (0);
}
