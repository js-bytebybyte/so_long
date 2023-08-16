/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/16 09:44:52 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	set_player_map(t_map *game)
{
	int	x;
	int	y;
	
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "images/player_cat.xpm", &x, &y);
	game->player_img->width = x;
	//printf("the player image width: %d\n", game->player_img->width);
	game->player_img->heigth = y;
	//printf("the player image width: %d\n", game->player_img->heigth);
}


void	init_game_images(t_map *game)
{
	int 		x;
	int			y;

	// initialize the image -- return void pointer as the image initializer
	// Creates one that contains the .xpm image found in relative_path
	// and saves its width and height in pixels to the given pointers.
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "images/wall_rock.xpm", &x, &y);
	printf("the wall image width: %d\n", x);
	printf("the wall image heigth: %d\n", y);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "images/floor.xpm", &x, &y);
	printf("the floor image width: %d\n", x);
	printf("the floor image heigth: %d\n", y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "images/exit_fence.xpm", &x, &y);
	printf("the exit image width: %d\n", x);
	printf("the exit image heigth: %d\n", y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr, "images/collectible_candy.xpm", &x, &y);
	printf("the collectibles image width: %d\n", x);
	printf("the collectibles imgage heigth: %d\n", y);
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
			if (game->map[height][width] == '1') // wall
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width * 40, height * 40);
			if (game->map[height][width] == '0') // floor
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor, width * 40, height * 40);
			if (game->map[height][width] == 'C') // collectible
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible_img, width * 40, height * 40);
			if (game->map[height][width] == 'P') // player
			{
				set_player_map(game);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, width * 40, height * 40);
			}
			if (game->map[height][width] == 'E') // exit
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img, width * 40, height * 40);
			width++;
		}
		height++;
	}
}