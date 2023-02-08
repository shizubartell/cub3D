/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:37:01 by abartell          #+#    #+#             */
/*   Updated: 2023/02/08 12:25:45 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//init img and adding the data address to be able
//to properly display the colours and textures
void	ft_img_init(t_game *game)
{
	game->data.img = mlx_new_image(game->mlx, WWIDTH, WHEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_pp, \
		&game->data.line_length, &game->data.endian);
}

//init mlx window, maye renaming into different
//struct in the future (using one small struct to
//call the different structs of the programm)
void    init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, WWIDTH, WHEIGHT, "Otter 3D");
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
