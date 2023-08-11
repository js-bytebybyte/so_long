/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/11 14:58:28 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_game_images(t_map *game)
{
	int 		x;
	int			y;

	// initialize the image -- return void pointer as the image initializer
	// Creates one that contains the .xpm image found in relative_path
	// and saves its width and height in pixels to the given pointers.
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "images/wall.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "images/floor.xpm", &x, &y);
}

void	adding_in_graphics(t_map *game)
{
	int height;
	int width;

	height = 0;
	while (height < game->rows)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor, width * 40, height * 40);
			// if (game->map[height][width] == 'C')
			// 	place_collectable(game, height, width);
			// if (game->map[height][width] == 'P')
			// 	place_player(game, height, width);
			// if (game->map[height][width] == 'E')
			// 	mlx_put_image_to_window(game->mlxpointer,
			// 							game->winpointer, game->exit, width * 40, height * 40);
			width++;
		}
		height++;
	}
}