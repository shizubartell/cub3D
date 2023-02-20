/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:04:30 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/20 18:40:12 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/cub3D.h"

//checks for textures being in the structure
int	check_textures(t_game *game)
{
	if (!game->n_texture)
		return (0);
	if (!game->s_texture)
		return (0);
	if (!game->w_texture)
		return (0);
	if (!game->e_texture)
		return (0);
	if (!game->floor_colour)
		return (0);
	if (!game->ceilling_colour)
		return (0);
	return (1);
}

//skips spaces and trims to return the right texture
static char	*texture_from_dot(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '.')
		i++;
	return (ft_strtrim(&line[i], "\n"));
}

//strips rgb for floor and ceilling from unnecessary characters
//and spaces
static char	*rgb_skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == 'F' || line[i] == 'C')
		i++;
	return (ft_strtrim(&line[i], "\n"));
}

//puts textuers in the game structure
int	fill_texture(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		game->n_texture = texture_from_dot(line);
	else if (line[0] == 'S' && line[1] == 'O')
		game->s_texture = texture_from_dot(line);
	else if (line[0] == 'W' && line[1] == 'E')
		game->w_texture = texture_from_dot(line);
	else if (line[0] == 'E' && line[1] == 'A')
		game->e_texture = texture_from_dot(line);
	else if (line[0] == 'F')
		game->floor_colour = rgb_skip_spaces(line);
	else if (line[0] == 'C')
		game->ceilling_colour = rgb_skip_spaces(line);
	else
		return (0);
	return (1);
}

//reads in the texture lines from map file by gnl
int	read_textures(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	int		row_index;

	row_index = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		dead_end("Error filedescriptor!\n");
	line = get_next_line(fd);
	while (line)
	{
		fill_texture(game, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!check_textures(game))
		dead_end("Wrong texture in map!\n");
	return (1);
}
