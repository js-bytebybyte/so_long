/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/01 09:49:45 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	move(t_map *game, int dy, int dx)
{
	char	target_tile;

	target_tile = game->map[game->player_p.y + dy][game->player_p.x + dx];
	if (target_tile == '0' || target_tile == 'C' || target_tile == 'P')
	{
		if (target_tile == 'C')
			game->collectibles--;
		game->player_p.x += dx;
		game->player_p.y += dy;
		game->map[game->player_p.y][game->player_p.x] = '0';
	}
	if (target_tile == 'E') 
	{
		game->player_p.x += dx;
		game->player_p.y += dy;
		if (game->collectibles == 0)
			terminate_game(game);
	}
	if (target_tile == '1')
		return (0);
	return (1);
}

int	key_controls(int keycode, t_map *game)
{
	int	moved;

	moved = game->moves;
	if (keycode == ESC_KEY)
		terminate_game(game);
	if (keycode == UP_KEY || keycode == 126)
		game->moves += move(game, -1, 0);
	if (keycode == DOWN_KEY || keycode == 125)
		game->moves += move(game, 1, 0);
	if (keycode == LEFT_KEY || keycode == 123)
		game->moves += move(game, 0, -1);
	if (keycode == RIGHT_KEY || keycode == 124)
		game->moves += move(game, 0, 1);
	init_background(game);
	display_graphics(game);
	if (game->moves != moved)
		ft_printf("moves: %d\n", game->moves);
	return (0);
}
