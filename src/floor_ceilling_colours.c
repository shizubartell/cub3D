/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling_colours.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:09:07 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/18 18:09:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/cub3D.h"

//frees **rgb
static void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

//converts the ceilling colour for used by mlx
static void	ceilling_colour(t_game *game)
{
	int		colour;
	char	**rgb;
	int		i;

	i = 0;
	colour = 0;
	rgb = ft_split(game->ceilling_colour, ',');
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			dead_end("Wrong colour!\n");
		i++;
	}
	colour += ft_atoi(rgb[0]) * 256 * 256;
	colour += ft_atoi(rgb[1]) * 256;
	colour += ft_atoi(rgb[2]);
	free_rgb(rgb);
	game->ceilling_rgb = colour;
}

//converts the floor colour for used by mlx
static void	floor_colour(t_game *game)
{
	int		colour;
	char	**rgb;
	int		i;

	i = 0;
	colour = 0;
	rgb = ft_split(game->floor_colour, ',');
	while (rgb[i] != NULL)
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			dead_end("Wrong colour!\n");
		i++;
	}
	colour += ft_atoi(rgb[0]) * 256 * 256;
	colour += ft_atoi(rgb[1]) * 256;
	colour += ft_atoi(rgb[2]);
	free_rgb(rgb);
	game->floor_rgb = colour;
}

//checks for forbidden characters in colour
static int	check_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == ',')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//checks if colours are fine and calls 
//functions for parsing them
int	check_colours(t_game *game)
{
	if (!check_characters(game->ceilling_colour))
		errorhandler(8);
	if (!check_characters(game->floor_colour))
		errorhandler(8);
	ceilling_colour(game);
	floor_colour(game);
	return (0);
}
