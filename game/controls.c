/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/21 22:46:50 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	move(t_map *game, int dy, int dx) 
{
    char    target_tile;

    // the target_tile char is the direction in which the player will move
    // depends on the key that has been pressed
    target_tile = game->map[game->start_y + dy][game->start_x + dx];
    if (target_tile == '0' || target_tile == 'C') 
	{
        // if the target tile is a collectible, lower counter
        if (target_tile == 'C') 
            game->collectibles--;
            
        // change current position value to 'floor' (= 0) for graphics
        game->map[game->start_y][game->start_x] = '0';
        
        // change the start_x && start_y according to direction  
        game->start_x += dx;
        game->start_y += dy;
        
        // change the new position value to player for the graphics
        game->map[game->start_y][game->start_x] = 'P';
    } 
	if (target_tile == 'E' && game->collectibles == 0)
		terminate_game(game);
    return (1);
}

int  key_controls(int keycode, t_map *game)
{
	// int	moved;
	
	// moved = 0;
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
	// game->moves++;
    adding_in_graphics(game);
	printf("moves: %d\n", game->moves);
    printf("the number of tokens left to collect: %d\n", game->collectibles);
	return (0);
}