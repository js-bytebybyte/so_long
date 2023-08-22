/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/22 13:11:21 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	move(t_map *game, int dy, int dx) 
{
    char    target_tile;

    // the target_tile char is the direction in which the player will move
    // depends on the key that has been pressed
    target_tile = game->map[game->start_y + dy][game->start_x + dx];
    printf("current position value: %c\n", game->map[game->start_y][game->start_x]);
    printf("target tile: %c\n", target_tile);
    if (target_tile == '0' || target_tile == 'C') 
	{
        // if the target tile is a collectible, lower counter
        if (target_tile == 'C') 
            game->collectibles--;
            
        // change current position value to 'floor' (= 0) for graphics
        game->map[game->start_y][game->start_x] = '0';
        printf("adjusted position value: %c\n", game->map[game->start_y][game->start_x]);
        
        // change the start_x && start_y according to direction  
        game->start_x += dx;
        game->start_y += dy;
        
        // change the new position value to player for the graphics
        game->map[game->start_y][game->start_x] = 'P';
        printf("new position value: %c\n", game->map[game->start_y][game->start_x]);
    } 
	if (target_tile == 'E' && game->collectibles == 0)
		terminate_game(game);
    return (1);
}

int  key_controls(int keycode, t_map *game)
{
	if (keycode == ESC_KEY)
		terminate_game(game);
	if (keycode == UP_KEY)
        game->moves += move(game, -1, 0);
	if (keycode == DOWN_KEY)
        game->moves +=move(game, 1, 0);
 	if (keycode == LEFT_KEY)
        game->moves += move(game, 0, -1);
    if (keycode == RIGHT_KEY)
        game->moves += move(game, 0, 1);
    init_background(game);
    adding_in_graphics(game);
	printf("moves: %d\n", game->moves);
    printf("the number of tokens left to collect: %d\n", game->collectibles);
	return (0);
}