/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:41:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/31 11:07:05 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		return (error("Please provide just one map.ber file.\n"));
	ft_memset(&game, 0, sizeof(t_map));
	if (!map_init_checks(&game, argc, argv[1]))
	{
		ft_free_array(game.map);
		ft_free_array(game.flood_grid);
		return (0);
	}
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.columns * IMG_SIZE, 
			game.rows * IMG_SIZE, "so_long");
	init_graphics(&game);
	mlx_key_hook(game.win_ptr, *key_controls, &game);
	mlx_loop_hook(game.mlx_ptr, *update, (void *)&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
