/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/28 17:28:11 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// initialize the images - returns void pointer as the image initializer

void	init_game_images(t_map *game)
{
	int		x;
	int		y;

	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/cactus.xpm", &x, &y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/castle_32px.xpm", &x, &y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/mushroom.xpm", &x, &y);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/tile000.xpm", &x, &y);
}

void	init_background(t_map *game)
{
	t_img	bg_image;
	int     y;
    int     x;

	bg_image.img_ptr = mlx_new_image(game->mlx_ptr, game->columns * IMG_SIZE, game->rows * IMG_SIZE);
    bg_image.address = mlx_get_data_addr(bg_image.img_ptr, &bg_image.bpp, &bg_image.line_len, &bg_image.endian);

    bg_image.color = 0x347434;
	if (bg_image.bpp != 32)
        bg_image.color = mlx_get_color_value(game->mlx_ptr, bg_image.color);
    y = 0;
    while (y < game->rows * IMG_SIZE)
    {   
        x = 0;    
        while (x < game->columns * IMG_SIZE)
        {
            int pixel = (y * bg_image.line_len) + (x * 4);
            if (bg_image.endian == 1)        // Most significant (Alpha) byte first
            {
                bg_image.address[pixel + 0] = (bg_image.color >> 24);
                bg_image.address[pixel + 1] = (bg_image.color >> 16) & 0xFF;
                bg_image.address[pixel + 2] = (bg_image.color >> 8) & 0xFF;
                bg_image.address[pixel + 3] = (bg_image.color) & 0xFF;
            }
            else if (bg_image.endian == 0)   // Least significant (Blue) byte first
            {
                bg_image.address[pixel + 0] = (bg_image.color) & 0xFF;
                bg_image.address[pixel + 1] = (bg_image.color >> 8) & 0xFF;
                bg_image.address[pixel + 2] = (bg_image.color >> 16) & 0xFF;
                bg_image.address[pixel + 3] = (bg_image.color >> 24);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, bg_image.img_ptr, 0, 0);
}

// displays the images on the opened window in the correct position according to 2D map array
void	adding_in_graphics(t_map *game)
{
	int 	height;
	int 	width;

	height = 0;
	while (height < game->rows)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1') // wall
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width * IMG_SIZE, height * IMG_SIZE);
			if (game->map[height][width] == 'C') // collectible
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible_img, width * IMG_SIZE, height * IMG_SIZE);
			if (game->map[height][width] == 'P') // player
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, width * IMG_SIZE, height * IMG_SIZE);
			if (game->map[height][width] == 'E') // exit
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img, width * IMG_SIZE, height * IMG_SIZE);
			width++;
		}
		height++;
	}
}

int	init_graphics(t_map *game)
{
	init_background(game);
	init_game_images(game);
	adding_in_graphics(game);
	return (0);
}