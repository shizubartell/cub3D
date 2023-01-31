/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:11:24 by abartell          #+#    #+#             */
/*   Updated: 2023/01/31 15:07:33 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/cub3D.h"

//calculates the width and the height of the map and 
//puts them in the game structure
void	get_width_height(t_game *game, char *map)
{
	int		fd;
	char	*line;
	char	*trimmed_line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (i++ < 10)
		line = get_next_line(fd);
	trimmed_line = ft_strtrim(line, "\n");
	game->width = (int)ft_strlen(trimmed_line);
	printf("game height %d\n", game->height);
	while (line != 0)
	{
		if (game->width < (int)ft_strlen(trimmed_line))
			game->width = (int)ft_strlen(trimmed_line);
		game->height++;
		line = get_next_line(fd);
		trimmed_line = ft_strtrim(line, "\n");
		printf("Line :%s\n", trimmed_line);
	}
	free(trimmed_line);
	free(line);
	close(fd);
}

//checks if the extension is valid
int	valid_extension(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strnstr(path + length - 4, ".cub", 4) == 0)
	{
		return (errorhandler(1));
	}
	return (0);
}

//game initialisation
t_game	*init_game(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->width = 0;
	game->height = -1;
	game->n_texture = 0;
	game->s_texture = 0;
	game->w_texture = 0;
	game->e_texture = 0;
	game->ceiling_rgb = 0;
	game->floor_rgb = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	t_game 	*game;
	int		i = 0;

	if (argc != 2)
		return (errorhandler(2));
	valid_extension(argv[1]);
	game = init_game(argv[1]);
	read_textures(game, argv[1]);
	if (check_textures(game) == 0)
		printf("sad\n");
	else
		printf("textures exist\n");
	get_width_height(game, argv[1]);
	printf("%d\n", game->width);
	printf("%d\n", game->height);
}
