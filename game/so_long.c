/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:41:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/28 16:27:55 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int main(int argc, char **argv)
{
	t_map	game;
	t_img	image;

	// initializes the variables of the structures
	ft_memset(&game, 0, sizeof(t_map));
	ft_memset(&image, 0, sizeof(t_img));
	
	// map validation checks + reading map
	if (!map_init_checks(&game, argc, argv[1]))
	{
		terminate_game(&game);
		return (0);
	}
	
	// initialize the connection
	game.mlx_ptr = mlx_init();
	
	// create new window on the screen
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.columns * IMG_SIZE, game.rows * IMG_SIZE, "so_long");

	// initializes the background and other images for the game
	init_graphics(&game);
	
	// hooks set-up
	mlx_key_hook(game.win_ptr, *key_controls, &game);
	mlx_loop_hook(game.mlx_ptr, *update, (void *)&game);
	mlx_loop(game.mlx_ptr);

	return (0);
}