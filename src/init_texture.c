/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:51:00 by abartell          #+#    #+#             */
/*   Updated: 2023/02/22 15:39:59 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//initializing the different textures of the map
//for the game file
void	init_text(t_game *game)
{
	game->text_n = xpm_to_text(game, game->n_texture);
	game->text_s = xpm_to_text(game, game->s_texture);
	game->text_w = xpm_to_text(game, game->w_texture);
	game->text_e = xpm_to_text(game, game->e_texture);
}

//mlx functions to actually display the xpm image
//and get the address
t_texdata	*xpm_to_text(t_game *game, char *texture)
{
	t_texdata	*input;

	if (open(texture, O_RDONLY) == -1)
		dead_end("Error, wrong texture path!\n");
	input = ft_calloc (sizeof(t_texdata), 1);
	input->img = mlx_xpm_file_to_image(game->mlx, texture, \
		&input->w, &input->h);
	input->addr = mlx_get_data_addr(input->img, &input->bits_pp, \
		&input->line_length, &input->endian);
	return (input);
}

int	deal_loop(t_game *game)
{
	deal_key(game);
	raycaster(game);
	return (0);
}

//setting down pixel by pixel the previous colour
void	mlx_pixels(t_game *game, int x, int y, int colour)
{
	char	*dest;

	dest = game->data.addr + (y * game->data.line_length \
		+ x * (game->data.bits_pp / 8));
	*(unsigned int *)dest = colour;
}

//setting down pixel by pixel the colour according
//to the specific texture it goes through
int	text_pixels(int x, int y, t_texdata *game)
{
	char	*source;
	int		colour;

	source = game->addr + (y * game->line_length + (x * (game->bits_pp / 8)));
	colour = *((unsigned int *)source);
	return (colour);
}
