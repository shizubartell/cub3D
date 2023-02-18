/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:59:32 by abartell          #+#    #+#             */
/*   Updated: 2023/02/18 15:12:15 by abartell         ###   ########.fr       */
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

# define WWIDTH 960
# define WHEIGHT 720
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

typedef struct  data
{
    void    *img;
    char    *addr;
    int     bits_pp;
    int     line_length;
    int     endian;
}   t_data;

typedef struct  texdata
{
    void    *img;
    char    *addr;
    int     bits_pp;
    int     line_length;
    int     endian;
    int     w;
    int     h;
}   t_texdata;

typedef struct game
{
	char **map;
    void    *mlx;
    void    *window;
    int width;
    int height;
    double screen_w;
    double  screen_h;
    double  save_dist;
    int     w;
    int     s;
    int     d;
    int     a;
    int     arrow_l;
    int     arrow_r;
    int     txt_pos_y;
    int     txt_pos_x;
    int     wall_h;
    // int     text_n;
    // int     text_e;
    // int     text_s;
    // int     text_w;
    char    *n_texture;
    char    *s_texture;
    char    *w_texture;
    char    *e_texture;
    char    *floor_colour;
    char    *ceilling_colour;
    int     floor_rgb;
    int     ceilling_rgb;
    int     row_beggining_of_map;
    double		pl_x;
	double		pl_y;
	double		pl_dx;
	double		pl_dy;
	double		p_angle;
	double		fov;
    int         prec_ray;
    double      incr_angle;
    struct data  data;
    struct texdata  texdata;
    t_texdata     *text_n;
    t_texdata     *text_e;
    t_texdata     *text_s;
    t_texdata	*text_w;
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

int ft_closing(int key, t_game *game);
int key_setup_push(int key, t_game *window);
int key_setup_nopush(int key, t_game *game);

//*********************************************************//
//**         DISPLAY_COLOUR.C                           **//

void    mlx_pixels(t_game *game, int x, int y, int colour);
int     text_pixels(int x, int y, t_texdata *game);
void	pixeldrawer(t_game *game, int x, int direction);

//*********************************************************//
//**         INITIALIZE.C                            **//

void	ft_img_init(t_game *game);
void    init_mlx(t_game *game);
t_game	*init_game(char *map);
void    init_for_moves(t_game *game);

//*********************************************************//
//**         MOVE.C                            **//

double	deg_to_rad(double deg);
void	rotation(t_game *game, double dir);
void	moving(t_game	*game, double move_x, double move_y);
int	    deal_key(t_game *game);

//*********************************************************//
//**         PLAYER_INIT.C                              **//

int	player_check(t_game *game);

//*********************************************************//
//**         RAYCASTING.C                               **//

double	calc_modulo(double a, double b);
void calculate_rays(t_game *game, double angle_ray, double rays[2], double *cosray, double *ray_sin);
void	raycaster(t_game *game);
void    init_text(t_game *game);
t_texdata  *xpm_to_text(t_game *game, char *texture);
int	deal_loop(t_game *game);
void	get_text_start(t_game *game, double *y_incrementer, double save_dist, int *y_text);

#endif