/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:34:46 by iczarnie          #+#    #+#             */
/*   Updated: 2023/02/20 17:21:01 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/cub3D.h"

//fills rows in map
char	*fill_map(char *map, char *row)
{
	int	x;

	x = 0;
	while (row[x] && row[x] != '\n')
	{
		map[x] = row[x];
		x++;
	}
	return (map);
}

//allocating memory space for the map according
//to its width and height with malloc
void	map_allocater(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc (sizeof(char *) * (game->height + 1));
	game->map[game->height] = 0;
	while (i < game->height)
	{
		game->map[i] = ft_calloc (sizeof(char) * (game->width + 1), 1);
		game->map[i][game->width] = '\0';
		i++;
	}
}

//storing the rows of the map and going through them via
//GNL and fd, saving them in the fd and the game struct
int	read_maprows(char *row, int fd, t_game *game)
{
	int	i;

	i = 0;
	row = get_next_line(fd);
	while (i++ < game->row_beggining_of_map)
	{
		free(row);
		row = get_next_line(fd);
	}
	i = 0;
	while (row != 0)
	{
		game->map[i] = fill_map(game->map[i], row);
		i++;
		free(row);
		row = get_next_line(fd);
	}
	return (i);
}

//filling the empty spaces on the map that arent 1 and 0 with 1 for the map
//to be readable
void	filling_space(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if (game->map[i][j] == ' ' || game->map[i][j] == 0)
			{
				game->map[i][j] = '1';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	mapreader(t_game *game, char *file)
{
	int		fd;
	char	*row;
	int		i;

	i = 0;
	row = 0;
	if (!game->height || !game->width)
		return (0);
	map_allocater(game);
	fd = open(file, O_RDONLY);
	i = read_maprows(row, fd, game);
	filling_space(game);
	free(row);
	close(fd);
	game->map[i] = NULL;
	return (1);
}
