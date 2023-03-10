/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:28:27 by abartell          #+#    #+#             */
/*   Updated: 2023/02/22 10:38:30 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//calculates the mathematical modulo between two
//numbers a and b, the function returns the result of the
//modul operation.
//if a is neg its stored in mod, if b is neg it is set to its
//absolute value, it then repeatedlz substracts b from mod
//until mod is less than b
double	calc_modulo(double a, double b)
{
	double	mod;

	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;
	while (mod >= b)
		mod = mod - b;
	if (a < 0)
		return (-mod);
	return (mod);
}

void	get_distance(t_game *game, double *rays, double ray_angle)
{
	double	distance;

	distance = sqrt(pow(game->pl_x - rays[0], 2)
			+ pow(game->pl_y - rays[1], 2));
	distance = distance * cos(deg_to_rad(ray_angle - game->p_angle));
	game->save_dist = distance;
	if (distance < 1)
		distance = 1;
	game->wall_h = (int)(game->screen_h / 2 / distance);
}

int	orientation(t_game *game, double angle_ray, double *rays)
{
	int	dx;
	int	dy;

	dx = rays[0] - cos(deg_to_rad(angle_ray)) / game->prec_ray;
	dy = rays[1] - sin(deg_to_rad(angle_ray)) / game->prec_ray;
	if (dy == (int)rays[1] && dx < (int)rays[0])
		return (1);
	else if (dy == (int)rays[1] && dx > (int)rays[0])
		return (2);
	else if (dx == (int)rays[0] && dy < (int)rays[1])
		return (3);
	else if (dx == (int)rays[0] && dy > (int)rays[1])
		return (4);
	return (5);
}

//main for raycasting in our game
//we initialize a rays array to store the x and y position
//of the player, cosray and sinray store the proper cosine and sine
//from the angle_ray converted to radians
//our while loop goes through each ray and for each loop the ray array is
//reset to the current player x and y position;
//the other while loop casts the ray and checks if it hits an object (texture)
//on the game map and goes on as long as it doesnt hit an object, updating the
//ray position and adding cosray and sinray to x and y of the rays array.
//this function is too long and will be split into 2 functions
void	calculate_rays(t_game *game, double angle_ray, \
		double rays[2], double cossinray[2])
{
	rays[0] = game->pl_x;
	rays[1] = game->pl_y;
	cossinray[0] = cos(deg_to_rad(angle_ray)) / game->prec_ray;
	cossinray[1] = sin(deg_to_rad(angle_ray)) / game->prec_ray;
	while (game->map[(int)rays[1]][(int)rays[0]] != '1')
	{
		rays[0] = rays[0] + cossinray[0];
		rays[1] = rays[1] + cossinray[1];
	}
	get_distance(game, rays, angle_ray);
	game->txt_pos_x = calc_modulo((64.0 * (rays[0] + rays[1])), 64.0);
}

void	raycaster(t_game *game)
{
	double	angle_ray;
	double	rays[2];
	double	cossinray[2];
	int		raycounter;

	raycounter = 0;
	angle_ray = game->p_angle - game->fov / 2;
	while (raycounter < game->screen_w)
	{
		calculate_rays(game, angle_ray, rays, cossinray);
		pixeldrawer(game, raycounter, orientation(game, angle_ray, rays));
		angle_ray = angle_ray + game->incr_angle;
		raycounter++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);
}
