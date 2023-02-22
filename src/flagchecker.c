/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:54 by abartell          #+#    #+#             */
/*   Updated: 2023/02/22 13:40:28 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_for_flag(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == ' '
			|| line[i] == 'W' || line[i] == 'E' || line[i] == '\n'
			|| line[i] == '0' || line[i] == '1')
		{
			i++;
		}
		else
		{
			game->map_flag = 1;
			break ;
		}
	}
}

int	fill_a(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (game->n_flag == 0)
		{
			game->n_texture = texture_from_dot(line);
			game->n_flag = 1;
		}
		return (1);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (game->s_flag == 0)
		{
			game->s_texture = texture_from_dot(line);
			game->s_flag = 1;
		}
		return (1);
	}
	else
		return (0);
}

int	fill_b(t_game *game, char *line)
{
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (game->w_flag == 0)
		{
			game->w_texture = texture_from_dot(line);
			game->w_flag = 1;
		}
		return (1);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (game->e_flag == 0)
		{
			game->e_texture = texture_from_dot(line);
			game->e_flag = 1;
		}
		return (1);
	}
	else
		return (0);
}

int	fill_c(t_game *game, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		if (game->f_flag == 0)
		{
			game->floor_colour = rgb_skip_spaces(line);
			game->f_flag = 1;
		}
		return (1);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		if (game->c_flag == 0)
		{
			game->ceilling_colour = rgb_skip_spaces(line);
			game->c_flag = 1;
		}
		return (1);
	}
	else
		return (0);
}
