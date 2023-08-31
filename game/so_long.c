/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:41:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/31 15:42:46 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		return (error("Please provide just one map.ber file.\n"));
	ft_memset(&game, 0, sizeof(t_map));
	if (!map_init_checks(&game, argv[1]))
	{
		ft_free_array(game.map);
		ft_free_array(game.flood_grid);
		exit(EXIT_FAILURE);
	}
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.columns * IMG_SIZE, 
			game.rows * IMG_SIZE, "so_long");
	if (game.win_ptr == NULL)
		exit(EXIT_FAILURE);
	init_graphics(&game);
	mlx_key_hook(game.win_ptr, *key_controls, &game);
	mlx_loop_hook(game.mlx_ptr, *update, (void *)&game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
	exit(EXIT_SUCCESS);
}
