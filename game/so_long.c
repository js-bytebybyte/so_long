/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:41:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/15 15:34:33 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"



int main(int argc, char **argv)
{
	t_map		game;
	int			check;
	
	// check if the file as argument is valid
	check = valid_file(argc, argv[1]);
	printf("Args and file extension check: %d\n", check);
	
	// read the map file + copy all the chars of the file in 2D array map
	map_reading(&game, argv[1]);

	// error checking of the 2D array 'map'
	// Is the map surrounded by walls (char == '1')?
	check = ft_wall_check(&game);
	printf("Wall check:\t%d\n", check);

	// check if the chars in map are valid
	check = ft_char_check(&game);
	printf("5 chars check:\t%d\n", check);

	// retrieve the position of the player and the exit
	set_start_and_exit(&game);
	
	// initialize the connection
	game.mlx_ptr = mlx_init();

	// create new window on the screen
	// wich measurements are best for the widow size?
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.columns * 40, game.rows * 40, "so_long");

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