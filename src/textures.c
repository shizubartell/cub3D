/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:04:30 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/02 10:45:44 by iczarnie         ###   ########.fr       */
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
	if (!game->floor_rgb)
		return (0);
	if (!game->ceiling_rgb)
		return (0);
	return (1);
}

//skips spaces and trims to return the right texture
static char	*texture_from_dot(char *line)
{
	int	i;

	i = 0;
	while(line[i] != '.')
		i++;
	return(ft_strtrim(&line[i], "\n"));
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
		game->floor_rgb = ft_strtrim(&line[2], "\n");
	else if (line[0] == 'C')
		game->ceiling_rgb = ft_strtrim(&line[2], "\n");
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
		return (errorhandler(3));
	line = get_next_line(fd);
	while (line)
	{
		fill_texture(game, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!check_textures(game))
		errorhandler(4);
	return (1);
}