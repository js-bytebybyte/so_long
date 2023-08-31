/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/31 15:38:33 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// displays the images in the correct position according to map
void	display_graphics(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->wall_img, x * IMG_SIZE, y * IMG_SIZE);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->collectible_img, x * IMG_SIZE, y * IMG_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->exit_img, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, 
		game->player_p.x * IMG_SIZE, game->player_p.y * IMG_SIZE);
}

void	init_game_images(t_map *game)
{
	int		x;
	int		y;

	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"game_images/cactus.xpm", &x, &y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"game_images/castle_32px.xpm", &x, &y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/mushroom.xpm", &x, &y);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"game_images/player.xpm", &x, &y);
}

static void	set_background_color(t_img *bg_img, t_map *game)
{
	int		pixel;
	int		y;
	int		x;

	bg_img->color = 0x347434;
	y = 0;
	while (y < game->rows * IMG_SIZE)
	{
		x = 0; 
		while (x < game->columns * IMG_SIZE)
		{
			pixel = (y * bg_img->line_len) + (x * 4);
			bg_img->address[pixel + 0] = (bg_img->color) & 0xFF;
			bg_img->address[pixel + 1] = (bg_img->color >> 8) & 0xFF;
			bg_img->address[pixel + 2] = (bg_img->color >> 16) & 0xFF;
			bg_img->address[pixel + 3] = (bg_img->color >> 24);
			x++;
		}
		y++;
	}
}

void	init_background(t_map *game)
{
	t_img	bg_img;

	bg_img.img_ptr = mlx_new_image(game->mlx_ptr, 
			game->columns * IMG_SIZE, game->rows * IMG_SIZE);
	if (bg_img.img_ptr == NULL)
		exit(EXIT_FAILURE);
	bg_img.address = mlx_get_data_addr(bg_img.img_ptr, 
			&bg_img.bpp, &bg_img.line_len, &bg_img.endian);
	set_background_color(&bg_img, game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		bg_img.img_ptr, 0, 0);
}

int	init_graphics(t_map *game)
{
	t_img	image;

	ft_memset(&image, 0, sizeof(t_img));
	init_background(game);
	init_game_images(game);
	display_graphics(game);
	return (0);
}
