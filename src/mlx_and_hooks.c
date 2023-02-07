/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_and_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:30:47 by abartell          #+#    #+#             */
/*   Updated: 2023/02/07 17:51:41 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//closing function for the window
//EXIT_SUCCESS should prevent leaks
//as it expands to a different size than 0
int ft_closing(int key, t_game *game)
{
    printf("%d\n", key);
    if (key == 53)
    {
        mlx_destroy_window(game->mlx, game->window);
        printf("Exiting Otter 3D\n");
        exit(0);
    }
    return (0);
}

//key setup for the used keys in our cub3D
//might be later moved on to its own .c file
int key_setup(int key, t_game *game)
{
    if (key == 53)
    {
        mlx_destroy_window(game->mlx, game->window);
        printf("Exiting Otter 3D\n");
        exit(0);
    }
	// if (key == W)

	// if (key == S)

	// if (key == A)

	// if (key == D)

	// if (key == ARR_LEFT)

	// if (key == ARR_RIGHT)

    return (0);
}
