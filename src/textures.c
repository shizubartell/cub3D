/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:04:30 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/22 15:39:18 by abartell         ###   ########.fr       */
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
char	*texture_from_dot(char *line)
{
	int		i;
	char	*texture;

	i = 0;
	while (line[i] != '.')
		i++;
	texture = ft_strtrim(&line[i], "\n");
	return (texture);
}

//strips rgb for floor and ceilling from unnecessary characters
//and spaces
char	*rgb_skip_spaces(char *line)
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
	int	i;

	i = 0;
	i += fill_a(game, line);
	i += fill_b(game, line);
	i += fill_c(game, line);
	if (i != 0)
		return (1);
	else
	{
		check_for_flag(game, line);
		return (0);
	}
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
		game->key_count += fill_texture(game, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (game->key_count > 6)
		dead_end("Duplicate texture/colour in map!\n");
	if (!check_textures(game))
		dead_end("Lacking texture/colour in map!\n");
	if (game->map_flag == 1)
		dead_end("Wrong input in the map file!\n");
	return (1);
}
