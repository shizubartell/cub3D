/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:11 by abartell          #+#    #+#             */
/*   Updated: 2023/02/20 15:42:00 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	errorhandler(int i)
{
	if (i == 1)
		ft_putstr_fd("Extension of map must be .cub \n", 2);
	else if (i == 2)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error filedescriptor\n", 2);
	else if (i == 4)
		ft_putstr_fd("No texture in map\n", 2);
	else if (i == 5)
		ft_putstr_fd("Wrong letter in map\n", 2);
	else if (i == 6)
		ft_putstr_fd("Wrong border of the map\n", 2);
	else if (i == 7)
		ft_putstr_fd("Wrong colour\n", 2);
	else if (i == 8)
		ft_putstr_fd("Wrong character in colour\n", 2);
	else if (i == 9)
		ft_putstr_fd("ERROR\n", 2);
	return (1);
}

int	dead_end(char *str)
{
	ft_putstr_fd(str, 0);
	exit(0);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (game->text_n)
		mlx_destroy_image(game->mlx, game->text_n);
	if (game->text_e)
		mlx_destroy_image(game->mlx, game->text_e);
	if (game->text_w)
		mlx_destroy_image(game->mlx, game->text_w);
	if (game->text_s)
		mlx_destroy_image(game->mlx, game->text_s);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}
