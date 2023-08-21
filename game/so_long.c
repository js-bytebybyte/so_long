/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:41:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/21 22:50:17 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (len--)
	{
		*s = (unsigned char)c;
		s++;
	}
	return (b);
}

int	terminate_game(t_map *game)
{
	int		i;
	
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	i = 0;
	if (game->map[i])
	{
		while (i < game->rows)
		{	
			free(game->map[i]);
			i++;
		}
	}
	free(game->map);
	exit(0);
}
// t_img	new_file_img(char *path, t_map window) 
// {
// 	t_img	image;
// 	t_map	game;

// 	image.win = (t_img *)window;
// 	image.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, path, &image.w, &image.h);
// 	if (!image.img_ptr)
// 		write(2, "File could not be read\n", 23);
// 	else
// 		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
// 			&(image.line_len), &(image.endian));
// 	return (image);
// }

int main(int argc, char **argv)
{
	t_map	game;
	t_img	bg_image;
	int     y; // heigth of the window
    int     x; // width of the window
	int 	color;
	
	// initialize the variables of t_map game 
	ft_memset(&game, 0, sizeof(t_map));
	ft_memset(&bg_image, 0, sizeof(t_img));
	
	// map validation checks + reading map
	if (!map_init_checks(&game, argc, argv[1]))
		return (0);
	
	// initialize the connection
	game.mlx_ptr = mlx_init();

	// create new window on the screen
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.columns * IMG_SIZE, game.rows * IMG_SIZE, "so_long");
	bg_image.img_ptr = mlx_new_image(game.mlx_ptr, game.columns * IMG_SIZE, game.rows * IMG_SIZE);

	
    bg_image.addr = mlx_get_data_addr(game.background_img, &bg_image.bpp, &bg_image.line_len, &bg_image.endian);
	printf("pixel address: %p\n", bg_image.addr);
    printf("pixel bits: %d\n", bg_image.bpp);
    printf("endian: %d\n", bg_image.endian);
    printf("line bytes: %d\n", bg_image.line_len);
    
    color = 0x8FCE00;
    if (bg_image.bpp != 32)
        color = mlx_get_color_value(game.mlx_ptr, color);
    y = 0;
    while (y < game.rows * IMG_SIZE)
    {   
        x = 0;    
        while (x < game.columns * IMG_SIZE)
        {
            int pixel = (y * bg_image.line_len) + (x * 4);
            // printf("pixel: %d\n", pixel);
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
    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, bg_image.img_ptr, 0, 0);
	
	//printf("game width (columns): %d, game heigth (rows): %d\n", game.columns, game.rows);

	// initialize the image -- return void pointer as the image initializer
	// Creates one that contains the .xpm image found in relative_path
	// and saves its width and height in pixels to the given pointers.
	init_game_images(&game);
	
	// put image to window according to the char in 2D 'map' array 
	adding_in_graphics(&game);

	/* ---------------- hooks setup -------------------------*/

	mlx_key_hook(game.win_ptr, *key_controls, &game);
	//mlx_loop_hook(game.mlx_ptr, *ft_update, &program);
	printf("the start position: (%d, %d)\n", game.start_y, game.start_x);
	printf("the exit position: (%d, %d)\n", game.exit_y, game.exit_x);

	// keep the window opem
	mlx_loop(game.mlx_ptr);

	return (0);
}