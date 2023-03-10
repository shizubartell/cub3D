/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_and_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:30:47 by abartell          #+#    #+#             */
/*   Updated: 2023/02/22 13:45:30 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//key setup for the used keys in our cub3D
//might be later moved on to its own .c file
int	key_setup_push(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		printf("Exiting Otter 3D\n");
		exit(0);
	}
	if (key == W)
		game->w = 1;
	if (key == S)
		game->s = 1;
	if (key == A)
		game->a = 1;
	if (key == D)
		game->d = 1;
	if (key == ARR_LEFT)
		game->arrow_l = 1;
	if (key == ARR_RIGHT)
		game->arrow_r = 1;
	return (0);
}

int	key_setup_nopush(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		printf("Exiting Otter 3D\n");
		exit(0);
	}
	if (key == W)
		game->w = 0;
	if (key == S)
		game->s = 0;
	if (key == A)
		game->a = 0;
	if (key == D)
		game->d = 0;
	if (key == ARR_LEFT)
		game->arrow_l = 0;
	if (key == ARR_RIGHT)
		game->arrow_r = 0;
	return (0);
}
