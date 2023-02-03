/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:59:32 by abartell          #+#    #+#             */
/*   Updated: 2023/02/03 12:37:47 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*********************************************************//
//**                INCLUDES                            **//

# include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>


//*********************************************************//
//**                DEFINES                             **//

# define W 13
# define A 0
# define S 1
# define D 2
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define ESC 53
# define PI 3.141592653589793238

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct game
{
	char **map;
    void    *mlx;
    void    *window;
    int width;
    int height;
    char    *n_texture;
    char    *s_texture;
    char    *w_texture;
    char    *e_texture;
    char    *floor_colour;
    char    *ceilling_colour;
    int     floor_rgb;
    int     ceilling_rgb;
    int     row_beggining_of_map;
}	t_game;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//*********************************************************//
//**                ERRORS.C                            **//

int				errorhandler(int i);

//*********************************************************//
//**                MAIN.C                              **//

//*********************************************************//
//**                TEXTURES.C                           **//
int	check_textures(t_game *game);
int	fill_texture(t_game *game, char *line);
int	read_textures(t_game *game, char *map_file);

//*********************************************************//
//**                READ_MAP.C                          **//
char	*fill_map(char *map, char *row);
void	map_allocater(t_game *game);
int	    read_maprows(char *row, int fd, t_game *game);
void	filling_space(t_game *game);
int	    mapreader(t_game *game, char *file);

//*********************************************************//
//**                CHECKS.C                          **//
int	is_beggining_of_map(char *line);
int	valid_extension(char *path);
int check_map_letters(t_game *game);
int check_map_borders(t_game *game);

//*********************************************************//
//**         FLOOR_CEILLING_COLOURS.C                   **//
int check_colours(t_game *game);

//*********************************************************//
//**         MLX_AND_HOOKS.C                            **//

void    init_mlx(t_game *game);
int ft_closing(t_game *game);
int key_setup(int keys, t_game *window);
#endif