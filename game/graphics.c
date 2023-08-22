/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/22 21:46:20 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"


void	init_game_images(t_map *game)
{
	int		x;
	int		y;
	//t_img	bg_image;

	// initialize the image -- return void pointer as the image initializer
	// Creates one that contains the .xpm image found in relative_path
	// and saves its width and height in pixels to the given pointers.
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/simple_bush.xpm", &x, &y);
	printf("the wall image width: %d\n", x);
	printf("the wall image heigth: %d\n", y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/castle_32px.xpm", &x, &y);
	printf("the exit image width: %d\n", x);
	printf("the exit image heigth: %d\n", y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/mushroom.xpm", &x, &y);
	printf("the collectibles image width: %d\n", x);
	printf("the collectibles imgage heigth: %d\n", y);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "game_images/tile000.xpm", &x, &y);
	printf("the player image width: %d\n", x);
	printf("the player imgage heigth: %d\n", y);
}

void	init_background(t_map *game)
{
	t_img	bg_image;
	int     y; // heigth of the window
    int     x; // width of the window
	int 	color;

	bg_image.img_ptr = mlx_new_image(game->mlx_ptr, game->columns * IMG_SIZE, game->rows * IMG_SIZE);
    bg_image.addr = mlx_get_data_addr(bg_image.img_ptr, &bg_image.bpp, &bg_image.line_len, &bg_image.endian);
    printf("endian: %d\n", bg_image.endian);

    color = 0x347434;
    if (bg_image.bpp != 32)
        color = mlx_get_color_value(game->mlx_ptr, color);
    y = 0;
    while (y < game->rows * IMG_SIZE)
    {   
        x = 0;    
        while (x < game->columns * IMG_SIZE)
        {
            int pixel = (y * bg_image.line_len) + (x * 4);
            if (bg_image.endian == 1)        // Most significant (Alpha) byte first
            {
                bg_image.addr[pixel + 0] = (color >> 24);
                bg_image.addr[pixel + 1] = (color >> 16) & 0xFF;
                bg_image.addr[pixel + 2] = (color >> 8) & 0xFF;
                bg_image.addr[pixel + 3] = (color) & 0xFF;
            }
            else if (bg_image.endian == 0)   // Least significant (Blue) byte first
            {
                bg_image.addr[pixel + 0] = (color) & 0xFF;
                bg_image.addr[pixel + 1] = (color >> 8) & 0xFF;
                bg_image.addr[pixel + 2] = (color >> 16) & 0xFF;
                bg_image.addr[pixel + 3] = (color >> 24);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, bg_image.img_ptr, 0, 0);
}

void	adding_in_graphics(t_map *game)
{
	int 	height;
	int 	width;
	//t_img	bg_image;

	height = 0;
	while (height < game->rows)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1') // wall
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width * IMG_SIZE, height * IMG_SIZE);
			// if (game->map[height][width] == '0') // floor
			// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, bg_image.img_ptr, 0, 0);
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
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, bg_image.img_ptr, 0, 0);
}