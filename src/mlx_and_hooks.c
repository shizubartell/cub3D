/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_and_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:30:47 by abartell          #+#    #+#             */
/*   Updated: 2023/02/03 12:00:52 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//init mlx window, maye renaming into different
//struct in the future (using one small struct to
//call the different structs of the programm)
void    init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    game->window =mlx_new_window(game->mlx, 1440, 990, "Otter 3D");
}

//closing function for the window
//EXIT_SUCCESS should prevent leaks
//as it expands to a different size than 0
int ft_closing(t_game *game)
{
    mlx_destroy_image(game->mlx, game->window);
    printf("Exiting Otter 3D\n");
    exit(EXIT_SUCCESS);
    return (0);
}

//key setup for the used keys in our cub3D
//might be later moved on to its own .c file
int key_setup(int keys, t_game *window)
{
    if (keys == ESC)
        ft_closing(window);
    return (0);
}

int key_hooks(t_game *game)
{
    return (1);
}
