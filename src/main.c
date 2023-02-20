/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:11:24 by abartell          #+#    #+#             */
/*   Updated: 2023/02/20 14:53:17 by abartell         ###   ########.fr       */
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
	while (!is_beggining_of_map(line))
	{
		free(line);
		line = get_next_line(fd);
		game->row_beggining_of_map++;
	}
	trimmed_line = ft_strtrim(line, "\n");
	game->width = (int)ft_strlen(trimmed_line);
	while (line != 0)
	{
		if (game->width < (int)ft_strlen(trimmed_line))
			game->width = (int)ft_strlen(trimmed_line);
		game->height++;
		free(line);
		free(trimmed_line);
		line = get_next_line(fd);
		trimmed_line = ft_strtrim(line, "\n");
	}
	free(trimmed_line);
	free(line);
	close(fd);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
}

void	printing_things(t_game *game)
{
	// int	i;
	// int	j;

	printf("N: %s\n", game->n_texture);
	printf("S: %s\n", game->s_texture);
	printf("W: %s\n", game->w_texture);
	printf("E: %s\n", game->e_texture);
	printf("floor: %s\n", game->floor_colour);
	printf("ceiling: %s\n", game->ceilling_colour);
	printf("floor parsed: %d\n", game->floor_rgb);
	printf("ceiling parsed: %d\n", game->ceilling_rgb);
	printf("widht: %d\n", game->width);
	printf("height: %d\n", game->height);
	printf("beginning of the map: %d\n", game->row_beggining_of_map);
	print_map(game);
	// i = 0;
	// j = 0;
	// while (i < game->height)
	// {
	// 	while (j < game->width)
	// 	{
	// 		printf("%c", game->map[i][j]);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// 	printf("\n");
	// }
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		dead_end("Wrong number of arguments!\n");
	valid_extension(argv[1]);
	game = init_game(argv[1]);
	// init_mlx(game);
	get_width_height(game, argv[1]);
	read_textures(game, argv[1]);
	mapreader(game, argv[1]);
	check_map_borders(game);
	check_map_letters(game);
	if (!player_check(game))
		dead_end("Wrong number of players!\n");
	// game = init_game(argv[1]);
	init_mlx(game);
	// if (player_check(game) == 0)
	// 	printf("Wrong number of players\n");
	ft_img_init(game);
	init_text(game);
	check_colours(game);
	printing_things(game);
	mlx_hook(game->window, 2, 0, key_setup_push, game);
	mlx_hook(game->window, 17, 0, ft_closing, 0);
	mlx_hook(game->window, 3, 0, key_setup_nopush, game);
	mlx_loop_hook(game->mlx, deal_loop, game);
	mlx_loop(game->mlx);
	free_game(game);
}
