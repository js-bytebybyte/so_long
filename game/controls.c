/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/18 17:13:00 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	move_up(t_map *game)
{
	int	x;
	int	y;

	x = game->start_x;
	y = game->start_y;
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
	{
		if (game->map[y - 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			game->collectibles--;
		}
		game->map[y][x] = '0'; 
		y -= 1;	
		game->map[y][x] = 'P';
		game->start_y = y;
	}
	else if (game->map[y - 1][x] == 'E')
		return (0);
	return (1);
}

static int move_down(t_map *game)
{
	int	x;
	int	y;

	x = game->start_x;
	y = game->start_y;
	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C') // the tile above is just the floor
	{
		if (game->map[y + 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			game->collectibles--;
		}
		game->map[y][x] = '0';
		y += 1;
		game->map[y][x] = 'P';
		game->start_y = y;
	}
	else if (game->map[y + 1][x] == 'E')
		return (0);
	return (1);
}

static int move_left(t_map *game)
{
	int	x;
	int	y;

	x = game->start_x;
	y = game->start_y;
	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
	{
		if (game->map[y][x - 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			game->collectibles--;
		}
		game->map[y][x] = '0'; 
		x -= 1;			
		game->map[y][x] = 'P'; 
		game->start_x = x;
	}
	else if (game->map[y][x - 1] == 'E')
		return (0);
	return (1);
}

static int move_right(t_map *game)
{
	int	x;
	int	y;

	x = game->start_x;
	y = game->start_y;
	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
	{
		if (game->map[y][x + 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			game->collectibles--;
		}
		game->map[y][x] = '0'; // set the current position as floor
		x += 1;			 // go up along the vertical axis
		game->map[y][x] = 'P';
		game->start_x = x; 
	}
	else if (game->map[y][x + 1] == 'E')
		return (0);
	return (1);
}

int  key_controls(int keycode, t_map *game)
{
	int	moved;
	
	moved = 0;
    printf("the start position: in keycontrol function (%d, %d)\n", game->start_y, game->start_x);
	if (keycode == ESC_KEY)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	else if (keycode == UP_KEY)
        moved = move_up(game);
	else if (keycode == DOWN_KEY)
        moved = move_down(game);
    else if (keycode == LEFT_KEY)
        moved = move_left(game);
    else if (keycode == RIGHT_KEY)
        moved = move_right(game);
    else
		printf("other key was pressed: %d\n", keycode);
    printf("the player's new position (%d, %d)\n", game->start_y, game->start_x);
	game->moves++;
    if (!moved)
        terminate_game();
    adding_in_graphics(game);
	printf("moves: %d\n", game->moves);
    printf("the number of tokens left to collect: %d\n", game->collectibles);
	return (0);
}