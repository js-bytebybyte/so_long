/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/17 14:04:34 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	move_up(char **map, int y, int x, int token)
{
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C') // the tile above is just the floor
	{
		if (map[y - 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		y -= 1;				   // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y - 1][x] == 'E')
		return (0);
	return (y);
}

static int move_down(char **map, int y, int x, int token)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C') // the tile above is just the floor
	{
		if (map[y + 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		printf("y before: %d\n", y);	
		y += 1;
		printf("y is now: %d\n", y);		 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y + 1][x] == 'E')
		return (0);
	return (y);
}

static int move_left(char **map, int y, int x, int token)
{
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		if (map[y][x - 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		x -= 1;			 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y][x - 1] == 'E')
		return (0);
	return (x);
}

static int move_right(char **map, int y, int x, int token)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		if (map[y][x + 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		x += 1;			 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y][x + 1] == 'E')
		return (0);
	return (x);
}

int  key_controls(int keycode, t_map *game)
{
    game->token = 0;
    printf("the start position: in keycontrol function (%d, %d)\n", game->start_y, game->start_x);
	if (keycode == ESC_KEY)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	else if (keycode == UP_KEY)
        game->start_y = move_up(game->map, game->start_y, game->start_x, game->token);
	else if (keycode == DOWN_KEY)
        game->start_y = move_down(game->map, game->start_y, game->start_x, game->token);
    else if (keycode == LEFT_KEY)
        game->start_x = move_left(game->map, game->start_y, game->start_x, game->token);
    else if (keycode == RIGHT_KEY)
        game->start_x = move_right(game->map, game->start_y, game->start_x, game->token);
    else
		printf("other key was pressed: %d\n", keycode);
    printf("the player's new position (%d, %d)\n", game->start_y, game->start_x);
    if (game->start_x == 0 || game->start_y == 0)
        terminate_game();
    adding_in_graphics(game);
    //printf("the number of tokens gathered: %d\n", game->token);
	return (0);
}