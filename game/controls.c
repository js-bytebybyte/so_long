/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/29 12:24:27 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	move(t_map *game, int dy, int dx) 
{
    char    target_tile;
    
    target_tile = game->map[game->start_p.y + dy][game->start_p.x + dx];
    if (target_tile == '0' || target_tile == 'C')//|| target_tile == 'E') 
	{
        if (target_tile == 'C') 
            game->collectibles--;
        game->map[game->start_p.y][game->start_p.x] = '0';
        game->start_p.x += dx;
        game->start_p.y += dy;
        game->map[game->start_p.y][game->start_p.x] = 'P';
    } 
	if (target_tile == 'E' && game->collectibles == 0)
		terminate_game(game);
    return (1);
}

int  key_controls(int keycode, t_map *game)
{
	if (keycode == ESC_KEY)
		terminate_game(game);
	if (keycode == UP_KEY || keycode == 126)
        game->moves += move(game, -1, 0);
	if (keycode == DOWN_KEY || keycode == 125)
        game->moves +=move(game, 1, 0);
 	if (keycode == LEFT_KEY || keycode == 123)
        game->moves += move(game, 0, -1);
    if (keycode == RIGHT_KEY || keycode == 124)
        game->moves += move(game, 0, 1);
    init_background(game);
    adding_in_graphics(game);
	printf("moves -> %d\n", game->moves);
    printf("the number of tokens left to collect: %d\n", game->collectibles);
	return (0);
}